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
        glm::vec2 mouseOffset = mousePos - lastMousePos;
        lastMousePos =  mousePos;

        glm::quat xQuaternion = glm::angleAxis(mouseOffset.x, glm::vec3(0, 1, 0));
        glm::quat yQuaternion = glm::angleAxis(mouseOffset.y, glm::cross(model->getFront(), glm::vec3(0, 1, 0)));

        this->model->veer(xQuaternion * yQuaternion);

        if(Input::getInstance()->keyIsPressed("W"))
            this->model->accelerate();
        else if(Input::getInstance()->keyIsPressed("S"))
            this->model->slowDown();

        if(Input::getInstance()->keyIsPressed("D"))
            this->model->bendRight();
        if(Input::getInstance()->keyIsPressed("A"))
            this->model->bendLeft();
    }
};

#endif //SWTOR_SHIPMOVEMENTCONTROLLER_H
