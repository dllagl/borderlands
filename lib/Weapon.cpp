/**
 * @file Weapon.cpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief 
 * @date 2024-02-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Weapon.hpp"

////////////////////////////////////
// static members 
////////////////////////////////////

const float Weapon::width_  = 15.f;
const float Weapon::height_ = 25.f;


////////////////////////////////////
// ctors / dtor 
////////////////////////////////////

Weapon::Weapon(const sf::Vector2f& pos, const sf::Vector2f& origin) {
    InitAttributs(pos, origin);
}

Weapon::~Weapon() {
}



////////////////////////////////////
// methods
////////////////////////////////////

void Weapon::InitAttributs(const sf::Vector2f& pos, const sf::Vector2f& origin) {

    shape_ = sf::RectangleShape();
    shape_.setSize(sf::Vector2f(width_,height_));

    /**
     * The origin of the weapon is set to the geometrical center 
     * of the player in order to rotate around its axis.
     */
    shape_.setOrigin(-origin);
    shape_.setPosition(pos);
    shape_.setFillColor(sf::Color::Red);
}

void Weapon::Update(const sf::Vector2f& pos, const float rotation) {

    // movements and rotations are updated following main player's body's
    shape_.setPosition(pos);
    shape_.setRotation(rotation);
}

void Weapon::Render(sf::RenderWindow* window) {
    window->draw(shape_);
}