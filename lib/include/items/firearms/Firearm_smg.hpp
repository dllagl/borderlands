/**
 * @file Firearm_smg.hpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief class for smg firearm
 * @date 2024-03-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef DEF_FIREARM_SMG
#define DEF_FIREARM_SMG

#include "items/firearms/Firearm.hpp"

class Firearm_smg : public Firearm {


    public: 

        /** @brief Construct a new Weapon object */
        Firearm_smg() {};

        /**
         * @brief Construct a new Firearm_smg object
         * 
         * @param pos position of the object 
         */
        Firearm_smg(const sf::Vector2f& pos);

        /** @brief Destroy the Firearm_smg object */
        virtual ~Firearm_smg() {};


    private: 

        /**
         * @brief Initialise weapon's properties
         * 
         * @param pos initial position
         */
        void InitAttributs(const sf::Vector2f& pos) override;

};

#endif // DEF_FIREARM_SMG