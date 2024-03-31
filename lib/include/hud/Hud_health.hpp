/**
 * @file Hud_health.hpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief class for health display on HUD
 * @date 2024-02-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef DEF_HUD_HEALTH
#define DEF_HUD_HEALTH

#include <SFML/Graphics.hpp>
#include <memory>

class Hud_health {

    std::unique_ptr<sf::Text> text_; ///< text object to display current health 
    std::unique_ptr<sf::Font> font_; ///< font for health text
    uint16_t displayedHealth_;       ///< current health displayed on screen
    sf::RectangleShape bgRect_;      ///< background health rectangle (fixed size)
    std::unique_ptr<sf::RectangleShape> rect_; ///< dynamic rectangle for player's health

    public: 

        /** @brief Construct a new Hud_health object */
        Hud_health() {};

        /**
         * @brief Construct a new Hud_health object
         * 
         * @param playerHealth player's current health
         * @param windowSize game window's (x,y) dimensions
         */
        Hud_health(const uint16_t playerHealth, const sf::Vector2f& windowSize);

        /**
         * @brief Update HUD's health component properties
         * 
         * @param playerHealth player's current health
         * @param playerMaxHealth player's max health 
         */
        void Update(const uint16_t playerHealth, const uint16_t playerMaxHealth);

        /**
         * @brief Render HUD's health component on game window
         * 
         * @param window window to be rendered in
         */
        void Render(const std::unique_ptr<sf::RenderWindow>& window) const;

    protected:

        /**
         * @brief Initialise health display
         * 
         * @param windowSize game window's (x,y) dimensions
         */
        void InitAttributs(const sf::Vector2f& windowSize);
};


#endif // DEF_HUD_HEALTH