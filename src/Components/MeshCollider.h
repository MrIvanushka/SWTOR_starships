//
// Created by egorich on 19.04.22.
//

#ifndef SWTOR_MESHCOLLIDER_H
#define SWTOR_MESHCOLLIDER_H

#include "vector"
#include "Collider.h"

#include <utility>
#include "../Engine/Mesh.h"

class MeshCollider : public Collider{
private:
    std::vector<Vertex> Vertexes{};
public:
    std::vector<Vertex> get_vertexArray() const{return Vertexes;}

    MeshCollider(GameObject* object) : Collider(object) {}

    void initialize(std::vector<Vertex> vertexes){
        this->Vertexes = std::move(vertexes);
    }
    void CollisionExecution(Collider* aim){
        std::cout << "Collision from Mesh\n";
    }

};

#endif //SWTOR_MESHCOLLIDER_H
