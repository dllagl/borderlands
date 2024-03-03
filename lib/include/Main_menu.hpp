/**
 * @file Main_menu.hpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief 
 * @date 2024-03-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef DEF_MAIN_MENU
#define DEF_MAIN_MENU


#include "Button.hpp"


class Button;
class MainMenu {

    std::unique_ptr<Button> quit_; ///< button to quit the game

    public:

        /**
         * @brief Construct a new Main Menu object
         * 
         * @param window window to be rendered in
         */
        MainMenu(const std::unique_ptr<sf::RenderWindow>& window);

        /** @brief Destroy the Main Menu object */
        virtual ~MainMenu() {};

        /**
         * @brief Update pause menu properties
         * 
         * @param window window to be rendered in 
         */
        void Update(const std::unique_ptr<sf::RenderWindow>& window);

        /**
         * @brief Render pause menu's assets
         * 
         * @param window window to be rendered in 
         */
        void Render(const std::unique_ptr<sf::RenderWindow>& window) const;


    protected:

        /**
         * @brief Initialise pause menu properties
         * 
         * @param window window to be rendered in
         */
        void InitAttributs(const std::unique_ptr<sf::RenderWindow>& window);
};


#endif // DEF_MAIN_MENU