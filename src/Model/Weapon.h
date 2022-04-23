//
// Created by ivan on 15.04.22.
//

#ifndef SWTOR_WEAPON_H
#define SWTOR_WEAPON_H

#include "Bullet.h"
#include "Observer.h"

class Weapon : public ArgObservable<Bullet*>, IUpdatable
{
private:
    float reloadingDuration = 0.3f;
    float currentTime = 1;
    Transformable* shooter;
    glm::vec3 weaponOffset;
    glm::quat shootingOrientation;
public:
    Weapon(Transformable* shooter, glm::vec3 offset, glm::quat orientation);
    void update(float deltaTime) override;
    void shoot();
    virtual bool canShoot();
};

#endif //SWTOR_WEAPON_H
