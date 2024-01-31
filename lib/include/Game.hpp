/**
 * @file Game.hpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief Centralise everything in the game to update and render 
 * @date 2024-01-31
 * 
 * @copyright Copyright (c) 2024
 * 
 * @see main.cpp
 * 
 */


#ifndef GAME_HPP
#define GAME_HPP

// external lib 
#include <SFML/Graphics.hpp>

// game lib 
#include "Player.hpp"

class player;

class Game {

    sf::RenderWindow *mainWindow_;                ///< game window 
    sf::Event event_;                             ///< event object for key pressing 
    uint16_t mainWindowWidth_, mainWindowHeight_; ///< x and y dimensions
    Player* mainPlayer_;                          ///< main player 

    public :

        ////////////////////////////////////
        // ctors / dtor 
        ////////////////////////////////////

        /** @brief Construct a Game object */
        Game();

        /** @brief Destroy a Game object */
        virtual ~Game();

    protected : 

        /** @brief Initialise class attributs */
        void InitAttributs();

        /** @brief Initialise main player */
        void InitPlayer();

        /** @brief Handles keyboard interaction with the main window */
        void PollEvents(); 

        /** @brief Run the game i.e. update and render assets */
        void Run(); 

        /** @brief Update game assets */
        void Update();

        /** @brief Render game assets */
        void Render();

        
};


#endif // GAME_HPP