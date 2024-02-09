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

    public : 

        ////////////////////////////////////
        // ctors / dtor 
        ////////////////////////////////////

        Bullet() {};
        Bullet(const sf::Vector2f& pos, const sf::Vector2f& direction);
        virtual ~Bullet();


        ////////////////////////////////////
        // methods 
        ////////////////////////////////////

        void Update(const float velocity);
        void Render(sf::RenderWindow* window);


    protected : 

        void InitAttributs();
        void Move(const float velocity);

};

#endif // BULLET_HPP