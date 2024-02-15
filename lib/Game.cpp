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
    Run();
}

Game::~Game() {
    delete mainWindow_;
    delete mainPlayer_;
}





////////////////////////////////////
// methods 
////////////////////////////////////

void Game::InitAttributs() {

    mainWindowWidth_ = 1200;
    mainWindowHeight_ = 800;    

    mainWindow_ = new sf::RenderWindow(
        sf::VideoMode(mainWindowWidth_,mainWindowHeight_), "SMFL works!"
        );

    mainWindow_->setFramerateLimit(60);
}

void Game::InitPlayer() {
    mainPlayer_ = new Player(sf::Vector2f(mainWindowWidth_/2.f, mainWindowHeight_/2.f));
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
    PollEvents();
    mainPlayer_->Update(mainWindow_, timeSinceLastFrame);
}

void Game::Render() {

    // clear old frame
    mainWindow_->clear();

    mainPlayer_->Render(mainWindow_);
    
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