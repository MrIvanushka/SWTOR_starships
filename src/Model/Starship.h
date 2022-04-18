//
// Created by ivan on 12.04.2022.
//

#ifndef SWTOR_STARSHIP_H
#define SWTOR_STARSHIP_H

#include "Transformable.h"


class Starship : public Transformable
{
private:
    float maxSpeed = 10;
    float currentSpeed = 0;
    float engineSpeed = 0;
    float acceleration = 0.01;
    float rotationSpeed = 1.f / maxSpeed;
    float normalizingSpeed = 0.5f;
    glm::vec3 velocity = glm::vec3(0, 0, 0);
    glm::quat targetRotation;

    void normalize(float deltaTie);
    void moveForward(float deltaTie);
public:
    Starship(glm::vec3 position, glm::vec3 rotation);
    void update(float deltaTime) override;
    void accelerate();
    void slowDown();
    void veer(glm::quat delta);
    void bendRight();
    void bendLeft();
};

#endif //SWTOR_STARSHIP_H
