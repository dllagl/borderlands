/**
 * @file Hud_firearm.hpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief class for ammo display on HUD
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef DEF_HUD_FIREARM
#define DEF_HUD_FIREARM

#include <SFML/Graphics.hpp>
#include <memory>
#include <iomanip>
#include <sstream>

class Hud_firearm {

    std::unique_ptr<sf::Text> textAmmo_; ///< text object to display current ammo 
    std::unique_ptr<sf::Text> textName_; ///< text object to display weapon's name 
    std::unique_ptr<sf::Font> font_;     ///< text font
    uint16_t displayedAmmoInClip_;       ///< current ammo in clip displayed on screen
    uint16_t displayedTotalAmmo_;        ///< current total ammo left displayed on screen
    std::string weaponName_;             ///< equiped weapon's name
    
    public: 

        /** @brief Construct a new Hud_firearm object */
        Hud_firearm() {};

        /**
         * @brief Construct a new Hud_firearm object
         * 
         * @param ammoLeftInClip number of ammo left in the weapon's magazine 
         * @param totalAmmoLeft player's total number of available ammo 
         * @param weaponName equiped weapon's name
         * @param windowSize main window's (x,y) dimensions
         */
        Hud_firearm(
            const uint16_t ammoLeftInClip,
            const uint16_t totalAmmoLeft,
            const std::string& name,
            const sf::Vector2f& windowSize
            );

        /**
         * @brief Update HUD's ammo component properties
         * 
         * @param ammoLeftInClip number of ammo left in the weapon's magazine 
         * @param totalAmmoLeft player's total number of available ammo 
         */
        void Update(const uint16_t ammoLeftInClip, const uint16_t totalAmmoLeft);

        /**
         * @brief Render HUD's ammo component on game window
         * 
         * @param window window to be rendered in
         */
        void Render(const std::unique_ptr<sf::RenderWindow>& window) const;

    protected:

        /**
         * @brief Initialise ammo display
         * 
         * @param windowSize game window's (x,y) dimensions
         */
        void InitAttributs(const sf::Vector2f& windowSize);
};


#endif // DEF_HUD_FIREARM