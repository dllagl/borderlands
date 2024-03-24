/**
 * @file Hud.hpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief Central class for HUD display on screen
 * @date 2024-02-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef HUD_HPP
#define HUD_HPP

#include "Hud_health.hpp"
#include "Hud_shield.hpp"
#include "Hud_firearm.hpp"

class Hud_health;
class Hud_shield;
class Hud_firearm;

class Hud {

    std::unique_ptr<Hud_health> hudHealth_; ///< health display on HUD 
    std::unique_ptr<Hud_shield> hudShield_; ///< shield display on HUD 
    std::unique_ptr<Hud_firearm> hudFirearm_;  ///< weapon display on HUD

    public:

        /** @brief Construct a new Hud object */
        Hud() {};  

        /**
         * @brief Construct a new Hud object
         * 
         * @param playerHealth main player's current health
         * @param playerShield main player's current shield
         * @param ammoLeftInClip number of ammo left in the weapon's magazine 
         * @param totalAmmoLeft player's total number of available ammo 
         * @param weaponName equiped weapon's name
         * @param windowSize main window's (x,y) dimensions
         */
        Hud(
            const uint16_t playerHealth,
            const uint16_t playerShield,
            const uint16_t ammoLeftInClip,
            const uint16_t totalAmmoLeft,
            const std::string weaponName,
            const sf::Vector2f& windowSize
            ); 

        /** @brief Destroy a Hud object */
        virtual ~Hud() {};

        /**
         * @brief Update HUD properties 
         * 
         * @param ammoLeftInClip number of ammo left in the weapon's magazine 
         * @param totalAmmoLeft player's total number of available ammo 
         * @param playerHealth player's current health
         * @param playerMaxHealth player's maximum health
         * @param playerShield player's current shield
         * @param playerMaxShield player's maximum shield
         */
        void Update(
            const uint16_t ammoLeftInClip,
            const uint16_t totalAmmoLeft,
            const uint16_t playerHealth,
            const uint16_t playerMaxHealth,
            const uint16_t playerShield,
            const uint16_t playerMaxShield
            );

        /**
         * @brief Render HUD on game's window
         * 
         * @param window window to be rendered in
         */
        void Render(const std::unique_ptr<sf::RenderWindow>& window) const;

    protected:

        /**
         * @brief Initialise HUD attributes
         * 
         * @param playerHealth main player's current health
         * @param playerShield main player's current shield
         * @param ammoLeftInClip number of ammo left in the weapon's magazine 
         * @param totalAmmoLeft player's total number of available ammo
         * @param weaponName equiped weapon's name  
         * @param windowSize main window's (x,y) dimensions
         */
        void InitAttributs(
            const uint16_t playerHealth,
            const uint16_t playerShield,
            const uint16_t ammoLeftInClip,
            const uint16_t totalAmmoLeft,
            const std::string weaponName,
            const sf::Vector2f& windowSize
        );

};


#endif // HUD_HPP