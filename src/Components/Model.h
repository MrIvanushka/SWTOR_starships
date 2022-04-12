//
// Created by ivan on 10.04.2022.
//

#ifndef SWTOR_MODEL_H
#define SWTOR_MODEL_H

#include"../Engine/Mesh.h"
#include"../Engine/Texture.h"
#include"../Engine/Shader.h"
#include"../Engine/Material.h"
#include"../Engine/OBJLoader.h"
#include "../Engine/GameObject.h"
#include "../Engine/MeshRenderer.h"

class Model : public Component
{
private:
    std::vector<MeshRenderer*> meshes;
public:
    Model(GameObject* object) : Component(object)
    {}

    void initialize(std::vector<MeshRenderer*> meshes)
    {
        this->meshes = meshes;
    }

    //OBJ file loaded model
    void initialize(
            float scale,
            Material* material,
            Shader* shader,
            Texture* orTexDif,
            Texture* orTexSpec,
            const char* objFile,
            bool allowManyMeshes = false
    ) {
        if (allowManyMeshes == false) {
            std::vector<Vertex> mesh = loadOBJ(objFile);
            this->meshes.push_back(
                    new MeshRenderer(new Mesh(mesh.data(), mesh.size(), NULL, 0, gameObject, glm::vec3(scale)),
                                     material, shader, orTexDif, orTexSpec));
        } else
        {
            std::cout << "start";
            auto meshes = loadOBJwithManyMeshes(objFile);
            //for(auto &mesh : meshes)
            {
                this->meshes.push_back(
                        new MeshRenderer(new Mesh(meshes[0].data(), meshes[0].size(), NULL, 0, gameObject, glm::vec3(scale)),
                                         material, shader, orTexDif, orTexSpec));
            }
        }
    }

    ~Model()
    {
        for (auto*& i : this->meshes)
            delete i;
    }

    void render() override
    {
        for (MeshRenderer* renderer : meshes)
        {
            renderer->render();
        }
    }
};

#endif //SWTOR_MODEL_H
