//
// Created by ivan on 14.04.22.
//

#ifndef SWTOR_BULLET_H
#define SWTOR_BULLET_H

#include "Transformable.h"

class Bullet : public Transformable
{
private:
    float speed = 10;
    float damage;
    glm::vec3 position = glm::vec3(0, 0, 0);
public:
    Bullet(glm::vec3 position, glm::quat orientation);
    void update(float deltaTime) override;
    float getDamage();
};

#endif //SWTOR_BULLET_H
