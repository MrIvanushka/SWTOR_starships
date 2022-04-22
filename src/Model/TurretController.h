#ifndef SWTOR_TURRETCONTROLLER_H
#define SWTOR_TURRETCONTROLLER_H

#include "../Model/Weapon.h"
#include "../Model/TurretAim.h"
#include "../Model/Army.h"
class TurretController : public IUpdatable
{
private:
    Weapon* _weapon;
    TurretAim* _model;
    Starship* _currentTarget;
    bool _hasTarget = false;
    float _estimatedTime;
    float _newTargetTime;
public:

    void initialize(Weapon* model)
    {
        this->_weapon = model;
    }

    void update(float deltaTime) override
    {
        _model->navigateTarget(this->_currentTarget);
        _weapon->update(deltaTime);
        if(this->_hasTarget == true) {
            _weapon->shoot();
        }
        else this->_estimatedTime += deltaTime;
    }

    void allocateTarget(Army* enemyArmy){
        for (int i =0;i<n;i++){
            if (enemyArmy
        }

    }
};
#endif

