/**
 * @file Bullet.cpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief 
 * @date 2024-02-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Bullet.hpp"

////////////////////////////////////
// ctors / dtor 
////////////////////////////////////

Bullet::Bullet(
    const sf::Vector2f& pos,
    const sf::Vector2f& origin,
    const float rotation,
    const sf::Vector2f& direction,
    const float weaponWidth) 
    : dir_(direction) {
    InitAttributs(pos, origin, rotation, weaponWidth);
}

Bullet::~Bullet() {
}



////////////////////////////////////
// methods
////////////////////////////////////

void Bullet::InitAttributs(
    const sf::Vector2f& pos,
    const sf::Vector2f& origin,
    const float rotation,
    const float weaponWidth) {

    radius_ = 2.f;
    color_  = sf::Color::White;

    /*
    The bullet origin is based on the weapon's offset from the player's body 
    and and additional offset for it to spawn at the center of the weapon, like 
    a real one. 
    */
    offsetOriginFromWeapon_ = sf::Vector2f(-( weaponWidth - shape_.getRadius() )/2.f, 0.f);

    shape_ = sf::CircleShape(radius_);
    shape_.setFillColor(color_);
    shape_.setOrigin(origin + offsetOriginFromWeapon_);
    shape_.setPosition(pos);
    shape_.setRotation(rotation);
}

void Bullet::Update(const float velocity, const sf::Time& timeSinceLastFrame) {
    Move(velocity, timeSinceLastFrame);
}


void Bullet::Render(sf::RenderWindow* window) {
    window->draw(shape_);
}

void Bullet::Move(const float velocity, const sf::Time& timeSinceLastFrame) {
    shape_.move(velocity * dir_ * timeSinceLastFrame.asSeconds());
}