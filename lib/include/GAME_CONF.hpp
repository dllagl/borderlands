/**
 * @file GAME_CONF.hpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief Contains game constants in namespaces
 * @date 2024-03-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <SFML/Graphics.hpp>

/** @brief Constants related to pause menu buttons */
namespace BUTTON {
    namespace THICKNESS {
        constexpr float DEFAULT = 0.f;
        constexpr float HOVERED = 5.f;
    };

    namespace COLOR {
        const sf::Color FILL    = sf::Color::Green;
        const sf::Color OUTLINE = sf::Color::White;
    };

    namespace TEXT {
        const sf::Color COLOR   = sf::Color::White;
        constexpr int CHAR_SIZE = 50; 
        constexpr float WIDTH   = 130.f;
        constexpr float HEIGHT  = 70.f;
        const sf::Vector2f SIZE = sf::Vector2f(WIDTH, HEIGHT);
    };
};