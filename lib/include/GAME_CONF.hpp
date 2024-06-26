/**
 * @file GAME_CONF.hpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief Contains game constants in namespaces
 * @date 2024-03-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef DEF_GAME_CONF
#define DEF_GAME_CONF

#include <SFML/Graphics.hpp>
#include <string>

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
    };

    namespace DIM {
        constexpr float WIDTH   = 130.f;
        constexpr float HEIGHT  = 70.f;
        const sf::Vector2f SIZE = sf::Vector2f(WIDTH, HEIGHT);
    };

    namespace NAME {
        const char* const QUIT   = "LEAVE";
        const char* const RESUME = "RESUME"; 
    };
};


/** @brief Global keybindings */
namespace KEY {
    typedef sf::Keyboard sfk;
    typedef sf::Mouse sfm;

    // player's movements 
    namespace MOV {
        const sfk::Key UP    = sfk::Z;
        const sfk::Key DOWN  = sfk::S;
        const sfk::Key LEFT  = sfk::Q;
        const sfk::Key RIGHT = sfk::D;
    };

    namespace WEAPON {
        const sfk::Key RELOAD   = sfk::R;
        const sfm::Button SHOOT = sfm::Left; 
    };
};


#endif // DEF_GAME_CONF