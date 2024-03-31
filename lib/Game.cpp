/**
 * @file Game.cpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief 
 * @date 2024-01-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Game.hpp"



////////////////////////////////////
// ctors / dtor 
////////////////////////////////////


Game::Game() {

    InitAttributs();
    InitPlayer();
    InitPauseMenu();
    InitHud();
    Run();
}



////////////////////////////////////
// methods 
////////////////////////////////////

Game& Game::Instantiate() {

    static Game gameInstance;
    return gameInstance;
}



void Game::InitAttributs() {

    mainWindowSize_.x = 1920;
    mainWindowSize_.y = 1080;    

    mainWindow_ = std::make_unique<sf::RenderWindow>(
        sf::VideoMode(mainWindowSize_.x,mainWindowSize_.y), "SMFL works!", sf::Style::Fullscreen
    );
    mainWindow_->setFramerateLimit(60);
}



void Game::InitPlayer() {
    mainPlayer_ = std::make_unique<Player>(mainWindow_->getView().getCenter());
}



void Game::InitPauseMenu() {
    menu_ = std::make_unique<MainMenu>(mainWindow_);
}



void Game::InitHud() {
    hud_ = std::make_unique<Hud>(
        mainPlayer_->getCurrentHealth(),
        mainPlayer_->getCurrentShield(),
        mainPlayer_->getAmmoInClip(),
        mainPlayer_->getTotalAmmoLeft(),
        mainPlayer_->getWeaponName(),
        mainWindowSize_
        );
}



void Game::Run() {

    sf::Clock clock; // starts time clock 
    sf::Time timeElapsedSinceLastFrame;

    while (mainWindow_->isOpen()) {

        // see https://www.sfml-dev.org/tutorials/2.6/system-time.php for time management
        timeElapsedSinceLastFrame = clock.restart();

        Update(timeElapsedSinceLastFrame);
        Render();

    }
}



void Game::Update(const sf::Time& timeSinceLastFrame) {

    // keyboard events
    PollEvents();

    // do not update game assets when pause menu is open
    if (!menu_->getIsOpen()) {
            
        // main player
        mainPlayer_->Update(mainWindow_, timeSinceLastFrame);

        // head up display 
        hud_->Update(
            mainPlayer_->getAmmoInClip(),
            mainPlayer_->getTotalAmmoLeft(),
            mainPlayer_->getWeaponName(),
            mainPlayer_->getCurrentHealth(),
            mainPlayer_->getMaxHealth(),
            mainPlayer_->getCurrentShield(),
            mainPlayer_->getMaxShield()
            );
    }

    // pause menu
    menu_->Update(mainWindow_);
}



void Game::Render() {

    // clear old frame
    mainWindow_->clear();

    // do not render game assets when pause menu is open
    if (!menu_->getIsOpen()) {
        mainPlayer_->Render(mainWindow_);
        hud_->Render(mainWindow_);
    }
    
    menu_->Render(mainWindow_);  
 
    // display updated assets
    mainWindow_->display();
}



void Game::PollEvents() {

    while (mainWindow_->pollEvent(event_)) {

        switch (event_.type) {

            case sf::Event::Closed:
                mainWindow_->close();
                break;
            
            case sf::Event::KeyPressed:
                break;
            
            default:
                break;
        }
    }


    /*
    Enable pause menu to be opened and closed on demand.
    
    The use of a static boolean to save wether or not a key 
    has been pressed earlier is to avoid flickering of the 
    MainMenu::shape_ when on display
    */
    static bool wasEscapeKeyPressed = false;
    if (event_.key.code == sf::Keyboard::Escape) {
        if (!wasEscapeKeyPressed) {
            // open or close pause menu depending on its current state
            menu_->setIsOpen(!menu_->getIsOpen());
        }
        wasEscapeKeyPressed = true;
    } else {
        wasEscapeKeyPressed = false;
    }
}