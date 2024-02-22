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


#include <vector>
#include <chrono>
#include <memory>
#include <iostream>

#include "Bullet.hpp"

class Bullet;


class Weapon {

    // body 
    std::unique_ptr<sf::RectangleShape> shape_; ///< weapon shape (a rectangle at this point)
    static const float width_, height_;         ///< weapon's x and y dimensions
    sf::Vector2f offsetOriginFromPlayerCenter_; ///< offset position coordonate from player's body

    // ammunitions
    uint16_t maxAmmo_;           ///< maximum amount of ammo allowed     
    uint16_t currentAmmoLeft_;   ///< current total number of ammo left 
    uint16_t currentAmmoInClip_; ///< current number of ammo left in clip
    uint16_t clipSize_;          ///< clip's size

    // bullets properties
    std::vector<std::unique_ptr<Bullet>> bullets_;  ///< vector of the fired bullets
    float bulletVelocity_;  ///< bullet's speed
    float fireRate_;        ///< weapon's fire rate (bullet per sec)
    float fireRange_;       ///< bullet's max distance of flying

    public :

        /** @brief Construct a new Weapon object */
        Weapon() {};

        /**
         * @brief Construct a new Weapon object
         * 
         * @param pos position of the object 
         */
        Weapon(const sf::Vector2f& pos);

        /** @brief Destroy the Weapon object */
        virtual ~Weapon();



        /**
         * @brief Update weapon's properties
         * 
         * @param pos position
         * @param rotation rotation angle
         * @param aimingDirection eye direction of the player
         * @param timeSinceLastFrame time since the last window frame 
         */
        void Update(
            const sf::Vector2f& pos,
            const float rotation,
            sf::Vector2f& aimingDirection,
            const sf::Time& timeSinceLastFrame
            ); 

        /**
         * @brief Render the object
         * 
         * @param window window to be rendered in
         */
        void Render(const std::unique_ptr<sf::RenderWindow>& window); 

    protected : 

        /**
         * @brief Initialise weapon's properties
         * 
         * @param pos initial position
         */
        void InitAttributs(const sf::Vector2f& pos);

        /**
         * @brief Shoot bullets
         * 
         * @param direction vector of the direction bullets will move towards
         */
        void Shoot(sf::Vector2f& direction);

        /** @brief Reload the weapon's clip to full capacity if enough remaining ammo */
        void Reload();

};

#endif // WEAPON_HPP

