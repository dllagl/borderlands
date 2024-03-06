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
    
    // menu properties 
    isOpen_ = false;
    
    // button to quit the game
    buttons_.push_back(
        std::make_unique<Button>(
        window->getView().getCenter(),
        BUTTON::DIM::SIZE,
        [&](){window->close();},
        BUTTON::NAME::QUIT
        )
    );

    /*
    Button to close pause menu and resume the game 
    
    !!! 
    NOTE put to sleep current thread for 50 ms after closing the
    menu to avoid triggering unwanted game action i.e. firing bullets 
    !!!
    */
    buttons_.push_back(
        std::make_unique<Button>(
        window->getView().getCenter() - sf::Vector2f(0.f,100.f),
        BUTTON::DIM::SIZE,
        [&](){
            setIsOpen(false);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            },
        BUTTON::NAME::RESUME
        )
    );
}



void MainMenu::Update(const std::unique_ptr<sf::RenderWindow>& window) {

    if (isOpen_) {
        // mouse position on window for hovering computation
        const sf::Vector2f mousePos = window->mapPixelToCoords(sf::Mouse::getPosition());

        for (auto& b : buttons_) {
            b->Update(window, mousePos);
        }
    }
}



void MainMenu::Render(const std::unique_ptr<sf::RenderWindow>& window) const {

    if (isOpen_) {
        for (const auto& b : buttons_) {
            b->Render(window);
        }
    }
}