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

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f direction) 
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
    velocity_ = 0.1;

    shape_ = sf::CircleShape(radius_);
    shape_.setFillColor(color_);
    shape_.setPosition(initialPos_);
}

void Bullet::Update() {
    Move();
}


void Bullet::Render(sf::RenderWindow* window) {
    window->draw(shape_);
}

void Bullet::Move() {
    shape_.move(velocity_ * dir_);
}