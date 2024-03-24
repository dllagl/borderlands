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

#include "Firearm_smg.hpp"
#include "Firearm_pistol.hpp"

class Firearm;
class Player {

    // player properties
    std::unique_ptr<sf::RectangleShape> shape_;  ///< shape of the player (a rectangle here)
    static const float width_, height_;          ///< x and y dimensions
    float acc_;                                  ///< velocity
    float rotationForce_;                        ///< angular velocity
    sf::Vector2f lookingDirection_;              ///< vector of the player's rotation direction

    uint16_t maxHealth_, currentHealth_; ///< maximum and current health
    uint16_t maxShield_, currentShield_; ///< maximum and current shield

    // inventory properties
    std::vector<std::unique_ptr<Firearm>> equipedWeapons_;
    static uint8_t weaponIdx_;

    public : 

        /**
         * @brief Construct a new Player object
         * 
         * @param pos default x and y position's coordonates
         */
        Player(const sf::Vector2f& pos);

        /** @brief Destroy the Player object */
        virtual ~Player() {}; 


        /**
         * @brief Update every states (position, rotation, ..)
         * 
         * @param window window to be rendered in 
         * @param timeSinceLastFrame time since the last window frame
         */
        void Update(const std::unique_ptr<sf::RenderWindow>& window, const sf::Time& timeSinceLastFrame);

        /**
         * @brief Render the player 

         * @param window window to be rendered in
         */
        void Render(const std::unique_ptr<sf::RenderWindow>& window) const;



        /** @brief Return current number of ammo in the weapon's magazine */
        const uint16_t getAmmoInClip() const { return equipedWeapons_.at(weaponIdx_)->getAmmoInClip();}

        /** @brief Return the total number of ammunitions left for the player */
        const uint16_t getTotalAmmoLeft() const { return equipedWeapons_.at(weaponIdx_)->getTotalAmmoLeft();}

        /** @brief Return the weapon's name */
        const std::string getWeaponName() const { return equipedWeapons_.at(weaponIdx_)->getName();}

        /** @brief Return player's current health */
        const uint16_t getCurrentHealth() const { return currentHealth_; }

        /** @brief Return player's maximum health */
        const uint16_t getMaxHealth() const { return maxHealth_; }

        /** @brief Return player's current shield */
        const uint16_t getCurrentShield() const { return currentShield_; }

        /** @brief Return player's maximum shield */
        const uint16_t getMaxShield() const { return maxShield_; }


    protected :

        /** @brief Initialise class attributes */
        void InitAttributs(const sf::Vector2f& pos);

        /**
         * @brief Handle player's movements
         * 
         * Player moves up, left, down, and right with 
         * ZQSD keys, respectively. 
         * 
         * @param timeSinceLastFrame time since the last window frame
         */
        void Move(const sf::Time& timeSinceLastFrame);

        /**
         * @brief Handle player's rotation
         * 
         * The player rotates with the mouse's cursor.
         * This function computes the angle between the player's body 
         * and the cursor to set the according rotation angle. 
         * 
         * @param window window to be rendered in
         */
        void Rotate(const std::unique_ptr<sf::RenderWindow>& window);

        /** @brief Update player's selected weapon in its inventory*/
        void changeSelectedWeapon();

};

#endif // PLAYER_HPP