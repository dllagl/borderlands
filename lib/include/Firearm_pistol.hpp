/**
 * @file Firearm_pistol.hpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief class for smg firearm
 * @date 2024-03-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef DEF_FIREARM_PISTOL
#define DEF_FIREARM_PISTOL

#include "Firearm.hpp"

class Firearm_pistol : public Firearm {


    public: 

        /** @brief Construct a new Weapon object */
        Firearm_pistol() {};

        /**
         * @brief Construct a new Firearm_pistol object
         * 
         * @param pos position of the object 
         */
        Firearm_pistol(const sf::Vector2f& pos);

        /** @brief Destroy the Firearm_pistol object */
        virtual ~Firearm_pistol() {};


    private: 

        /**
         * @brief Initialise weapon's properties
         * 
         * @param pos initial position
         */
        void InitAttributs(const sf::Vector2f& pos) override;

};

#endif // DEF_FIREARM_PISTOL