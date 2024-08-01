/**
 * @file GAME_CONF.cpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief 
 * @date 2024-08-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "GAME_CONF.hpp"

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