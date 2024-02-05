/**
 * @file Weapon.hpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief Central class for game weapons 
 * @date 2024-02-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef WEAPON_HPP
#define WEAPON_HPP


#include <SFML/Graphics.hpp>
#include <vector>


class Weapon {

    sf::RectangleShape shape_;          ///< weapon shape (a rectangle at this point)
    static const float width_, height_; ///< weapon's x and y dimensions

    public :

        /** @brief Construct a new Weapon object */
        Weapon() {};

        /**
         * @brief Construct a new Weapon object
         * 
         * @param pos position of the object 
         * @param origin origin of the object's shape (relative to its 0,0 coordonates)
         */
        Weapon(const sf::Vector2f& pos, const sf::Vector2f& origin);

        /** @brief Destroy the Weapon object */
        virtual ~Weapon();



        /**
         * @brief Update weapon's properties
         * 
         * @param pos position
         * @param rotation rotation angle 
         */
        void Update(const sf::Vector2f& pos, const float rotation); 

        /**
         * @brief Render the object
         * 
         * @param window window to be rendered in
         */
        void Render(sf::RenderWindow* window); 

    protected : 

        /**
         * @brief Initialise weapon's properties
         * 
         * @param pos initial position
         * @param origin initial origin
         */
        void InitAttributs(const sf::Vector2f& pos, const sf::Vector2f& origin);

};

#endif // WEAPON_HPP

