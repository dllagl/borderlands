/**
 * @file Weapon.cpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief 
 * @date 2024-02-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Weapon.hpp"

////////////////////////////////////
// static members 
////////////////////////////////////

const float Weapon::width_  = 15.f;
const float Weapon::height_ = 25.f;


////////////////////////////////////
// ctors / dtor 
////////////////////////////////////

Weapon::Weapon(const sf::Vector2f& pos) {
    InitAttributs(pos);
}

Weapon::~Weapon() {
    for (Bullet* b : bullets_) { delete b; }
}



////////////////////////////////////
// methods
////////////////////////////////////

void Weapon::InitAttributs(const sf::Vector2f& pos) {

    shape_ = sf::RectangleShape();
    shape_.setSize(sf::Vector2f(width_,height_));

    /**
     * The origin of the weapon is set to the geometrical center 
     * of the player in order to rotate around its axis.
     */
    offsetOriginFromPlayerCenter_ = sf::Vector2f(-8.f, 30.f);
    shape_.setOrigin(offsetOriginFromPlayerCenter_);
    shape_.setPosition(pos);
    shape_.setFillColor(sf::Color::Red);

    // bullets
    fireRate_ = 5.f;
    bulletVelocity_ = 0.1f;
}

void Weapon::Update(const sf::Vector2f& pos, const float rotation, sf::Vector2f& aimingDirection) {

    // movements and rotations are updated following main player's body's
    shape_.setPosition(pos);
    shape_.setRotation(rotation);

    // weapon
    Shoot(aimingDirection);

    // bullets
    if (bullets_.size() != 0)
        for (Bullet* b : bullets_) { b->Update(bulletVelocity_); }
}

void Weapon::Render(sf::RenderWindow* window) {

    // weapon 
    window->draw(shape_);

    // bullets
    if (bullets_.size() != 0)
        for (Bullet* b : bullets_) { b->Render(window); }
}

void Weapon::Shoot(sf::Vector2f& direction) {

    static auto lastShotFired = std::chrono::steady_clock::now();

    auto currentTime = std::chrono::steady_clock::now();

    // compute time since shot was fired 
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(
        currentTime - lastShotFired
        ).count() / 1000.0;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) 
        && (elapsedTime >= 1.f/fireRate_) ) {

        // normalize aiming direction vector 
        direction /= static_cast<float>(sqrt(pow(direction.x,2) + pow(direction.y,2)));

        // spawn bullet and move it 
        bullets_.push_back(new Bullet(shape_.getPosition(), direction));

        lastShotFired = currentTime;
    }
}