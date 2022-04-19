//
// Created by egorich on 16.04.22.
//

#ifndef SWTOR_COLLISIONDETECTOR_H
#define SWTOR_COLLISIONDETECTOR_H

#include <utility>

#include "vector"
#include "../Components/Collider.h"

#include "../Components/SphereCollider.h"
#include "../Components/MeshCollider.h"


class CollisionDetector {
public:
    CollisionDetector() = default;
    void initialize(std::vector<Collider*> colliders){
        Colliders = std::move(colliders);
    }
    void update();
private:
    std::vector<Collider*> Colliders;
    void CollisionProcessing(Collider* first, Collider* second);

};


#endif //SWTOR_COLLISIONDETECTOR_H
