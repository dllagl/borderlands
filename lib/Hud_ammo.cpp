/**
 * @file Hud_ammo.cpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief 
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Hud_ammo.hpp"



////////////////////////////////////
// ctors / dtor 
////////////////////////////////////

Hud_ammo::Hud_ammo(
    const uint16_t ammoLeftInClip,
    const uint16_t totalAmmoLeft,
    const sf::Vector2f& windowSize) 
    : displayedAmmoInClip_(ammoLeftInClip), displayedTotalAmmo_(totalAmmoLeft) {
        
    InitAttributs(windowSize);
}


////////////////////////////////////
// methods
////////////////////////////////////

void Hud_ammo::InitAttributs(const sf::Vector2f& windowSize) {

    // font
    font_ = std::make_unique<sf::Font>();
    font_->loadFromFile("../lib/fonts/ammo-pixel.ttf");

    // text
    text_ = std::make_unique<sf::Text>();
    text_->setFont(*font_);
    text_->setCharacterSize(50);
    text_->setPosition(0.89f*windowSize.x, 0.9f*windowSize.y);
    text_->setFillColor(sf::Color::Red);

    /*
    displayedAmmoInClip_ and displayedTotalAmmo_ are forced to a two- and 
    three-digit format so that the text does not move on the screen
    e.g. when the ammo count drops below ten. 
    */
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << displayedAmmoInClip_ << "/" 
        << std::setw(3) << std::setfill('0') << displayedTotalAmmo_;
    text_->setString(oss.str());

}



void Hud_ammo::Update(const uint16_t ammoLeftInClip, const uint16_t totalAmmoLeft) {

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
        text_->setString(oss.str());

        displayedAmmoInClip_ = ammoLeftInClip;
        displayedTotalAmmo_ = totalAmmoLeft;
    }
}



void Hud_ammo::Render(const std::unique_ptr<sf::RenderWindow>& window) const {
    window->draw(*text_);   
}