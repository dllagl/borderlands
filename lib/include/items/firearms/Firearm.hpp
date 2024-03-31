/**
 * @file Firearm.hpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief Abstract class for firearm (pistols, smg, sniper, ..)
 * @date 2024-03-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef FIREARM_HPP
#define FIREARM_HPP

#include "items/Item.hpp"
#include "Bullet.hpp"

class Bullet;
class Firearm : public Item {

    protected: 

        // body 
        std::unique_ptr<sf::RectangleShape> shape_; ///< weapon shape (a rectangle at this point)
        sf::Vector2f offsetOriginFromPlayerCenter_; ///< offset position coordonate from player's body
        float width_, height_;                      ///< weapon's x and y dimensions

        // ammunitions
        uint16_t magazineSize_;       ///< clip's size
        uint16_t maxAmmo_;            ///< maximum amount of ammo allowed
        uint16_t currentAmmoInClip_;  ///< current number of ammo left in clip
        uint16_t currentAmmoLeft_;    ///< current total number of ammo left 

        // weapon properties
        std::vector<std::unique_ptr<Bullet>> bullets_; ///< vector of the fired bullets
        float fireRate_;       ///< weapon's fire rate (bullet per sec)
        float fireRange_;      ///< bullet's max distance of flying
        float bulletVelocity_; ///< bullet's speed
        float damage_;
        float reloadSpeed_;

    public: 

        Firearm() {};
        virtual ~Firearm() {};

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
        void Render(const std::unique_ptr<sf::RenderWindow>& window) const;

        /** @brief Return current number of ammo in the weapon's magazine */
        const uint16_t getAmmoInClip() const { return currentAmmoInClip_; }

        /** @brief Return the total number of ammunitions left for the player */
        const uint16_t getTotalAmmoLeft() const { return currentAmmoLeft_; }

        /** @brief Return the weapon's name */
        const std::string getName() const { return name_; }


    protected:

        /**
         * @brief Initialise weapon's properties
         * 
         * @param pos initial position
         */
        virtual void InitAttributs(const sf::Vector2f& pos) = 0;
        
        /**
         * @brief Shoot bullets
         * 
         * @param direction vector of the direction bullets will move towards
         */
        void Shoot(sf::Vector2f& direction);

        /** @brief Reload the weapon's clip to full capacity if enough remaining ammo */
        void Reload();

};

#endif // FIREARMS_HPP