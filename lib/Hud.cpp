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

Hud::Hud(const uint16_t ammoLeftInClip, const uint16_t totalAmmoLeft, const sf::Vector2f windowSize) {
    InitAttributs(ammoLeftInClip, totalAmmoLeft, windowSize);
}



////////////////////////////////////
// methods
////////////////////////////////////

void Hud::InitAttributs(
    const uint16_t ammoLeftInClip,
    const uint16_t totalAmmoLeft,
    const sf::Vector2f windowSize) {

    InitAmmoDisplay(ammoLeftInClip,totalAmmoLeft,windowSize);

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



void Hud::Update(const uint16_t ammoLeftInClip, const uint16_t totalAmmoLeft) {
    
    /*
    ammoLeftInClip and totalAmmoLeft are forced to a two- and 
    three-digit format so that the text does not move on the screen
    e.g. when the ammo count drops below ten. 
    */
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << ammoLeftInClip << "/" 
        << std::setw(3) << std::setfill('0') << totalAmmoLeft;
    ammoText_->setString(oss.str());
}



void Hud::Render(const std::unique_ptr<sf::RenderWindow>& window) {
    window->draw(*ammoText_);
}