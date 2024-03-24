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
    const std::string weaponName,
    const sf::Vector2f& windowSize) {

    InitAttributs(playerHealth, playerShield, ammoLeftInClip, totalAmmoLeft, weaponName, windowSize);
}



////////////////////////////////////
// methods
////////////////////////////////////

void Hud::InitAttributs(
    const uint16_t playerHealth,
    const uint16_t playerShield,
    const uint16_t ammoLeftInClip,
    const uint16_t totalAmmoLeft,
    const std::string weaponName,
    const sf::Vector2f& windowSize) {

    hudFirearm_  = std::make_unique<Hud_firearm>(ammoLeftInClip, totalAmmoLeft, weaponName, windowSize);
    hudHealth_   = std::make_unique<Hud_health>(playerHealth, windowSize);
    hudShield_   = std::make_unique<Hud_shield>(playerShield,windowSize);

}



void Hud::Update(
    const uint16_t ammoLeftInClip,
    const uint16_t totalAmmoLeft,
    const uint16_t playerHealth,
    const uint16_t playerMaxHealth,
    const uint16_t playerShield,
    const uint16_t playerMaxShield) {
        
    hudFirearm_->Update(ammoLeftInClip, totalAmmoLeft);
    hudHealth_->Update(playerHealth, playerMaxHealth);
    hudShield_->Update(playerShield, playerMaxShield);
        
}



void Hud::Render(const std::unique_ptr<sf::RenderWindow>& window) const {

    hudFirearm_->Render(window);
    hudHealth_->Render(window);
    hudShield_->Render(window);

}