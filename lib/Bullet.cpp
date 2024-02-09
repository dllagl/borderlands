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

Bullet::Bullet(const sf::Vector2f& pos, const sf::Vector2f& direction) 
: initialPos_(pos), dir_(direction) {
    InitAttributs();
}

Bullet::~Bullet() {
}



////////////////////////////////////
// methods
////////////////////////////////////

void Bullet::InitAttributs() {

    radius_ = 2.f;
    color_  = sf::Color::White;

    shape_ = sf::CircleShape(radius_);
    shape_.setFillColor(color_);
    shape_.setPosition(initialPos_);
}

void Bullet::Update(const float velocity) {
    Move(velocity);
}


void Bullet::Render(sf::RenderWindow* window) {
    window->draw(shape_);
}

void Bullet::Move(const float velocity) {
    shape_.move(velocity * dir_);
}