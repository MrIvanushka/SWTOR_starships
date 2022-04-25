//
// Created by d on 4/22/22.
//

#ifndef SWTOR_PASSIVEPRESENTER_H
#define SWTOR_PASSIVEPRESENTER_H


#include "../Engine/GameObject.h"
#include "../Model/Transformable.h"
#include "../Model/IUpdatable.h"
#include "../Model/Turret.h"

class PassivePresenter : public Component
{
private:
    Turret* _model;
public:
    PassivePresenter(GameObject* object) : Component(object)
    {}

    ~PassivePresenter()
    {
        delete _model;
    }

    void initialize(Turret* model)
    {
        this->_model = model;
    }

    void update(float deltaTime) override
    {
        _model->update(deltaTime);
    }
};

#endif //SWTOR_PASSIVEPRESENTER_H
