/**
 * @file main.cpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief 
 * @date 2024-01-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Game.hpp"


int main () {

    Game* game = Game::Instantiate();
    delete game;

    return 0;
}