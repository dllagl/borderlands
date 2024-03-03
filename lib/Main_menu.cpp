/**
 * @file Main_menu.cpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief 
 * @date 2024-03-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Main_menu.hpp"


////////////////////////////////////
// ctors / dtor 
////////////////////////////////////

MainMenu::MainMenu(const std::unique_ptr<sf::RenderWindow>& window) {
    InitAttributs(window);
}



////////////////////////////////////
// methods
////////////////////////////////////

void MainMenu::InitAttributs(const std::unique_ptr<sf::RenderWindow>& window) {
    
    // button to quit the game
    quit_ = std::make_unique<Button>(
        window->getView().getCenter(),
        BUTTON::TEXT::SIZE,
        "LEAVE"
    );
}



void MainMenu::Update(const std::unique_ptr<sf::RenderWindow>& window) {
    quit_->Update(window, [&](){window->close();});
}



void MainMenu::Render(const std::unique_ptr<sf::RenderWindow>& window) const {
    quit_->Render(window);
}