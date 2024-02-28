/**
 * @file Hud_shield.hpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief class for shield display on HUD
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef DEF_HUD_SHIELD
#define DEF_HUD_SHIELD

#include <SFML/Graphics.hpp>
#include <memory>

class Hud_shield {

    std::unique_ptr<sf::Text> text_; ///< text object to display current shield 
    std::unique_ptr<sf::Font> font_; ///< font for shield text
    uint16_t displayedShield_;       ///< current shield displayed on screen
    sf::RectangleShape bgRect_;      ///< background shield rectangle (fixed size)
    std::unique_ptr<sf::RectangleShape> rect_; ///< dynamic rectangle for player's shield

    public: 

        /** @brief Construct a new Hud_shield object */
        Hud_shield() {};

        /**
         * @brief Construct a new Hud_shield object
         * 
         * @param playerShield player's current shield
         * @param windowSize game window's (x,y) dimensions
         */
        Hud_shield(const uint16_t playerShield, const sf::Vector2f& windowSize);

        /**
         * @brief Update HUD's shield component properties
         * 
         * @param playerShield player's current shield
         * @param playerMaxShield player's max shield 
         */
        void Update(const uint16_t playerShield, const uint16_t playerMaxShield);

        /**
         * @brief Render HUD's shield component on game window
         * 
         * @param window window to be rendered in
         */
        void Render(const std::unique_ptr<sf::RenderWindow>& window);

    protected:

        /**
         * @brief Initialise shield display
         * 
         * @param windowSize game window's (x,y) dimensions
         */
        void InitAttributs(const sf::Vector2f& windowSize);
};


#endif // DEF_HUD_SHIELD