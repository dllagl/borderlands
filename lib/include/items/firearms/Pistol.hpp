/**
 * @file Pistol.hpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief class for smg firearm
 * @date 2024-03-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef DEF_PISTOL
#define DEF_PISTOL

#include "items/firearms/Firearm.hpp"

class Pistol : public Firearm {


    public: 

        /** @brief Construct a new Weapon object */
        Pistol() {};

        /**
         * @brief Construct a new Pistol object
         * 
         * @param pos position of the object 
         */
        Pistol(const sf::Vector2f& pos);

        /** @brief Destroy the Pistol object */
        virtual ~Pistol() {};


    private: 

        /**
         * @brief Initialise weapon's properties
         * 
         * @param pos initial position
         */
        void InitAttributs(const sf::Vector2f& pos) override;

};

#endif // DEF_PISTOL