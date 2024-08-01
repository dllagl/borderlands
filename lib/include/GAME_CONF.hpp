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
        extern const float DEFAULT;
        extern const float HOVERED;
    };

    namespace COLOR {
        extern const sf::Color FILL;
        extern const sf::Color OUTLINE;
    };

    namespace TEXT {
        extern const sf::Color COLOR;
        extern const int CHAR_SIZE; 
    };

    namespace DIM {
        extern const float WIDTH; 
        extern const float HEIGHT;
        extern const sf::Vector2f SIZE;
    };

    namespace NAME {
        extern const char* const QUIT;
        extern const char* const RESUME; 
    };
};


/** @brief Global keybindings */
namespace KEY {
    typedef sf::Keyboard sfk;
    typedef sf::Mouse sfm;

    // player's movements 
    namespace MOV {
        extern const sfk::Key UP;
        extern const sfk::Key DOWN;
        extern const sfk::Key LEFT;
        extern const sfk::Key RIGHT;
    };

    namespace WEAPON {
        extern const sfk::Key RELOAD;
        extern const sfm::Button SHOOT; 
    };
};


#endif // DEF_GAME_CONF