/**
 * @file Firearm.cpp
 * @author Anthony DALL'AGNOL (dllagl@gmx.com)
 * @brief 
 * @date 2024-03-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "items/firearms/Firearm.hpp"

////////////////////////////////////
// methods
////////////////////////////////////


void Firearm::Update(
    const sf::Vector2f& pos,
    const float rotation,
    sf::Vector2f& aimingDirection,
    const sf::Time& timeSinceLastFrame
    ) {

    // movements and rotations are updated following main player's body's
    shape_->setPosition(pos);
    shape_->setRotation(rotation);

    // weapon
    if (sf::Mouse::isButtonPressed(KEY::WEAPON::SHOOT) && (currentAmmoInClip_ != 0)) {

        /*
        Shoot if: 
        - fire button pressed 
        - AND at least one ammo in the magazine 
        */
        Shoot(aimingDirection);

    } else if (
        sf::Keyboard::isKeyPressed(KEY::WEAPON::RELOAD) 
        && (currentAmmoLeft_ != 0)
        && (currentAmmoInClip_ != magazineSize_) ) {

        /*
        Reload if:
        - reload key pressed 
        - AND at least one available ammo remains 
        - AND the magazine is not already full 
        */
        Reload();
    }

    // bullets
    if (!bullets_.empty()) {
        std::vector<std::unique_ptr<Bullet>>::iterator it = bullets_.begin();
        while (it != bullets_.end()) {
            (*it)->Update(bulletVelocity_, timeSinceLastFrame, fireRange_);

            if ((*it)->getHasReachedMaxDistance()) {
                it = bullets_.erase(it); // empty vector slot and resize it
            } else {
                ++it;
            }
        }
    }  
}




void Firearm::Render(const std::unique_ptr<sf::RenderWindow>& window) const {

    // weapon 
    window->draw(*shape_);

    // bullets
    if (!bullets_.empty())
        for (const auto& b : bullets_) { b->Render(window); }
}



void Firearm::Shoot(sf::Vector2f& direction) {

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



void Firearm::Reload() {

    // number of ammo required to refill the clip
    const uint16_t ammoToReload = magazineSize_ - currentAmmoInClip_;

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