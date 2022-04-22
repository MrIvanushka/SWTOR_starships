//
// Created by ivan on 18.04.22.
//

#ifndef SWTOR_PLAYERSHOOTINGCONTROLLER_H
#define SWTOR_PLAYERSHOOTINGCONTROLLER_H

#include "../Engine/GameObject.h"
#include "../Engine/Input.h"
#include "../Model/Weapon.h"

class PlayerShootingController : public Component
{
private:
    Weapon* model;
public:
    PlayerShootingController(GameObject* object) : Component(object)
    {}

    void initialize(Weapon* model)
    {
        this->model = model;
    }

    void update(float deltaTime) override
    {
        model->update(deltaTime);

        if(Input::getInstance()->keyIsPressed("LM"))
            model->shoot();
    }
};

#endif //SWTOR_PLAYERSHOOTINGCONTROLLER_H
