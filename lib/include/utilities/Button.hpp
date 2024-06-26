/**
 * @file Button.hpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief Class for pause menu buttons
 * @date 2024-03-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef DEF_BUTTON
#define DEF_BUTTON

#include <memory>
#include <functional>
#include "GAME_CONF.hpp"


class Button {

    std::unique_ptr<sf::RectangleShape> shape_; ///< rect shape of the button
    sf::Text text_; ///< text on the button 
    sf::Font font_; ///< text's font
    std::function<void()> func_; ///< action to perform when clicked

    public: 

        /**
         * @brief Construct a new Button object
         * 
         * @param pos (x,y) position coordonate 
         * @param size (x,y) rectangle size
         * @param func function to execute when button is clicked
         * @param text text displayed 
         */
        Button(
            const sf::Vector2f& pos,
            const sf::Vector2f& size,
            std::function<void()> func,
            const char* text = nullptr
        );

        /** @brief Destroy the Button object */
        virtual ~Button() {};

        /**
         * @brief Update button properties (hovering, clicked, ...)
         * 
         * @param window window to be rendered in 
         * @param mousePos (x,y) position coordonate of the mouse cursor
         */
        void Update(
            const std::unique_ptr<sf::RenderWindow>& window,
            const sf::Vector2f& mousePos
        );

        /**
         * @brief Render button shape and text
         * 
         * @param window window to be rendered in 
         */
        void Render(const std::unique_ptr<sf::RenderWindow>& window) const;

    protected: 

        /**
         * @brief Initialise button properties
         * 
         * @param pos (x,y) position coordonate 
         * @param size (x,y) rectangle size
         * @param text text displayed 
         */
        void InitAttributs(
            const sf::Vector2f& pos,
            const sf::Vector2f& size,
            const char* text
        );
};


#endif // DEF_BUTTON