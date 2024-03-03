/**
 * @file Hud_shield.cpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief 
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Hud_shield.hpp"



////////////////////////////////////
// ctors / dtor 
////////////////////////////////////

Hud_shield::Hud_shield(const uint16_t playerShield, const sf::Vector2f& windowSize) 
    : displayedShield_(playerShield) {
    InitAttributs(windowSize);
}


////////////////////////////////////
// methods
////////////////////////////////////

void Hud_shield::InitAttributs(const sf::Vector2f& windowSize) {

    // background shield rectangle (fixed size, only the outline is colored)
    bgRect_ = sf::RectangleShape(sf::Vector2f(180.f,20.f));
    bgRect_.setOrigin(bgRect_.getSize()/2.f);
    bgRect_.setPosition(0.09f * windowSize.x, 0.94f * windowSize.y);
    bgRect_.setFillColor(sf::Color::Transparent);
    bgRect_.setOutlineColor(sf::Color::White);
    bgRect_.setOutlineThickness(2.0f);

    // actual shield rectangle (its size evolves with player's shield)
    rect_ = std::make_unique<sf::RectangleShape>(bgRect_.getSize());
    rect_->setOrigin(rect_->getSize()/2.f);
    rect_->setPosition(bgRect_.getPosition());
    rect_->setFillColor(sf::Color::Blue);

    // font
    font_ = std::make_unique<sf::Font>();
    font_->loadFromFile("../lib/fonts/ammo-pixel.ttf");

    // text (positioned relatively to the background shield rectangle)
    text_ = std::make_unique<sf::Text>();
    text_->setString(std::to_string(displayedShield_));
    text_->setFont(*font_);
    text_->setCharacterSize(50);
    const sf::FloatRect textBounds = text_->getGlobalBounds();
    text_->setOrigin(
            sf::Vector2f(textBounds.left + textBounds.width/2.f, textBounds.top + textBounds.height/2.f)
        );
    text_->setPosition(bgRect_.getPosition() + sf::Vector2f(140.f,0.f));
    text_->setFillColor(sf::Color::Blue);
}



void Hud_shield::Update(const uint16_t playerShield, const uint16_t playerMaxShield) {

    // does not update shield display if it has not changed since last frame
    if (playerShield != displayedShield_) {

        // update text 
        text_->setString(std::to_string(playerShield));
        displayedShield_ = playerShield;

        // update rectangle
        float newSizeOfRect = ((float)playerShield / playerMaxShield) * bgRect_.getSize().x;
        rect_->setSize(sf::Vector2f(newSizeOfRect, rect_->getSize().y));
    }
}



void Hud_shield::Render(const std::unique_ptr<sf::RenderWindow>& window) const {

    window->draw(*text_);
    window->draw(*rect_);
    window->draw(bgRect_);
    
}