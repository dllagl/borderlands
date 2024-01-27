#include "Player.hpp"


////////////////////////////////////
// ctors / dtor 
////////////////////////////////////

Player::Player(sf::RenderWindow* window, sf::Vector2f pos) 
    : pos_(pos) {

    InitAttributs();
    Update(window);
    Render(window);
}

Player::~Player() {
}




////////////////////////////////////
// methods 
////////////////////////////////////

void Player::InitAttributs() {

    width_ = 60.f;
    height_ = 40.f;
    acc_ = 0.5f;

    // set player at the center of the window at launch
    pos_.x -= width_/2.f;
    pos_.y -= height_/2.f;

    playerShape_ = sf::RectangleShape(sf::Vector2f(width_, height_));
    playerShape_.setPosition(pos_);
    playerShape_.setFillColor(sf::Color::Green);
}


void Player::Update(sf::RenderWindow* window) {
    Move();
}


void Player::Render(sf::RenderWindow* window) {
    window->draw(playerShape_);
}

void Player::Move() {

    // move right 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        pos_.x += acc_;
    }

    // move left 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        pos_.x -= acc_;
    }

    // move down 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        pos_.y += acc_;
    }

    // move up 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        pos_.y -= acc_;
    }  

    playerShape_.setPosition(pos_);
}