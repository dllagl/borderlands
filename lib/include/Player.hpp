#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>


class Player {

    float width_, height_;
    sf::RectangleShape playerShape_;


    public : 
        
        Player(sf::RenderWindow* window);
        virtual ~Player(); 

        void Update(sf::RenderWindow* window);
        void Render(sf::RenderWindow* window);

    protected :

        void InitAttributs();


};

#endif // PLAYER_HPP