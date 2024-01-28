#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>


class Player {

    float width_, height_;
    sf::RectangleShape playerShape_;
    sf::Vector2f pos_;
    float acc_;
    float rotationForce_;


    public : 
        
        Player(sf::RenderWindow* window, sf::Vector2f pos);
        virtual ~Player(); 

        void Update(sf::RenderWindow* window);
        void Render(sf::RenderWindow* window);

    protected :

        void InitAttributs();
        void Move();
        void Rotate();


};

#endif // PLAYER_HPP