#include "Game.hpp"


////////////////////////////////////
// ctors / dtor 
////////////////////////////////////


Game::Game() {

    InitAttributs();
    Run();
}

Game::~Game() {
    delete mainWindow_;
}





////////////////////////////////////
// methods 
////////////////////////////////////

void Game::InitAttributs() {

    MAIN_WINDOW_WIDTH_ = 1200;
    MAIN_WINDOW_HEIGHT_ = 800;    
    
    mainWindow_ = new sf::RenderWindow(
        sf::VideoMode(MAIN_WINDOW_WIDTH_,MAIN_WINDOW_HEIGHT_), "SMFL works!"
        );
}

void Game::Run() {

    while (mainWindow_->isOpen()) {

        Update();
        Render();

    }
}

void Game::Update() {
    PollEvents();
}

void Game::Render() {

    // clear old frame
    mainWindow_->clear();
    
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