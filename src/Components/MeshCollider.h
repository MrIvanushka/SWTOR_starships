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

    void initialize(std::vector<Vertex> vertexes, float scale, glm::vec3 rotation){
        auto quaternion = this->getObject()->getRotation();
        for (auto& vertex : vertexes){
            vertex.position *= scale;
//            vertex.position = vertex.position * quaternion;
            vertex.position += this->getObject()->getPosition();
        }
        this->Vertexes = std::move(vertexes);
    }

    void CollisionExecution(Collider* aim) override{
        std::cout << "Collision from Mesh\n";
    }
};

#endif //SWTOR_MESHCOLLIDER_H
