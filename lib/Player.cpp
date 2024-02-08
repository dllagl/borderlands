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
// static members 
////////////////////////////////////

// main player properties
const float Player::width_  = 60.f;
const float Player::height_ = 40.f;

// weapon properties
const sf::Vector2f Player::weaponOriginFromPlayerCenter_ = sf::Vector2f(8.f, -30.f);



////////////////////////////////////
// ctors / dtor 
////////////////////////////////////

Player::Player(const sf::Vector2f& pos) {

    InitAttributs(pos);
}

Player::~Player() {

    for (Bullet* b : bullets_) { delete b; }
    delete smg_;
    delete shape_;
}




////////////////////////////////////
// methods 
////////////////////////////////////

void Player::InitAttributs(const sf::Vector2f& pos) {

    // player initial properties
    acc_ = 0.1f;
    rotationForce_ = 0.05f;

    // set player at the center of the window at launch
    shape_ = new sf::RectangleShape();
    shape_->setSize(sf::Vector2f(width_,height_));
    shape_->setOrigin(shape_->getSize() / 2.f);
    shape_->setPosition(pos);
    shape_->setFillColor(sf::Color::Green);

    // init weapon
    smg_ = new Weapon(shape_->getPosition(), weaponOriginFromPlayerCenter_);
}


void Player::Update(sf::RenderWindow* window) {
    Move();
    Rotate(window);
    Shoot(window);
    smg_->Update(shape_->getPosition(), shape_->getRotation());

    if (bullets_.size() != 0)
        for (Bullet* b : bullets_) { b->Update(); }
}


void Player::Render(sf::RenderWindow* window) {
    window->draw(*shape_);
    smg_->Render(window);

    if (bullets_.size() != 0)
        for (Bullet* b : bullets_) { b->Render(window); }
}

void Player::Move() {

    // move right 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        shape_->move(acc_, 0.f);
    }

    // move left 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        shape_->move(-acc_, 0.f);
    }

    // move down 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        shape_->move(0.f, acc_);
    }

    // move up 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        shape_->move(0.f, -acc_);
    }  
}

void Player::Rotate(sf::RenderWindow* window) {

    sf::Vector2f mousePos = window->mapPixelToCoords(sf::Mouse::getPosition());
    float angle = atan2(mousePos.y - shape_->getPosition().y, mousePos.x - shape_->getPosition().x) * 57.296f;
    shape_->setRotation(angle + 82.f);
}

void Player::Shoot(sf::RenderWindow* window) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

        // mouse position relative to the window
        sf::Vector2i mousePosWindow  = sf::Vector2i(sf::Mouse::getPosition(*window));

        // conversion to sf::view coordonates
        sf::Vector2f mousePosView = window->mapPixelToCoords(mousePosWindow);

        // aiming direction
        sf::Vector2f aimDir = mousePosView - shape_->getPosition();
        const sf::Vector2f aimDirNorm = aimDir / static_cast<float>(sqrt(pow(aimDir.x,2) + pow(aimDir.y,2)));

        // spawn new bullet
        bullets_.push_back(new Bullet(shape_->getPosition(), aimDirNorm));
            
    }
}