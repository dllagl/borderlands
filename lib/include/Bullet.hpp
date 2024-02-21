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
#include <cmath>


class Bullet {

    float radius_;                        ///< Radius of the bullet (a sphere for now)
    sf::Color color_;                     ///< Color of the shape
    sf::CircleShape shape_;               ///< Bullet main shape 
    sf::Vector2f dir_;                    ///< To store the direction of the bullet 
    sf::Vector2f offsetOriginFromWeapon_; ///< offset of bullet's position from weapon
    sf::Vector2f initialPosition_;        ///< spawning bullet's (x,y)  coordonate 
    bool hasReachedMaxDistance_;          ///< true when bullet has moved to its max distance

    public : 

        /** @brief Construct a new Bullet object */
        Bullet() {};

        /**
         * @brief Construct a new Bullet object
         * 
         * @param pos spawning position (Player's body's geometrical center) 
         * @param weaponOffsetFromPlayer offset position from spawning position
         * @param rotation player's rotation angle  
         * @param direction direction of the bullet to be fired 
         * @param weaponWidth weapon's x dimension to spawn bullet at its center
         */
        Bullet(
            const sf::Vector2f& pos,
            const sf::Vector2f& weaponOffsetFromPlayer,
            const float rotation,
            const sf::Vector2f& direction,
            const float weaponWidth
            );

        /** @brief Destroy the Bullet object */
        virtual ~Bullet();

        /**
         * @brief Update bullet's properties
         * 
         * @param velocity speed at which it will move 
         * @param timeSinceLastFrame time since the last window frame
         * @param maxDistance bullet's maximum flying distance 
         */
        void Update(const float velocity, const sf::Time& timeSinceLastFrame, const float maxDistance);

        /**
         * @brief Render the object
         * 
         * @param window window to be rendered in 
         */
        void Render(const std::unique_ptr<sf::RenderWindow>& window);

        /** @brief return true if bullet has traveled its maximum distance */
        inline const bool getHasReachedMaxDistance() const { return hasReachedMaxDistance_; }


    protected : 

        /**
         * @brief Initialise bullet's attributs
         * 
         * @param weaponOffsetFromPlayer offset position from spawning position
         * @param rotation player's rotation angle  
         * @param weaponWidth weapon's x dimension to spawn bullet at its center
         */
        void InitAttributs(
            const sf::Vector2f& weaponOffsetFromPlayer,
            const float rotation,
            const float weaponWidth
            );

        /**
         * @brief Handle bullet's movements
         * 
         * @param velocity speed at which it will move
         * @param timeSinceLastFrame time since the last window frame
         * @param maxDistance bullet's maximum flying distance 
         */
        void Move(const float velocity, const sf::Time& timeSinceLastFrame, const float maxDistance);

};

#endif // BULLET_HPP