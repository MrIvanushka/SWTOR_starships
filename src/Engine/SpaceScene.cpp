//
// Created by ivan on 10.04.2022.
//

#include "SpaceScene.h"

SpaceScene::SpaceScene(int GL_VERSION_MAJOR, int GL_VERSION_MINOR, const glm::mat4& ViewMatrix, const glm::mat4& ProjectionMatrix)
{
    this->initialize(GL_VERSION_MAJOR, GL_VERSION_MINOR, ViewMatrix, ProjectionMatrix);
}

void SpaceScene::initShaders(int GL_VERSION_MAJOR, int GL_VERSION_MINOR)
{
    this->shaders.push_back(new Shader(GL_VERSION_MAJOR, GL_VERSION_MINOR,
                                       "../Shaders/vertex_core.glsl", "../Shaders/fragment_directional.glsl"));
    this->shaders.push_back(new Shader(GL_VERSION_MAJOR, GL_VERSION_MINOR,
                                       "../Shaders/vertex_unlit.glsl", "../Shaders/fragment_unlit.glsl"));
}

void SpaceScene::initTextures()
{
    //TEXTURE 0
    this->textures.push_back(new Texture("../Images/pusheen.png", GL_TEXTURE_2D));
    this->textures.push_back(new Texture("../Images/pusheen_specular.png", GL_TEXTURE_2D));

    //TEXTURE 1
    this->textures.push_back(new Texture("../Images/panels01_d.png", GL_TEXTURE_2D));
    this->textures.push_back(new Texture("../Images/panels01_n.png", GL_TEXTURE_2D));

    this->textures.push_back(new Texture("../Images/skybox.png", GL_TEXTURE_2D));
}

void SpaceScene::initMaterials()
{
    this->materials.push_back(new Material(glm::vec3(0.1f), glm::vec3(1.f), glm::vec3(1.f),
                                           0, 1));
}

void SpaceScene::initObjects()
{
    GameObject* skybox = new GameObject(glm::vec3(2.f, 0.f, 2.f), glm::vec3(180.f, 0.f, 0.f));
    skybox->addComponent<Model>();
    skybox->getComponent<Model>()->initialize(5.f,  this->materials[0], this->shaders[1], this->textures[4], this->textures[0], "../OBJFiles/skybox.obj");
    this->gameObjects.push_back(skybox);

    GameObject* harrower = new GameObject(glm::vec3(-3.f, 0.f, 20.f), glm::vec3(0.f, 0.f, 0.f));
    harrower->addComponent<Model>();
    harrower->getComponent<Model>()->initialize(0.2f, this->materials[0], this->shaders[0], this->textures[2], this->textures[3], "../OBJFiles/Harrower.obj");
    this->gameObjects.push_back(harrower);

    GameObject* valor = new GameObject(glm::vec3(3.f, 0.f, -10.f), glm::vec3(0.f, 60.f, 0.f));
    valor->addComponent<Model>();
    valor->getComponent<Model>()->initialize(0.4f, this->materials[0], this->shaders[0], this->textures[2], this->textures[3], "../OBJFiles/Valor.obj");
    this->gameObjects.push_back(valor);
}

void SpaceScene::initPointLights()
{
    this->pointLights.push_back(new PointLight(glm::vec3(-50.f, 50.f, 50.f)));
}
