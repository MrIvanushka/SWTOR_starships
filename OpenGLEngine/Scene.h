#pragma once

#include "libs.h"
#include "Camera.h"

class Scene
{
protected:
	std::vector<Shader*> shaders;
	std::vector<Texture*> textures;
	std::vector<Material*> materials;
	Model* skybox;
	std::vector<Model*> models;
	std::vector<PointLight*> pointLights;
	void initialize(int GL_VERSION_MAJOR, int GL_VERSION_MINOR, const glm::mat4& ViewMatrix, const glm::mat4& ProjectionMatrix);
private:
	virtual void initShaders(int GL_VERSION_MAJOR, int GL_VERSION_MINOR) = 0;
	virtual void initTextures() = 0;
	virtual void initMaterials() = 0;
	virtual void initModels() = 0;
	virtual void initPointLights() = 0;
	void initUniforms(const glm::mat4& ViewMatrix, const glm::mat4& ProjectionMatrix);
public:
	~Scene();
	void updateUniforms(const glm::mat4& ViewMatrix, const glm::mat4& ProjectionMatrix, const glm::vec3 cameraPos);
	void update(float deltaTime);
	void render();
};