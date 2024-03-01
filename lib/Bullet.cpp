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
    const sf::Vector2f& weaponOffsetFromPlayer,
    const float rotation,
    const sf::Vector2f& direction,
    const float weaponWidth) 
    : dir_(direction), initialPosition_(pos) {
    InitAttributs(weaponOffsetFromPlayer, rotation, weaponWidth);
}

Bullet::~Bullet() {
}



////////////////////////////////////
// methods
////////////////////////////////////

void Bullet::InitAttributs(
    const sf::Vector2f& weaponOffsetFromPlayer,
    const float rotation,
    const float weaponWidth) {

    radius_ = 2.f;
    color_  = sf::Color::White;
    hasReachedMaxDistance_ = false;

    shape_ = std::make_unique<sf::CircleShape>(radius_);
    /*
    The bullet origin is based on the weapon's offset from the player's body 
    and and additional offset for it to spawn at the center of the weapon, like 
    a real one. 
    */
    offsetOriginFromWeapon_ = sf::Vector2f(-( weaponWidth - shape_->getRadius() )/2.f, 0.f);
    shape_->setFillColor(color_);
    shape_->setOrigin(weaponOffsetFromPlayer + offsetOriginFromWeapon_);
    shape_->setPosition(initialPosition_);
    shape_->setRotation(rotation);
}

void Bullet::Update(const float velocity, const sf::Time& timeSinceLastFrame, const float maxDistance) {
    Move(velocity, timeSinceLastFrame, maxDistance);
}


void Bullet::Render(const std::unique_ptr<sf::RenderWindow>& window) const {
    window->draw(*shape_);
}

void Bullet::Move(const float velocity, const sf::Time& timeSinceLastFrame, const float maxDistance) {

    sf::Vector2f currentPosition = shape_->getPosition() - initialPosition_;
    float currentPositionNorm = static_cast<float>(sqrt(pow(currentPosition.x,2) + pow(currentPosition.y,2)));
    
    if (currentPositionNorm <= maxDistance) {
        shape_->move(velocity * dir_ * timeSinceLastFrame.asSeconds());
    } else {
        hasReachedMaxDistance_ = true;
    }
            
}