/**
 * @file Hud_health.cpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief 
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "hud/Hud_health.hpp"



////////////////////////////////////
// ctors / dtor 
////////////////////////////////////

Hud_health::Hud_health(const uint16_t playerHealth, const sf::Vector2f& windowSize) 
    : displayedHealth_(playerHealth) {
    InitAttributs(windowSize);
}


////////////////////////////////////
// methods
////////////////////////////////////

void Hud_health::InitAttributs(const sf::Vector2f& windowSize) {

    // background health rectangle (fixed size, only the outline is colored)
    bgRect_ = sf::RectangleShape(sf::Vector2f(180.f,20.f));
    bgRect_.setOrigin(bgRect_.getSize()/2.f);
    bgRect_.setPosition(0.09f * windowSize.x, 0.9f * windowSize.y);
    bgRect_.setFillColor(sf::Color::Transparent);
    bgRect_.setOutlineColor(sf::Color::White);
    bgRect_.setOutlineThickness(2.0f);

    // actual health rectangle (its size evolves with player's health)
    rect_ = std::make_unique<sf::RectangleShape>(bgRect_.getSize());
    rect_->setOrigin(rect_->getSize()/2.f);
    rect_->setPosition(bgRect_.getPosition());
    rect_->setFillColor(sf::Color::Red);

    // font
    font_ = std::make_unique<sf::Font>();
    font_->loadFromFile("../refs/fonts/ammo-pixel.ttf");

    // text (positioned relatively to the background health rectangle)
    text_ = std::make_unique<sf::Text>();
    text_->setString(std::to_string(displayedHealth_));
    text_->setFont(*font_);
    text_->setCharacterSize(50);
    const sf::FloatRect textBounds = text_->getGlobalBounds();
    text_->setOrigin(
            sf::Vector2f(textBounds.left + textBounds.width/2.f, textBounds.top + textBounds.height/2.f)
        );
    text_->setPosition(bgRect_.getPosition() + sf::Vector2f(140.f,0.f));
    text_->setFillColor(sf::Color::Red);
}



void Hud_health::Update(const uint16_t playerHealth, const uint16_t playerMaxHealth) {

    // does not update health display if it has not changed since last frame
    if (playerHealth != displayedHealth_) {

        // update text 
        text_->setString(std::to_string(playerHealth));
        displayedHealth_ = playerHealth;

        // update rectangle
        float newSizeOfRect = ((float)playerHealth / playerMaxHealth) * bgRect_.getSize().x;
        rect_->setSize(sf::Vector2f(newSizeOfRect, rect_->getSize().y));
    }
}



void Hud_health::Render(const std::unique_ptr<sf::RenderWindow>& window) const {

    window->draw(*text_);
    window->draw(*rect_);
    window->draw(bgRect_);
    
}