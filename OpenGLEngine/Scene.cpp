#include "Scene.h"
#include "Game.h"

void Scene::initialize(int GL_VERSION_MAJOR, int GL_VERSION_MINOR, const glm::mat4& ViewMatrix, const glm::mat4& ProjectionMatrix)
{
	this->initShaders(GL_VERSION_MAJOR, GL_VERSION_MINOR);
	this->initTextures();
	this->initMaterials();
	this->initObjects();
	this->initPointLights();
	this->initUniforms(ViewMatrix, ProjectionMatrix);
}

Scene::~Scene()
{
	for (size_t i = 0; i < this->shaders.size(); i++)
		delete this->shaders[i];

	for (size_t i = 0; i < this->textures.size(); i++)
		delete this->textures[i];

	for (size_t i = 0; i < this->materials.size(); i++)
		delete this->materials[i];

	for (GameObject* i : this->gameObjects)
		delete i;

	for (size_t i = 0; i < this->pointLights.size(); i++)
		delete this->pointLights[i];
}

void Scene::initUniforms(const glm::mat4& ViewMatrix, const glm::mat4& ProjectionMatrix)
{
	for (Shader * shader : this->shaders)
	{
		shader->setMat4fv(ViewMatrix, "ViewMatrix");
		shader->setMat4fv(ProjectionMatrix, "ProjectionMatrix");

		for each (PointLight * pl in this->pointLights)
		{
			pl->sendToShader(*shader);
		}
	}
}

void Scene::updateUniforms(const glm::mat4& ViewMatrix, const glm::mat4& ProjectionMatrix, const glm::vec3 cameraPos)
{
	for (Shader* shader : this->shaders)
	{
		shader->setMat4fv(ViewMatrix, "ViewMatrix");
		shader->setVec3f(cameraPos, "cameraPos");

		pointLights[0]->sendToShader(*shader);
		for (int j = 0; j < pointLights.size(); j++)
		{
			if (pointLights[j] != nullptr && shader != nullptr)
				pointLights[j]->sendToShader(*shader);
		}
		shader->setMat4fv(ProjectionMatrix, "ProjectionMatrix");
	}
}

void Scene::update(float deltaTime)
{
	for (GameObject* object : this->gameObjects)
	{
		object->update(deltaTime);
	}
}

void Scene::render()
{
	for (GameObject* object : this->gameObjects)
	{
		object->render();
	}
}