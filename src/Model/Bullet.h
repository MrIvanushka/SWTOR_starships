//
// Created by ivan on 14.04.22.
//

#ifndef SWTOR_BULLET_H
#define SWTOR_BULLET_H

#include "Transformable.h"

class Bullet : public Transformable
{
private:
    float damage;
    glm::vec3 position = glm::vec3(0, 0, 0);
public:
    Bullet(glm::vec3 position, glm::vec3 direction);

    void update(float deltaTime) override;

    void getDamage();
};

#endif //SWTOR_BULLET_H
