//
// Created by egorich on 16.04.22.
//

#include "CollisionDetector.h"
#include "../../glm/glm/gtx/intersect.hpp"

float eps = 1E-5;

bool CollisionDetector::IntersectTriangleWithNormal(const std::vector<Vertex>& verts, glm::vec3 normal, glm::vec3 point) {

    // Getting triangle
    std::vector<Vertex> triangle = {};
    for (const auto & vert : verts){
        if (glm::length(vert.normal - normal) < eps){
            triangle.emplace_back(vert);
        }
    }

    glm::vec2 a;
    float dist;
    return glm::intersectRayTriangle(point,
                                     (normal * (-1.f)),
                                     triangle[0].position,
                                     triangle[1].position,
                                     triangle[2].position,
                                     a,
                                     dist);
}

// Method returns the distance between the center of a SphereCollider and the closest point of collision model
// dist < radius => collision
float CollisionDetector::Distance(Collider *first, Collider *second) {
    auto* Sphere1 = dynamic_cast<SphereCollider*>(first);
    auto* Sphere2 = dynamic_cast<SphereCollider*>(second);
    auto* Mesh1 = dynamic_cast<MeshCollider*>(first);
    auto* Mesh2 = dynamic_cast<MeshCollider*>(second);

    // ==========Sphere1 and Sphere2==========
    if (Sphere1 != nullptr and Sphere2 != nullptr){
//        std::cout << "\nTwo Spheres : " << glm::length(Sphere1->getObject()->getPosition() -
//        Sphere2->getObject()->getPosition());
        return glm::length(Sphere1->getObject()->getPosition() - Sphere2->getObject()->getPosition());
    }

    // ==========Sphere1 and Mesh2==========
    else if (Sphere1 != nullptr and Mesh2 != nullptr){
        float min = 99999999999.;
        Vertex* closest = nullptr;
        std::vector<Vertex*> Vertexes = {};

        // Searching for closest vertex
        for (int i = 0; i < Mesh2->get_vertexArray().size(); ++i){

            float current_length = glm::length(Sphere1->getObject()->getPosition()
                    - (Mesh2->get_vertexArray()[i]).position);

            if (current_length < min){
                min = current_length;
                closest = &Mesh2->get_vertexArray()[i];
            }
        }

        // Searching for all normals for this position
        for (int i = 0; i < Mesh2->get_vertexArray().size(); ++i){
            if (glm::length(Mesh2->get_vertexArray()[i].position - closest->position) < eps){
                Vertexes.push_back(&Mesh2->get_vertexArray()[i]);
            }
        }

        // Searching for triangles for these normals and checking for intersection
        for (int i = 0; i < Vertexes.size(); ++i){
            std::vector<Vertex*> tmp_Triangle = {};
            for (int j = 0; j < Mesh2->get_vertexArray().size(); ++j){
                if (glm::length(Vertexes[i]->normal - Mesh2->get_vertexArray()[j].normal) < eps){
                    tmp_Triangle.push_back(&Mesh2->get_vertexArray()[j]);
                }
            }
            if (!IntersectTriangleWithNormal(Mesh2->get_vertexArray(), Vertexes[i]->normal, Sphere1->getObject()->getPosition())){
                Vertexes.erase(Vertexes.begin() + i);
            }
        }

        // In case if no intersection occurs, return distance between SphereCenter and closest vertex
        if (Vertexes.empty()){
            return glm::length(Sphere1->getObject()->getPosition() - closest->position);
        }

        // Else searching for the lowest distance
        else{
            min = 999999999.;
            for (auto vertex : Vertexes) {
                float dist = std::abs(glm::dot(vertex->position - Sphere1->getObject()->getPosition(), vertex->normal));
//                std::cout << dist << "; \n";
                if (dist < min) {
                    min = dist;
                }
            }
        }
//        std::cout << " \nSphere1 and Mesh2 - " << min << '\n';
        return min;
    }

    // ==========Sphere2 and Mesh1==========
    else if (Sphere2 != nullptr and Mesh1 != nullptr){
        float min = 99999999999.;
        Vertex* closest = nullptr;
        std::vector<Vertex*> Vertexes = {};

        // Searching for closest vertex
        for (int i = 0; i < Mesh1->get_vertexArray().size(); ++i){

            float current_length = glm::length(Sphere2->getObject()->getPosition()
                                               - (Mesh1->get_vertexArray()[i]).position);

            if (current_length < min){
                min = current_length;
                closest = &Mesh1->get_vertexArray()[i];
            }
        }

        // Searching for all normals for this position
        for (int i = 0; i < Mesh1->get_vertexArray().size(); ++i){
            if (glm::length(Mesh1->get_vertexArray()[i].position - closest->position) < eps){
                Vertexes.push_back(&Mesh1->get_vertexArray()[i]);
            }
        }

        // Searching for triangles for these normals and checking for intersection
        for (int i = 0; i < Vertexes.size(); ++i){
            std::vector<Vertex*> tmp_Triangle = {};
            for (int j = 0; j < Mesh1->get_vertexArray().size(); ++j){
                if (glm::length(Vertexes[i]->normal - Mesh1->get_vertexArray()[j].normal) < eps){
                    tmp_Triangle.push_back(&Mesh1->get_vertexArray()[j]);
                }
            }
            if (!IntersectTriangleWithNormal(Mesh1->get_vertexArray(), Vertexes[i]->normal, Sphere2->getObject()->getPosition())){
                Vertexes.erase(Vertexes.begin() + i);
            }
        }

        // In case if no intersection occurs, return distance between SphereCenter and closest vertex
        if (Vertexes.empty()){
            return glm::length(Sphere2->getObject()->getPosition() - closest->position);
        }

            // Else searching for the lowest distance
        else{
            min = 999999999.;
            for (auto vertex : Vertexes) {
                float dist = std::abs(glm::dot(vertex->position - Sphere2->getObject()->getPosition(), vertex->normal));
//                std::cout << dist << "; \n";
                if (dist < min) {
                    min = dist;
                }
            }
        }
//        std::cout << " Sphere2 and Mesh1 -> " << min << '\n';
        return min;
    }

    // Mesh1 and Mesh2
    else if (Mesh1 != nullptr and Mesh2 != nullptr){
        std::cout << glm::length(Mesh1->getObject()->getPosition() - Mesh2->getObject()->getPosition());
        return glm::length(Mesh1->getObject()->getPosition() - Mesh2->getObject()->getPosition());
    }
    return 0;
}

