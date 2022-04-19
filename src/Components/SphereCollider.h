//
// Created by egorich on 17.04.22.
//

#ifndef SWTOR_SPHERECOLLIDER_H
#define SWTOR_SPHERECOLLIDER_H

#include "vector"
#include "Collider.h"

class SphereCollider : public Collider{
private:
    float radius = 0;
public:
    float getRadius() const{return radius;}
    SphereCollider(GameObject* object, bool enabledOnStart) : Collider(object, enabledOnStart) {}
    void initialize(float radius){
        radius = radius;
    }

    void CollisionExecution(Collider* aim){

    }
};

#endif //SWTOR_SPHERECOLLIDER_H
