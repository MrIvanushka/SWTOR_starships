//
// Created by saladass on 22/04/22.
//

#ifndef SWTOR_TURRETAIM_H
#define SWTOR_TURRETAIM_H
#include "Turret.h"
class TurretAim:public Component{
private:

    Turret* _model;
    glm::quat targetRotation;

public:
    TurretAim(GameObject* object) : Component(object)
    {}
    void initialize(Turret* model)
    {
        this->_model = model;
    }
    void navigateTarget(Starship* target)
    {
        glm::vec3 targetVelocity = target->getVelocity();
        glm::vec3 targetPosition = target->getPosition();
        this->targetRotation = glm::quat(targetVelocity+targetPosition);
    }
    void update(float deltaTime){
        _model->veer(targetRotation);
    }

};


#endif //SWTOR_TURRETAIM_H
