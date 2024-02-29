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

#include "Player.hpp"
#include "Hud.hpp"

class player;
class Hud;

class Game {
    
    std::unique_ptr<sf::RenderWindow> mainWindow_; ///< game window 
    sf::Event event_;                              ///< event object for key pressing 
    sf::Vector2f mainWindowSize_;                  ///< x and y dimensions
    std::unique_ptr<Player> mainPlayer_;           ///< main player 
    std::unique_ptr<Hud> hud_;                     ///< head up display 


    /** @brief Construct a Game object (private for singleton) */
    Game();

    public:

        /** @brief Destroy a Game object */
        virtual ~Game() {};

        /**
         * @brief Instantiate a Game object as a singleton
         * 
         * @return The reference to the Game instance
         */
        static Game& Instantiate();

        Game(Game& copy) = delete; // prevent copy
        void operator=(const Game&) = delete; // prevent assignement

    protected: 

        /** @brief Initialise class attributs */
        void InitAttributs();

        /** @brief Initialise main player */
        void InitPlayer();

        /** @brief Initialise HUD */
        void InitHud();

        /** @brief Handles keyboard interaction with the main window */
        void PollEvents(); 

        /** @brief Run the game i.e. update and render assets */
        void Run(); 

        /** 
         * @brief Update game assets 
         * 
         * @param timeSinceLastFrame time since the last window frame 
         */
        void Update(const sf::Time& timeSinceLastFrame);

        /** @brief Render game assets */
        void Render();

        
};


#endif // GAME_HPP