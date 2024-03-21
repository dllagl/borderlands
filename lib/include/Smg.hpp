/**
 * @file Smg.hpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief class for smg firearm
 * @date 2024-03-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef SMG_HPP
#define SMG_HPP

#include "Firearm.hpp"

class Smg : public Firearm {


    public: 

        /** @brief Construct a new Weapon object */
        Smg() {};

        /**
         * @brief Construct a new Smg object
         * 
         * @param pos position of the object 
         */
        Smg(const sf::Vector2f& pos);

        /** @brief Destroy the Smg object */
        virtual ~Smg() {};

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


    private: 

        /**
         * @brief Initialise weapon's properties
         * 
         * @param pos initial position
         */
        void InitAttributs(const sf::Vector2f& pos) override;

        /**
         * @brief Shoot bullets
         * 
         * @param direction vector of the direction bullets will move towards
         */
        void Shoot(sf::Vector2f& direction) override;

        /** @brief Reload the weapon's clip to full capacity if enough remaining ammo */
        void Reload() override;

};

#endif // SMG_HPP