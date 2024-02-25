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
    const uint16_t ammoLeftInClip,
    const uint16_t totalAmmoLeft,
    const uint16_t playerHealth,
    const uint16_t playerShield,
    const sf::Vector2f windowSize) {
    InitAttributs(ammoLeftInClip, totalAmmoLeft, playerHealth, playerShield, windowSize);
}



////////////////////////////////////
// methods
////////////////////////////////////

void Hud::InitAttributs(
    const uint16_t ammoLeftInClip,
    const uint16_t totalAmmoLeft,
    const uint16_t playerHealth,
    const uint16_t playerShield,
    const sf::Vector2f windowSize) {

    InitAmmoDisplay(ammoLeftInClip, totalAmmoLeft, windowSize);
    InitHealthDisplay(playerHealth, windowSize);
    InitShieldDisplay(playerShield, windowSize);

}



void Hud::Update(
    const uint16_t ammoLeftInClip,
    const uint16_t totalAmmoLeft,
    const uint16_t playerHealth,
    const uint16_t playerShield) {
    
    /*
    ammoLeftInClip and totalAmmoLeft are forced to a two- and 
    three-digit format so that the text does not move on the screen
    e.g. when the ammo count drops below ten. 
    */
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << ammoLeftInClip << "/" 
        << std::setw(3) << std::setfill('0') << totalAmmoLeft;
    ammoText_->setString(oss.str());


    //health 
    healthText_->setString(std::to_string(playerHealth));

    // shield 
    shieldText_->setString(std::to_string(playerShield));
}



void Hud::Render(const std::unique_ptr<sf::RenderWindow>& window) {
    window->draw(*ammoText_);
    window->draw(*healthText_);
    window->draw(*shieldText_);
}



void Hud::InitAmmoDisplay(
    const uint16_t ammoLeftInClip,
    const uint16_t totalAmmoLeft,
    const sf::Vector2f windowSize) {

    ammoFont_ = std::make_unique<sf::Font>();
    ammoFont_->loadFromFile("../lib/fonts/ammo-pixel.ttf");

    ammoText_ = std::make_unique<sf::Text>();
    ammoText_->setFont(*ammoFont_);
    ammoText_->setCharacterSize(50);
    ammoText_->setPosition(0.85f*windowSize.x, 0.9f*windowSize.y);
    ammoText_->setFillColor(sf::Color::Red);

}



void Hud::InitHealthDisplay(const uint16_t playerHealth, const sf::Vector2f windowSize) {

    healthFont_ = std::make_unique<sf::Font>();
    healthFont_->loadFromFile("../lib/fonts/ammo-pixel.ttf");

    healthText_ = std::make_unique<sf::Text>();
    healthText_->setFont(*healthFont_);
    healthText_->setCharacterSize(50);
    healthText_->setPosition(0.05f*windowSize.x, 0.87f*windowSize.y);
    healthText_->setFillColor(sf::Color::Red);
}



void Hud::InitShieldDisplay(const uint16_t playerShield, const sf::Vector2f windowSize) {

    shieldFont_ = std::make_unique<sf::Font>();
    shieldFont_->loadFromFile("../lib/fonts/ammo-pixel.ttf");

    shieldText_ = std::make_unique<sf::Text>();
    shieldText_->setFont(*shieldFont_);
    shieldText_->setCharacterSize(50);
    shieldText_->setPosition(0.05f*windowSize.x, 0.93f*windowSize.y);
    shieldText_->setFillColor(sf::Color::Blue);
}