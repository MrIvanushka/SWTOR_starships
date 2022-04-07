#pragma once

#include "Scene.h"

class SpaceScene : public Scene
{
	void initShaders(int GL_VERSION_MAJOR, int GL_VERSION_MINOR) override;
	void initTextures() override;
	void initMaterials() override;
	void initModels() override;
	void initPointLights() override;
public:
	SpaceScene(int GL_VERSION_MAJOR, int GL_VERSION_MINOR, const glm::mat4& ViewMatrix, const glm::mat4& ProjectionMatrix);
};
