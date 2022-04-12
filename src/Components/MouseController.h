//
// Created by ivan on 11.04.2022.
//

#ifndef SWTOR_MOUSECONTROLLER_H
#define SWTOR_MOUSECONTROLLER_H

#include "../Engine/GameObject.h"
#include "../Engine/Input.h"

class MouseController : public Component
{
private:
    glm::vec2 oldPos;
    float rotationSpeed = 0.1;
public:
    MouseController(GameObject* object) : Component(object)
    {
        oldPos = glm::vec2(0.5f, 0.5f);
    }

    void update(float deltaTime) override
    {

        if(Input::getInstance()->keyIsPressed("A"))
            gameObject->rotate(glm::vec3(0, 0.01,0));
    }
};

#endif //SWTOR_MOUSECONTROLLER_H
