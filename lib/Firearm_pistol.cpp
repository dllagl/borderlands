/**
 * @file Firearm_pistol.cpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief 
 * @date 2024-03-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "items/firearms/Firearm_pistol.hpp"

////////////////////////////////////
// ctors / dtor 
////////////////////////////////////

Firearm_pistol::Firearm_pistol(const sf::Vector2f& pos) {
    InitAttributs(pos);
}

////////////////////////////////////
// methods
////////////////////////////////////

void Firearm_pistol::InitAttributs(const sf::Vector2f& pos) {

    // body 
    shape_ = std::make_unique<sf::RectangleShape>();
    width_ = 15.f;
    height_ = 25.f;
    shape_->setSize(sf::Vector2f(width_, height_));
    name_ = "Example pistol name";

    /**
     * The origin of the weapon is set to the geometrical center 
     * of the player in order to rotate around its axis.
     */
    offsetOriginFromPlayerCenter_ = sf::Vector2f(-8.f, 30.f);
    shape_->setOrigin(offsetOriginFromPlayerCenter_);
    shape_->setPosition(pos);
    shape_->setFillColor(sf::Color::Blue);


    // ammunitions 
    maxAmmo_ = 100;
    magazineSize_ = 10;
    currentAmmoInClip_ = magazineSize_;
    currentAmmoLeft_ = maxAmmo_ - currentAmmoInClip_;

    // bullets
    fireRate_ = 10.f;
    fireRange_ = 400.f;
    bulletVelocity_ = 1000.f;
}