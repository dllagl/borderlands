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

// inventory
uint8_t Player::weaponIdx_ = 0; // index of the selected weapon in the inventory



////////////////////////////////////
// ctors / dtor 
////////////////////////////////////

Player::Player(const sf::Vector2f& pos) {

    InitAttributs(pos);
}



////////////////////////////////////
// methods 
////////////////////////////////////

void Player::InitAttributs(const sf::Vector2f& pos) {

    // player initial properties
    acc_ = 500.f;
    rotationForce_ = 0.05f;
    currentHealth_ = maxHealth_ = 100;
    currentShield_ = maxShield_ = 100;

    // set player at the center of the window at launch
    shape_ = std::make_unique<sf::RectangleShape>();
    shape_->setSize(sf::Vector2f(width_,height_));
    shape_->setOrigin(shape_->getSize() / 2.f);
    shape_->setPosition(pos);
    shape_->setFillColor(sf::Color::Green);

    // init weapons inventory (smg and pistol for testing purposes)
    equipedWeapons_.push_back(std::make_unique<Smg>(shape_->getPosition()));
    equipedWeapons_.push_back(std::make_unique<Pistol>(shape_->getPosition()));
}



void Player::Update(const std::unique_ptr<sf::RenderWindow>& window, const sf::Time& timeSinceLastFrame) {
    Move(timeSinceLastFrame);
    Rotate(window);
    changeSelectedWeapon();

    // only update selected weapon
    equipedWeapons_.at(weaponIdx_)->Update(shape_->getPosition(), shape_->getRotation(), lookingDirection_, timeSinceLastFrame);
}



void Player::Render(const std::unique_ptr<sf::RenderWindow>& window) const {
    window->draw(*shape_);

    // only render selected weapon
    equipedWeapons_.at(weaponIdx_)->Render(window); 
}



void Player::Move(const sf::Time& timeSinceLastFrame) {

    // move right 
    if (sf::Keyboard::isKeyPressed(KEY::MOV::RIGHT)) {
        shape_->move(acc_ * timeSinceLastFrame.asSeconds(), 0.f);
    }

    // move left 
    if (sf::Keyboard::isKeyPressed(KEY::MOV::LEFT)) {
        shape_->move(-acc_ * timeSinceLastFrame.asSeconds(), 0.f);
    }

    // move down 
    if (sf::Keyboard::isKeyPressed(KEY::MOV::DOWN)) {
        shape_->move(0.f, acc_ * timeSinceLastFrame.asSeconds());
    }

    // move up 
    if (sf::Keyboard::isKeyPressed(KEY::MOV::UP)) {
        shape_->move(0.f, -acc_ * timeSinceLastFrame.asSeconds());
    }  
}



void Player::Rotate(const std::unique_ptr<sf::RenderWindow>& window) {

    sf::Vector2f mousePos = window->mapPixelToCoords(sf::Mouse::getPosition());
    lookingDirection_.x = mousePos.x - shape_->getPosition().x;
    lookingDirection_.y = mousePos.y - shape_->getPosition().y;
    float angle = atan2(lookingDirection_.y, lookingDirection_.x) * 57.296f;
    shape_->setRotation(angle + 90.f);
}



void Player::changeSelectedWeapon() {

    static bool weaponHasbeenChanged = false; // avoid "multiple" key pressing bug

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
        if (!weaponHasbeenChanged) {
            weaponIdx_ = (weaponIdx_ < equipedWeapons_.size()-1) ? weaponIdx_+1 : 0;
        }  
        weaponHasbeenChanged = true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
        if (!weaponHasbeenChanged) {
            weaponIdx_ = (weaponIdx_ > 0) ? weaponIdx_-1 : equipedWeapons_.size()-1;
        }
        weaponHasbeenChanged = true;
    } else {
        weaponHasbeenChanged = false;
    }
}