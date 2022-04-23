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
    std::vector<Weapon*> models;
public:
    PlayerShootingController(GameObject* object) : Component(object)
    {}

    void insertModel(Weapon* model)
    {
        this->models.push_back(model);
    }

    void update(float deltaTime) override
    {
        for(auto* model : models) {
            model->update(deltaTime);

            if (Input::getInstance()->keyIsPressed("LM"))
                model->shoot();
        }
    }
};

#endif //SWTOR_PLAYERSHOOTINGCONTROLLER_H
