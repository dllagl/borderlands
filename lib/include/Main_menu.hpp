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

#include<chrono> 
#include<thread>
#include "Button.hpp"


class Button;
class MainMenu {
    
    bool isOpen_; ///< TRUE if menu is open, FALSE if not
    std::vector<std::unique_ptr<Button >> buttons_; ///< vector containing the menu buttons

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

        /** @brief return TRUE is menuy is open, FALSE if not */
        const bool getIsOpen() const { return isOpen_; }

        /**
         * @brief close or open pause menu depending on its current state
         * 
         * @param newState new state of pause menu
         */
        void setIsOpen(const bool newState) { isOpen_ = newState; }


    protected:

        /**
         * @brief Initialise pause menu properties
         * 
         * @param window window to be rendered in
         */
        void InitAttributs(const std::unique_ptr<sf::RenderWindow>& window);
};


#endif // DEF_MAIN_MENU