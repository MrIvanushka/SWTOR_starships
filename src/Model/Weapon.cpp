//
// Created by ivan on 15.04.22.
//

#include "Weapon.h"

Weapon::Weapon(Transformable *shooter, glm::vec3 offset, glm::quat orientation) :
shooter(shooter), weaponOffset(offset), shootingOrientation(orientation)
{}
void Weapon::shoot()
{
    if(canShoot())
    {
        currentTime = 0;
        Bullet* bullet = new Bullet(shooter->getPosition() + weaponOffset * shooter->getRotation(), shootingOrientation * shooter->getRotation());
        this->invoke(bullet);
    }
}

void Weapon::update(float deltaTime)
{
    currentTime += deltaTime;
}

bool Weapon::canShoot() {
    return currentTime > reloadingDuration;
}