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
}



////////////////////////////////////
// methods
////////////////////////////////////

void Weapon::InitAttributs(const sf::Vector2f& pos) {

    // body
    shape_ = std::make_unique<sf::RectangleShape>();
    shape_->setSize(sf::Vector2f(width_,height_));

    /**
     * The origin of the weapon is set to the geometrical center 
     * of the player in order to rotate around its axis.
     */
    offsetOriginFromPlayerCenter_ = sf::Vector2f(-8.f, 30.f);
    shape_->setOrigin(offsetOriginFromPlayerCenter_);
    shape_->setPosition(pos);
    shape_->setFillColor(sf::Color::Red);

    // ammunitions
    maxAmmo_ = 100;
    clipSize_ = 21;
    currentAmmoInClip_ = clipSize_;
    currentAmmoLeft_ = maxAmmo_ - currentAmmoInClip_;

    // bullets
    fireRate_ = 5.f;
    fireRange_ = 200.f;
    bulletVelocity_ = 500.f;
}



void Weapon::Update(
    const sf::Vector2f& pos,
    const float rotation,
    sf::Vector2f& aimingDirection,
    const sf::Time& timeSinceLastFrame
    ) {

    // movements and rotations are updated following main player's body's
    shape_->setPosition(pos);
    shape_->setRotation(rotation);

    // weapon
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (currentAmmoInClip_ != 0)) {
        Shoot(aimingDirection);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && (currentAmmoLeft_ != 0)) {
        Reload();
    }

    // bullets
    if (!bullets_.empty()) {
        std::vector<std::unique_ptr<Bullet>>::iterator it = bullets_.begin();
        while (it != bullets_.end()) {
            (*it)->Update(bulletVelocity_, timeSinceLastFrame, fireRange_);

            if ((*it)->getHasReachedMaxDistance()) {
                it = bullets_.erase(it); // empty vector case and resize it
            } else {
                ++it;
            }
        }
    }  
}



void Weapon::Render(const std::unique_ptr<sf::RenderWindow>& window) {

    // weapon 
    window->draw(*shape_);

    // bullets
    if (!bullets_.empty())
        for (const auto& b : bullets_) { b->Render(window); }
}



void Weapon::Shoot(sf::Vector2f& direction) {

    static auto lastShotFired = std::chrono::steady_clock::now();

    auto currentTime = std::chrono::steady_clock::now();

    // compute time since shot was fired 
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(
        currentTime - lastShotFired
        ).count() / 1000.0;

    if ( elapsedTime >= 1.f/fireRate_ ) {

        // normalize aiming direction vector 
        direction /= static_cast<float>(sqrt(pow(direction.x,2) + pow(direction.y,2)));

        // spawn bullet and move it 
        bullets_.push_back(
            std::make_unique<Bullet>(
                shape_->getPosition(),
                offsetOriginFromPlayerCenter_,
                shape_->getRotation(),
                direction,
                width_
                )
            );

        currentAmmoInClip_--; // decrease remaining ammo in clip

        lastShotFired = currentTime;
    }       
}



void Weapon::Reload() {

    // number of ammo required to refill the clip
    const uint16_t ammoToReload = clipSize_ - currentAmmoInClip_;

    if (ammoToReload <= currentAmmoLeft_) {
        // reload to full capacity 
        currentAmmoInClip_ += ammoToReload;
        currentAmmoLeft_ -= ammoToReload;
    } else {
        // reload with the total remaining of bullets
        currentAmmoInClip_ += currentAmmoLeft_;
        currentAmmoLeft_ = 0;
    }
        
}