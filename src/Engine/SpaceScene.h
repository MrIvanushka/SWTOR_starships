//
// Created by ivan on 10.04.2022.
//

#ifndef SWTOR_SPACESCENE_H
#define SWTOR_SPACESCENE_H

#include "Scene.h"

class SpaceScene : public Scene
{
    void initShaders(int GL_VERSION_MAJOR, int GL_VERSION_MINOR) override;
    void initTextures() override;
    void initMaterials() override;
    void initObjects() override;
    void initPointLights() override;
public:
    SpaceScene(int GL_VERSION_MAJOR, int GL_VERSION_MINOR, const glm::mat4& ViewMatrix, const glm::mat4& ProjectionMatrix);
};

#endif //SWTOR_SPACESCENE_H