void CollisionDetector::CollisionProcessing(Collider* first, Collider* second){
    if (first != nullptr and second != nullptr){

        float distance = Distance(first, second);
        auto* Sphere1 = dynamic_cast<SphereCollider*>(first);
        auto* Sphere2 = dynamic_cast<SphereCollider*>(second);

        if (Sphere1 != nullptr and Sphere2 != nullptr){
            if (distance < Sphere1->getRadius() + Sphere2->getRadius()){
                Sphere1->CollisionExecution(Sphere2);
                Sphere2->CollisionExecution(Sphere1);
            }
        }

        else if (Sphere1 != nullptr){
            if (distance < Sphere1->getRadius()){
                Sphere1->CollisionExecution(second);
                second->CollisionExecution(Sphere1);
            }
        }

        else if (Sphere2 != nullptr){
            if (distance < Sphere2->getRadius() and std::abs(distance - 0.237693) >= 1E-3){
                Sphere2->CollisionExecution(first);
                first->CollisionExecution(Sphere2);
            }
        }
    }
}


void CollisionDetector::update(){
    for (int i = 0; i < Colliders.size(); ++i){
        for (int j = i + 1; j < Colliders.size(); ++j){
            if (Colliders[j] != Colliders[i]){

                CollisionProcessing(Colliders[i], Colliders[j]);

            }
        }
    }
}


