#ifndef GAME_HPP
#define GAME_HPP

// external lib 
#include <SFML/Graphics.hpp>

// game lib 
#include "Player.hpp"


class Game {

    sf::RenderWindow *mainWindow_;
    sf::Event event_;
    uint16_t mainWindowWidth_, mainWindowHeight_;
    Player* mainPlayer_;

    public :

        Game();
        virtual ~Game();

    protected : 

        void InitAttributs();
        void InitPlayer() { mainPlayer_ = new Player(mainWindow_); }
        void PollEvents(); 
        void Run(); 
        void Update();
        void Render();

        
};


#endif // GAME_HPP