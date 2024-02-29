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
// static members
////////////////////////////////////

Game* Game::game_ = nullptr;




////////////////////////////////////
// ctors / dtor 
////////////////////////////////////


Game::Game() {

    InitAttributs();
    InitPlayer();
    InitHud();
    Run();
}

Game::~Game() {
}




////////////////////////////////////
// methods 
////////////////////////////////////

Game* Game::Instantiate() {

    if (game_ == nullptr) {
        game_ = new Game();
    } 

    return game_;
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
    mainPlayer_ = std::make_unique<Player>(mainWindowSize_/2.f);
}



void Game::InitHud() {
    hud_ = std::make_unique<Hud>(
        mainPlayer_->getCurrentHealth(),
        mainPlayer_->getCurrentShield(),
        mainPlayer_->getAmmoInClip(),
        mainPlayer_->getTotalAmmoLeft(),
        mainWindowSize_);
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

    // main player
    mainPlayer_->Update(mainWindow_, timeSinceLastFrame);

    // head up display 
    hud_->Update(
        mainPlayer_->getAmmoInClip(),
        mainPlayer_->getTotalAmmoLeft(),
        mainPlayer_->getCurrentHealth(),
        mainPlayer_->getMaxHealth(),
        mainPlayer_->getCurrentShield(),
        mainPlayer_->getMaxShield()
        );
}



void Game::Render() {

    // clear old frame
    mainWindow_->clear();

    mainPlayer_->Render(mainWindow_);

    hud_->Render(mainWindow_);
    
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
                if (event_.key.code ==sf::Keyboard::Escape) {
                    mainWindow_->close();
                }
                break;
            
            default:
                break;
        }
    }
}