#ifndef SWTOR_TURRET_H
#define SWTOR_TURRET_H

#include "Transformable.h"


class Turret : public Transformable
{
private:
    float rotationSpeed = 1.f;
    glm::quat targetRotation;
public:
    Turret(glm::vec3 position, glm::vec3 rotation);
    void update(float deltaTime) override;
    void veer(glm::quat delta);
};

#endif