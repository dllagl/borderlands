/**
 * @file Firearm.hpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief Abstract class for firearm (pistols, smg, sniper, ..)
 * @date 2024-03-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef FIREARM_HPP
#define FIREARM_HPP

#include "Item.hpp"
#include "Bullet.hpp"

class Bullet;
class Firearm : public Item {

    protected: 

        // body 
        std::unique_ptr<sf::RectangleShape> shape_; ///< weapon shape (a rectangle at this point)
        sf::Vector2f offsetOriginFromPlayerCenter_; ///< offset position coordonate from player's body
        float width_, height_;                      ///< weapon's x and y dimensions

        // ammunitions
        uint16_t magazineSize_;       ///< clip's size
        uint16_t maxAmmo_;            ///< maximum amount of ammo allowed
        uint16_t currentAmmoInClip_;  ///< current number of ammo left in clip
        uint16_t currentAmmoLeft_;    ///< current total number of ammo left 

        // weapon properties
        std::vector<std::unique_ptr<Bullet>> bullets_; ///< vector of the fired bullets
        float fireRate_;       ///< weapon's fire rate (bullet per sec)
        float fireRange_;      ///< bullet's max distance of flying
        float bulletVelocity_; ///< bullet's speed
        float damage_;
        float reloadSpeed_;

    public: 

        Firearm() {};
        virtual ~Firearm() {};


    protected:
    
        virtual void InitAttributs(const sf::Vector2f& pos) = 0;
        virtual void Shoot(sf::Vector2f& direction) = 0;
        virtual void Reload() = 0;

};

#endif // FIREARMS_HPP