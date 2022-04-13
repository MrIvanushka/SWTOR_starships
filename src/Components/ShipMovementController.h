//
// Created by ivan on 11.04.2022.
//

#ifndef SWTOR_SHIPMOVEMENTCONTROLLER_H
#define SWTOR_SHIPMOVEMENTCONTROLLER_H

#include "../Engine/GameObject.h"
#include "../Engine/Input.h"
#include "../Model/Starship.h"

class ShipMovementController : public Component
{
private:
    Starship* model;
    glm::vec2 lastMousePos;

    void clamp(float* angle, float min, float max)
    {
        if(*angle < min)
            *angle += min;
        if(*angle > max)
            *angle += max;
    }
public:
    ShipMovementController(GameObject* object) : Component(object)
    {
        lastMousePos = glm::vec2(0.5f, 0.5f);
    }

    void initialize(Starship* model)
    {
        this->model = model;
    }

    void update(float deltaTime) override
    {
        glm::vec2 mousePos = Input::getInstance()->getMousePosition();
        clamp(&mousePos.x, -360, 360);
        clamp(&mousePos.y, -360, 360);
        glm::vec2 mouseOffset = mousePos - lastMousePos;
        lastMousePos =  mousePos;

        glm::quat xQuaternion = glm::angleAxis(mouseOffset.x, glm::vec3(0, -1, 0));
        glm::quat yQuaternion = glm::angleAxis(mouseOffset.y, glm::vec3(0, 0, -1));

        this->model->veer(xQuaternion * yQuaternion);
    }
};

#endif //SWTOR_SHIPMOVEMENTCONTROLLER_H
