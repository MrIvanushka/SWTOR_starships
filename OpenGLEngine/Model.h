#pragma once

#include"Mesh.h"
#include"Texture.h"
#include"Shader.h"
#include"Material.h"
#include"OBJLoader.h"
#include "GameObject.h"
#include "MeshRenderer.h"

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
		const char* objFile
	)
	{
		std::vector<Vertex> mesh = loadOBJ(objFile);
		this->meshes.push_back(new MeshRenderer(new Mesh(mesh.data(), mesh.size(), NULL, 0, gameObject, glm::vec3(scale)),
			material, shader, orTexDif, orTexSpec));
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