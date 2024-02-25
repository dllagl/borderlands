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

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <iomanip>
#include <sstream>
#include <iostream>


class Hud {

    // ammo 
    std::unique_ptr<sf::Font> ammoFont_; ///< font for ammo text 
    std::unique_ptr<sf::Text> ammoText_; ///< text object to display current ammo 
    sf::Vector2f ammoTextPosition_;      ///< ammo text (x,y) position

    // health 
    std::unique_ptr<sf::Font> healthFont_; ///< font for health text 
    std::unique_ptr<sf::Text> healthText_; ///< text object to display current health 
    sf::Vector2f healthTextPosition_;      ///< health text (x,y) position

    // shield 
    std::unique_ptr<sf::Font> shieldFont_; ///< font for shield text 
    std::unique_ptr<sf::Text> shieldText_; ///< text object to display current shield 
    sf::Vector2f shieldTextPosition_;      ///< shield text (x,y) position

    public:

        /** @brief Construct a new Hud object */
        Hud() {};  

        /**
         * @brief Construct a new Hud object
         * 
         * @param ammoLeftInClip number of ammo left in the weapon's magazine 
         * @param totalAmmoLeft player's total number of available ammo 
         * @param playerHealth player's current health
         * @param playerShield player's current shield
         * @param windowSize main window's (x,y) dimensions
         */
        Hud(
            const uint16_t ammoLeftInClip,
            const uint16_t totalAmmoLeft,
            const uint16_t playerHealth,
            const uint16_t playerShield,
            const sf::Vector2f windowSize
            ); 

        /** @brief Destroy a Hud object */
        virtual ~Hud() {};

        /**
         * @brief Update HUD properties 
         * 
         * @param ammoLeftInClip number of ammo left in the weapon's magazine 
         * @param totalAmmoLeft player's total number of available ammo 
         * @param playerHealth player's current health
         * @param playerShield player's current shield
         */
        void Update(
            const uint16_t ammoLeftInClip,
            const uint16_t totalAmmoLeft,
            const uint16_t playerHealth,
            const uint16_t playerShield
            );

        /**
         * @brief Render HUD on game's window
         * 
         * @param window window to be rendered in
         */
        void Render(const std::unique_ptr<sf::RenderWindow>& window);

    
    protected:

        /**
         * @brief Initialise HUD attributes
         * 
         * @param ammoLeftInClip number of ammo left in the weapon's magazine 
         * @param totalAmmoLeft player's total number of available ammo 
         * @param playerHealth player's current health
         * @param playerShield player's current shield
         * @param windowSize main window's (x,y) dimensions
         */
        void InitAttributs(
            const uint16_t ammoLeftInClip,
            const uint16_t totalAmmoLeft,
            const uint16_t playerHealth,
            const uint16_t playerShield,
            const sf::Vector2f windowSize
            );

        /**
         * @brief Initialise ammo display properties
         * 
         * @param ammoLeftInClip number of ammo left in the weapon's magazine 
         * @param totalAmmoLeft player's total number of available ammo 
         * @param windowSize main window's (x,y) dimensions
         */
        void InitAmmoDisplay(
            const uint16_t ammoLeftInClip,
            const uint16_t totalAmmoLeft,
            const sf::Vector2f windowSize
        );

        /**
         * @brief Initialise main player's health display
         * 
         * @param playerHealth player's current health
         * @param windowSize main window's (x,y) dimensions
         */
        void InitHealthDisplay(const uint16_t playerHealth, const sf::Vector2f windowSize);

        /**
         * @brief Initialise main player's shield display
         * 
         * @param playerShield player's current shield
         * @param windowSize main window's (x,y) dimensions
         */
        void InitShieldDisplay(const uint16_t playerShield, const sf::Vector2f windowSize);

};


#endif // HUD_HPP