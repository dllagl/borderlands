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
    const uint16_t playerShield) {
    
    
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
        healthText_->setString(std::to_string(playerHealth));
        displayedHealth_ = playerHealth;
    }
        

    // does not update shield display if it has not changed since last frame
    if (playerShield != displayedShield_) {
        shieldText_->setString(std::to_string(playerShield));
        displayedShield_ = playerShield;
    }  
}



void Hud::Render(const std::unique_ptr<sf::RenderWindow>& window) {
    window->draw(*ammoText_);
    window->draw(*healthText_);
    window->draw(*shieldText_);
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

    healthFont_ = std::make_unique<sf::Font>();
    healthFont_->loadFromFile("../lib/fonts/ammo-pixel.ttf");

    healthText_ = std::make_unique<sf::Text>();
    healthText_->setFont(*healthFont_);
    healthText_->setCharacterSize(50);
    healthText_->setPosition(0.05f*windowSize.x, 0.87f*windowSize.y);
    healthText_->setFillColor(sf::Color::Red);
    healthText_->setString(std::to_string(displayedHealth_));
}



void Hud::InitShieldDisplay(const sf::Vector2f& windowSize) {

    shieldFont_ = std::make_unique<sf::Font>();
    shieldFont_->loadFromFile("../lib/fonts/ammo-pixel.ttf");

    shieldText_ = std::make_unique<sf::Text>();
    shieldText_->setFont(*shieldFont_);
    shieldText_->setCharacterSize(50);
    shieldText_->setPosition(0.05f*windowSize.x, 0.93f*windowSize.y);
    shieldText_->setFillColor(sf::Color::Blue);
    shieldText_->setString(std::to_string(displayedShield_));
}