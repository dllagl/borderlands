/**
 * @file Hud.cpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief 
 * @date 2024-02-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Hud.hpp"


////////////////////////////////////
// ctors / dtor 
////////////////////////////////////

Hud::Hud(
    const uint16_t playerHealth,
    const uint16_t playerShield,
    const uint16_t ammoLeftInClip,
    const uint16_t totalAmmoLeft,
    const sf::Vector2f& windowSize
    ) 
    : displayedHealth_(playerHealth),
      displayedShield_(playerShield),
      displayedAmmoInClip_(ammoLeftInClip),
      displayedTotalAmmo_(totalAmmoLeft) {

    InitAttributs(windowSize);
}



////////////////////////////////////
// methods
////////////////////////////////////

void Hud::InitAttributs(const sf::Vector2f& windowSize) {

    InitAmmoDisplay(windowSize);
    InitHealthDisplay(windowSize);
    InitShieldDisplay(windowSize);

}



void Hud::Update(
    const uint16_t ammoLeftInClip,
    const uint16_t totalAmmoLeft,
    const uint16_t playerHealth,
    const uint16_t playerMaxHealth,
    const uint16_t playerShield,
    const uint16_t playerMaxShield) {
    
    
    // does not update ammo display if it has not changed since last frame
    if ((ammoLeftInClip != displayedAmmoInClip_) || (totalAmmoLeft != displayedTotalAmmo_)) {

        /*
        ammoLeftInClip and totalAmmoLeft are forced to a two- and 
        three-digit format so that the text does not move on the screen
        e.g. when the ammo count drops below ten. 
        */
        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << ammoLeftInClip << "/" 
            << std::setw(3) << std::setfill('0') << totalAmmoLeft;
        ammoText_->setString(oss.str());

        displayedAmmoInClip_ = ammoLeftInClip;
        displayedTotalAmmo_ = totalAmmoLeft;
    }
        

    // does not update health display if it has not changed since last frame
    if (playerHealth != displayedHealth_) {

        // update text 
        healthText_->setString(std::to_string(playerHealth));
        displayedHealth_ = playerHealth;

        // update rectangle
        float newSizeOfRect = ((float)playerHealth / playerMaxHealth) * healthBgRectangle_.getSize().x;
        healthRectangle_->setSize(sf::Vector2f(newSizeOfRect, healthRectangle_->getSize().y));
    }
        

    // does not update shield display if it has not changed since last frame
    if (playerShield != displayedShield_) {

        // update text
        shieldText_->setString(std::to_string(playerShield));
        displayedShield_ = playerShield;

        // update rectangle
        float newSizeOfRect = ((float)playerShield / playerMaxShield) * shieldBgRectangle_.getSize().x;
        shieldRectangle_->setSize(sf::Vector2f(newSizeOfRect, shieldRectangle_->getSize().y));
    }  
}



void Hud::Render(const std::unique_ptr<sf::RenderWindow>& window) {

    // ammunition
    window->draw(*ammoText_);

    // health
    window->draw(*healthText_);
    window->draw(*healthRectangle_);
    window->draw(healthBgRectangle_);

    // shield
    window->draw(*shieldText_);
    window->draw(*shieldRectangle_);
    window->draw(shieldBgRectangle_);
}



void Hud::InitAmmoDisplay(const sf::Vector2f& windowSize) {

    ammoFont_ = std::make_unique<sf::Font>();
    ammoFont_->loadFromFile("../lib/fonts/ammo-pixel.ttf");

    ammoText_ = std::make_unique<sf::Text>();
    ammoText_->setFont(*ammoFont_);
    ammoText_->setCharacterSize(50);
    ammoText_->setPosition(0.85f*windowSize.x, 0.9f*windowSize.y);
    ammoText_->setFillColor(sf::Color::Red);

    /*
    displayedAmmoInClip_ and displayedTotalAmmo_ are forced to a two- and 
    three-digit format so that the text does not move on the screen
    e.g. when the ammo count drops below ten. 
    */
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << displayedAmmoInClip_ << "/" 
        << std::setw(3) << std::setfill('0') << displayedTotalAmmo_;
    ammoText_->setString(oss.str());

}



void Hud::InitHealthDisplay(const sf::Vector2f& windowSize) {

    // background health rectangle (fixed size, only the outline is colored)
    healthBgRectangle_ = sf::RectangleShape(sf::Vector2f(150.f,20.f));
    healthBgRectangle_.setPosition(0.05f * windowSize.x, 0.9f * windowSize.y);
    healthBgRectangle_.setFillColor(sf::Color::Transparent);
    healthBgRectangle_.setOutlineColor(sf::Color::White);
    healthBgRectangle_.setOutlineThickness(2.0f);

    // actual health rectangle (its size evolves with player's health)
    healthRectangle_ = std::make_unique<sf::RectangleShape>(healthBgRectangle_.getSize());
    healthRectangle_->setPosition(healthBgRectangle_.getPosition());
    healthRectangle_->setFillColor(sf::Color::Red);

    // font
    healthFont_ = std::make_unique<sf::Font>();
    healthFont_->loadFromFile("../lib/fonts/ammo-pixel.ttf");

    // text (positioned relatively to the background health rectangle)
    healthText_ = std::make_unique<sf::Text>();
    healthText_->setFont(*healthFont_);
    healthText_->setCharacterSize(50);
    healthText_->setPosition(
        healthBgRectangle_.getPosition().x + healthBgRectangle_.getSize().x + 20.f,
        healthBgRectangle_.getPosition().y - (healthBgRectangle_.getSize().y + 5.f)
    );
    healthText_->setFillColor(sf::Color::Red);
    healthText_->setString(std::to_string(displayedHealth_));
}



void Hud::InitShieldDisplay(const sf::Vector2f& windowSize) {

    // background shield rectangle (fixed size, only the outline is colored)
    shieldBgRectangle_ = sf::RectangleShape(sf::Vector2f(150.f,20.f));
    shieldBgRectangle_.setPosition(0.05f * windowSize.x, 0.94f * windowSize.y);
    shieldBgRectangle_.setFillColor(sf::Color::Transparent);
    shieldBgRectangle_.setOutlineColor(sf::Color::White);
    shieldBgRectangle_.setOutlineThickness(2.0f);

    // actual health rectangle (its size evolves with player's health)
    shieldRectangle_ = std::make_unique<sf::RectangleShape>(shieldBgRectangle_.getSize());
    shieldRectangle_->setPosition(shieldBgRectangle_.getPosition());
    shieldRectangle_->setFillColor(sf::Color::Blue);

    // font 
    shieldFont_ = std::make_unique<sf::Font>();
    shieldFont_->loadFromFile("../lib/fonts/ammo-pixel.ttf");

    // text (positioned relatively to the background shield rectangle)
    shieldText_ = std::make_unique<sf::Text>();
    shieldText_->setFont(*shieldFont_);
    shieldText_->setCharacterSize(50);
    shieldText_->setPosition(
        shieldBgRectangle_.getPosition().x + shieldBgRectangle_.getSize().x + 20.f,
        shieldBgRectangle_.getPosition().y - (shieldBgRectangle_.getSize().y + 5.f)
    );
    shieldText_->setFillColor(sf::Color::Blue);
    shieldText_->setString(std::to_string(displayedShield_));
}