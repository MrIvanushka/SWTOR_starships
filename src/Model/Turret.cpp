//
// Created by ivan on 12.04.2022.
//

#include "Turret.h"
Turret::Turret(glm::vec3 position, glm::vec3 rotation) : Transformable(position, rotation)
{
    targetRotation = glm::quat(rotation);
}

void Turret::update(float deltaTime)
{
    rotateAt(glm::mix(getRotation(), targetRotation, rotationSpeed * deltaTime));
}

void Turret::veer(glm::quat delta)
{
    this->targetRotation = glm::normalize(targetRotation * delta);
}
