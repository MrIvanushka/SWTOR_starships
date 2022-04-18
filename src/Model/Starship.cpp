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
    rotateAt(glm::mix(getRotation(), targetRotation, currentSpeed * rotationSpeed * deltaTime));
    moveForward(deltaTime);
    normalize(deltaTime);
}

void Starship::normalize(float deltaTime)
{
    float angle = (glm::cross(getFront(),glm::vec3(0.f,1.f,0.f)*getRotation())).y;
    if(angle > 0.05 || angle < -0.05)
        rotate(glm::angleAxis(-normalizingSpeed * deltaTime * currentSpeed * angle, getFront()));
}

void Starship::moveForward(float deltaTime) {
    currentSpeed += (engineSpeed - currentSpeed) * acceleration;
    velocity = getFront() * currentSpeed + velocity * acceleration;
    move( velocity  * deltaTime);
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

void Starship::bendRight() {
    rotate(glm::angleAxis(-0.01f * currentSpeed, getFront()));
}

void Starship::bendLeft() {
    rotate(glm::angleAxis(0.01f * currentSpeed, getFront()));
}