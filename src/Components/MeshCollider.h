//
// Created by egorich on 19.04.22.
//

#ifndef SWTOR_MESHCOLLIDER_H
#define SWTOR_MESHCOLLIDER_H

#include "vector"
#include "Collider.h"
#include "../Engine/Mesh.h"

class MeshCollider : public Collider{
private:
    Mesh* mesh;
public:
    Mesh* getMesh() const{return mesh;}
    MeshCollider(GameObject* object, bool enabledOnStart) : Collider(object, enabledOnStart) {}
    void initialize(Mesh* mesh){
        this->mesh = mesh;
    }
    void CollisionExecution(Collider* aim){

    }
};

#endif //SWTOR_MESHCOLLIDER_H
