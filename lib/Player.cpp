/**
 * @file Player.cpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief 
 * @date 2024-01-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Player.hpp"


////////////////////////////////////
// ctors / dtor 
////////////////////////////////////

Player::Player(sf::RenderWindow* window, sf::Vector2f pos) 
    : pos_(pos) {

    InitAttributs();
}

Player::~Player() {
}




////////////////////////////////////
// methods 
////////////////////////////////////

void Player::InitAttributs() {

    width_ = 60.f;
    height_ = 40.f;
    acc_ = 0.1f;
    rotationForce_ = 0.05f;

    // set player at the center of the window at launch
    shape_ = sf::RectangleShape(sf::Vector2f(width_, height_));
    shape_.setOrigin(width_/2.f, height_/2.f);
    shape_.setPosition(pos_);
    shape_.setFillColor(sf::Color::Green);
}


void Player::Update(sf::RenderWindow* window) {
    Move();
    Rotate();
}


void Player::Render(sf::RenderWindow* window) {
    window->draw(shape_);
}

void Player::Move() {

    // move right 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        shape_.move(acc_, 0.f);
    }

    // move left 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        shape_.move(-acc_, 0.f);
    }

    // move down 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        shape_.move(0.f, acc_);
    }

    // move up 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        shape_.move(0.f, -acc_);
    }  
}

void Player::Rotate() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        shape_.rotate(-rotationForce_);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        shape_.rotate(rotationForce_);
    }
}