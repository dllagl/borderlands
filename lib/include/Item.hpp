/**
 * @file Item.hpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief Abstract class for inventory objects (grenade, shield, firearms)
 * @date 2024-03-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef ITEM_HPP
#define ITEM_HPP

#include <memory>
#include <chrono>
#include <vector>

#include "GAME_CONF.hpp"

class Item {

    public: 

        Item() {};
        virtual ~Item() {};

};

#endif // ITEM_HPP