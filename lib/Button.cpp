/**
 * @file Button.cpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief 
 * @date 2024-03-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Button.hpp"


////////////////////////////////////
// ctors / dtor 
////////////////////////////////////

Button::Button(const sf::Vector2f& pos, const sf::Vector2f& size, const char* text) {
    InitAttributs(pos, size, text);        
}



////////////////////////////////////
// methods 
////////////////////////////////////

void Button::InitAttributs(const sf::Vector2f& pos, const sf::Vector2f& size, const char* text) {

    // button text font 
    font_.loadFromFile("../lib/fonts/ammo-pixel.ttf");

    // button shape
    shape_ = std::make_unique<sf::RectangleShape>();
    shape_->setSize(size);
    shape_->setOrigin(size/2.f);
    shape_->setPosition(pos);
    shape_->setFillColor(BUTTON::COLOR::FILL);
    shape_->setOutlineColor(BUTTON::COLOR::OUTLINE);

    // button text 
    if (text != nullptr) {
        text_.setString(text);
        text_.setFont(font_);
        text_.setCharacterSize(BUTTON::TEXT::CHAR_SIZE);
        text_.setFillColor(BUTTON::TEXT::COLOR);
        const sf::FloatRect textBounds = text_.getGlobalBounds();
        text_.setOrigin(
            sf::Vector2f(textBounds.left + textBounds.width/2.f, textBounds.top + textBounds.height/2.f)
        );
        text_.setPosition(shape_->getPosition());
    }
        
}



void Button::Update(const std::unique_ptr<sf::RenderWindow>& window) {

    // when hovered
    const sf::Vector2f mousePos = window->mapPixelToCoords(sf::Mouse::getPosition());
    if (shape_->getGlobalBounds().contains(mousePos)) {
        shape_->setOutlineThickness(BUTTON::THICKNESS::HOVERED);
    } else {
        shape_->setOutlineThickness(BUTTON::THICKNESS::DEFAULT);
    }

}



void Button::Render(const std::unique_ptr<sf::RenderWindow>& window) const {

    // draw button rectangle shape 
    window->draw(*shape_);

    // draw text only if argument is passed in Button ctor
    if (!text_.getString().isEmpty()) { 
        window->draw(text_); 
    }
}