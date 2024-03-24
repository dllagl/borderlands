/**
 * @file Smg.hpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief class for smg firearm
 * @date 2024-03-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef SMG_HPP
#define SMG_HPP

#include "Firearm.hpp"

class Smg : public Firearm {


    public: 

        /** @brief Construct a new Weapon object */
        Smg() {};

        /**
         * @brief Construct a new Smg object
         * 
         * @param pos position of the object 
         */
        Smg(const sf::Vector2f& pos);

        /** @brief Destroy the Smg object */
        virtual ~Smg() {};


    private: 

        /**
         * @brief Initialise weapon's properties
         * 
         * @param pos initial position
         */
        void InitAttributs(const sf::Vector2f& pos) override;

};

#endif // SMG_HPP