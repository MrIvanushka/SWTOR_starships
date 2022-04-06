#pragma once

#include "libs.h"
#include "Camera.h"

class Scene
{
	std::vector<Shader*> shaders;
	std::vector<Texture*> textures;
	std::vector<Material*> materials;
	Model* skybox;
	std::vector<Model*> models;
	std::vector<PointLight*> pointLights;

	void initShaders(int GL_VERSION_MAJOR, int GL_VERSION_MINOR);
	void initTextures();
	void initMaterials();
	void initModels();
	void initPointLights();
	void initUniforms(const glm::mat4& ViewMatrix, const glm::mat4& ProjectionMatrix);
public:
	Scene();
	Scene(int GL_VERSION_MAJOR, int GL_VERSION_MINOR, const glm::mat4& ViewMatrix, const glm::mat4& ProjectionMatrix);
	~Scene();
	void updateUniforms(const glm::mat4& ViewMatrix, const glm::mat4& ProjectionMatrix, const glm::vec3 cameraPos);
	void update(float deltaTime);
	void render();
};