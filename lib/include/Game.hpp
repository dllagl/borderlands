#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class Game {

    sf::RenderWindow *mainWindow_;
    sf::Event event_;
    uint16_t MAIN_WINDOW_WIDTH_, MAIN_WINDOW_HEIGHT_;

    public :

        Game();
        virtual ~Game();

    protected : 

        void InitAttributs();
        void PollEvents(); 
        void Run(); 
        void Update();
        void Render();

        
};


#endif // GAME_HPP