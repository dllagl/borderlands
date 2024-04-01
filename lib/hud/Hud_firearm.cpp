/**
 * @file Hud_firearm.cpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief 
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "hud/Hud_firearm.hpp"



////////////////////////////////////
// ctors / dtor 
////////////////////////////////////

Hud_firearm::Hud_firearm(
    const uint16_t ammoLeftInClip,
    const uint16_t totalAmmoLeft,
    const std::string& equipedWeaponName,
    const sf::Vector2f& windowSize) 
    : displayedAmmoInClip_(ammoLeftInClip), displayedTotalAmmo_(totalAmmoLeft), weaponName_(equipedWeaponName){
        
    InitAttributs(windowSize);
}


////////////////////////////////////
// methods
////////////////////////////////////

void Hud_firearm::InitAttributs(const sf::Vector2f& windowSize) {

    // font
    font_ = std::make_unique<sf::Font>();
    font_->loadFromFile("../refs/fonts/ammo-pixel.ttf");

    // text for ammunitions 
    textAmmo_ = std::make_unique<sf::Text>();
    textAmmo_->setFont(*font_);
    textAmmo_->setCharacterSize(50);
    textAmmo_->setPosition(0.89f*windowSize.x, 0.86f*windowSize.y);
    textAmmo_->setFillColor(sf::Color::Red);
    /*
    displayedAmmoInClip_ and displayedTotalAmmo_ are forced to a two- and 
    three-digit format so that the text does not move on the screen
    e.g. when the ammo count drops below ten. 
    */
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << displayedAmmoInClip_ << "/" 
        << std::setw(3) << std::setfill('0') << displayedTotalAmmo_;
    textAmmo_->setString(oss.str());


    // text for weapon's name
    textName_ = std::make_unique<sf::Text>();
    textName_->setFont(*font_);
    textName_->setCharacterSize(50);
    textName_->setFillColor(sf::Color::Red);
    textName_->setString(weaponName_); 
    /*
    Set the origin of the text to its right ending side so that the end
    of the string is aligned with the ammunition text above, no matter what 
    the name of the weapon is or how long its string is. 
    */
    const sf::FloatRect textBounds = textName_->getLocalBounds();
    textName_->setOrigin(textBounds.left + textBounds.width, 0.f);
    textName_->setPosition(
        textAmmo_->getGlobalBounds().left + textAmmo_->getGlobalBounds().width,
        0.9f*windowSize.y
    );


}



void Hud_firearm::Update(const uint16_t ammoLeftInClip, const uint16_t totalAmmoLeft, const std::string& equipedWeaponName) {

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
        textAmmo_->setString(oss.str());

        displayedAmmoInClip_ = ammoLeftInClip;
        displayedTotalAmmo_ = totalAmmoLeft;
    }

    // does not update weapon name unless player has switched weapons
    if (equipedWeaponName != weaponName_) {

        // update name 
        textName_->setString(equipedWeaponName);
        weaponName_ = equipedWeaponName;

        /*
        Because weapon names can differ in length, it is 
        necessary to reset their origin each time the string changes
        */
        const sf::FloatRect textBounds = textName_->getLocalBounds();
        textName_->setOrigin(textBounds.left + textBounds.width, 0.f);
    }
}



void Hud_firearm::Render(const std::unique_ptr<sf::RenderWindow>& window) const {
    window->draw(*textAmmo_);   
    window->draw(*textName_);
}