//
// Created by ivan on 13.04.2022.
//

#ifndef SWTOR_PRESENTER_H
#define SWTOR_PRESENTER_H

#include "../Engine/GameObject.h"
#include "../Model/Transformable.h"
#include "../Model/IUpdatable.h"

class Presenter : public Component
{
private:
    Transformable* model;
public:
    Presenter(GameObject* object) : Component(object)
    {}

    ~Presenter()
    {
        delete model;
    }

    void initialize(Transformable* model)
    {
        this->model = model;
    }

    void update(float deltaTime) override
    {
        model->update(deltaTime);
        gameObject->moveAt(model->getPosition());
        gameObject->rotateAt(model->getRotation());
    }
};

class BulletPresenter : public Presenter
{
public:
    BulletPresenter(GameObject* object) : Presenter(object)
    {}

    void activate(Transformable* model)
    {
        initialize(model);
        gameObject->setActive(true);
    }
};

#endif //SWTOR_PRESENTER_H
