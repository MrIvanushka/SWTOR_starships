//
// Created by ivan on 12.04.2022.
//

#include "Starship.h"

Starship::Starship(glm::vec3 position, glm::vec3 rotation) : Transformable(position, rotation)
{
    targetRotation = glm::quat(rotation);
}

void Starship::update(float deltaTime)
{
    rotateAt(glm::lerp(getRotation(), targetRotation, rotationSpeed * deltaTime));
    currentSpeed += (engineSpeed - currentSpeed) * acceleration;
    velocity = getFront() * currentSpeed + velocity * acceleration;
    //move(velocity * deltaTime);
}

void Starship::accelerate()
{
    if(engineSpeed < maxSpeed)
        engineSpeed += 0.1f;
}

void Starship::slowDown() {
    if(engineSpeed > 0)
        engineSpeed -= 0.1f;
}

void Starship::veer(glm::quat delta)
{
    this->targetRotation = targetRotation * delta;
}