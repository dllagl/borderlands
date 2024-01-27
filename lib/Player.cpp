#include "Player.hpp"


////////////////////////////////////
// ctors / dtor 
////////////////////////////////////

Player::Player(sf::RenderWindow* window) {

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

    playerShape_ = sf::RectangleShape(sf::Vector2f(width_, height_));
    playerShape_.setFillColor(sf::Color::Green);
}


void Player::Update(sf::RenderWindow* window) {
    // nothing to do yet 
}


void Player::Render(sf::RenderWindow* window) {
    window->draw(playerShape_);
}