//
// Created by egorich on 16.04.22.
//

#include "CollisionDetector.h"

void CollisionDetector::CollisionProcessing(Collider* first, Collider* second){
    auto* Sphere1 = dynamic_cast<SphereCollider*>(first);
    auto* Sphere2 = dynamic_cast<SphereCollider*>(second);
    auto* Mesh1 = dynamic_cast<MeshCollider*>(first);
    auto* Mesh2 = dynamic_cast<MeshCollider*>(second);

    if (Sphere1 != nullptr and Sphere2 != nullptr){
        if (glm::length(Sphere1->getObject()->getPosition() - Sphere2->getObject()->getPosition()) <
            Sphere1->getRadius() + Sphere2->getRadius()){
            Sphere1->CollisionExecution(Sphere2);
            Sphere2->CollisionExecution(Sphere1);
        }
    }

    if (Sphere1 != nullptr and Mesh2 != nullptr){
        if (glm::length(Sphere1->getObject()->getPosition() - Sphere2->getObject()->getPosition()) <
            Sphere1->getRadius() + Sphere2->getRadius()){
            Sphere1->CollisionExecution(Mesh2);
            Mesh2->CollisionExecution(Sphere1);
        }
    }

    if (Sphere2 != nullptr and Mesh1 != nullptr){
        if (glm::length(Sphere1->getObject()->getPosition() - Sphere2->getObject()->getPosition()) <
            Sphere1->getRadius() + Sphere2->getRadius()){
            Sphere2->CollisionExecution(Mesh1);
            Mesh1->CollisionExecution(Sphere2);
        }
    }

    if (Mesh1 != nullptr and Mesh2 != nullptr){
        if (glm::length(Sphere1->getObject()->getPosition() - Sphere2->getObject()->getPosition()) <
            Sphere1->getRadius() + Sphere2->getRadius()){
            Mesh1->CollisionExecution(Mesh2);
            Mesh2->CollisionExecution(Mesh1);
        }
    }
}


void CollisionDetector::update(){
    for (auto* collider1 : Colliders){
        for (auto* collider2 : Colliders){
            if (collider1 != collider2){

                CollisionProcessing(collider1, collider2);

            }
        }
    }
}

