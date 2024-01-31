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
    playerShape_ = sf::RectangleShape(sf::Vector2f(width_, height_));
    playerShape_.setOrigin(width_/2.f, height_/2.f);
    playerShape_.setPosition(pos_);
    playerShape_.setFillColor(sf::Color::Green);
}


void Player::Update(sf::RenderWindow* window) {
    Move();
    Rotate();
}


void Player::Render(sf::RenderWindow* window) {
    window->draw(playerShape_);
}

void Player::Move() {

    // move right 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        playerShape_.move(acc_, 0.f);
    }

    // move left 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        playerShape_.move(-acc_, 0.f);
    }

    // move down 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        playerShape_.move(0.f, acc_);
    }

    // move up 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        playerShape_.move(0.f, -acc_);
    }  
}

void Player::Rotate() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        playerShape_.rotate(-rotationForce_);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        playerShape_.rotate(rotationForce_);
    }
}