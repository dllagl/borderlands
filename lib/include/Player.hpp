/**
 * @file Player.hpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief Handle the game's main player e.g. its movements, shoots and so on ... 
 * @date 2024-01-31
 * 
 * @copyright Copyright (c) 2024
 * 
 * @see Game.hpp
 * 
 */


#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>


class Player {

    float width_, height_;     ///< x and y dimensions
    sf::RectangleShape shape_; ///< shape of the player (a rectangle here)
    sf::Vector2f pos_;         ///< x and y coordonate
    float acc_;                ///< velocity
    float rotationForce_;      ///< angular velocity


    public : 
        
        ////////////////////////////////////
        // ctors / dtor 
        ////////////////////////////////////

        /**
         * @brief Construct a new Player object
         * 
         * @param window window to be rendered in 
         * @param pos default x and y position's coordonates
         */
        Player(sf::RenderWindow* window, sf::Vector2f pos);

        /** @brief Destroy the Player object */
        virtual ~Player(); 



        ////////////////////////////////////
        // methods 
        ////////////////////////////////////

        /**
         * @brief Update every states (position, rotation, ..)
         * 
         * @param window window to be rendered in 
         */
        void Update(sf::RenderWindow* window);

        /**
         * @brief Render the player 

         * @param window window to be rendered in
         */
        void Render(sf::RenderWindow* window);


    protected :

        /** @brief Initialise class attributes */
        void InitAttributs();

        /** @brief Handle movements */
        void Move();

        /** @brief Handles rotation */
        void Rotate();


};

#endif // PLAYER_HPP