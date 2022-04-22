//
// Created by ivan on 14.04.22.
//

#include "Bullet.h"

Bullet::Bullet(glm::vec3 position, glm::quat orientation) : Transformable(position, orientation)
{}

void Bullet::update(float deltaTime)
{
    move(getFront() * speed * deltaTime);
}

float Bullet::getDamage()
{
    return damage;
}