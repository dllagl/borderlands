/**
 * @file Bullet.hpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief Class of basic bull_ets properties 
 * @date 2024-02-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>


class Bullet {

    float radius_;
    sf::Color color_;
    sf::CircleShape shape_;
    sf::Vector2f initialPos_;
    sf::Vector2f dir_;
    float velocity_;

    public : 

        ////////////////////////////////////
        // ctors / dtor 
        ////////////////////////////////////

        Bullet() {};
        Bullet(sf::Vector2f pos,sf::Vector2f direction);
        virtual ~Bullet();


        ////////////////////////////////////
        // methods 
        ////////////////////////////////////

        void Update();
        void Render(sf::RenderWindow* window);


    protected : 

        void InitAttributs();
        void Move();

};

#endif // BULLET_HPP