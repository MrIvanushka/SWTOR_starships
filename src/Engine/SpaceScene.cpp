//
// Created by ivan on 10.04.2022.
//

#include "SpaceScene.h"
#include "../Components/PlayerMovementController.h"
#include "../Components/PlayerShootingController.h"
#include "../Components/ShootingHandler.h"
#include "../Components/Presenter.h"
#include "../Components/Follower.h"
#include "../Model/Starship.h"
#include"OBJLoader.h"

SpaceScene::SpaceScene(int GL_VERSION_MAJOR, int GL_VERSION_MINOR, int framebufferWidth, int framebufferHeight)
{
    this->initialize(GL_VERSION_MAJOR, GL_VERSION_MINOR, framebufferWidth, framebufferHeight);
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
    this->textures.push_back(new Texture("../Images/skybox.png", GL_TEXTURE_2D));

    this->textures.push_back(new Texture("../Images/Harrower/panels01_d.png", GL_TEXTURE_2D));
    this->textures.push_back(new Texture("../Images/Harrower/panels01_n.png", GL_TEXTURE_2D));

    this->textures.push_back(new Texture("../Images/Harrower/panels02_d.png", GL_TEXTURE_2D));
    this->textures.push_back(new Texture("../Images/Harrower/panels02_n.png", GL_TEXTURE_2D));

    this->textures.push_back(new Texture("../Images/Harrower/panels03_d.png", GL_TEXTURE_2D));
    this->textures.push_back(new Texture("../Images/Harrower/panels03_n.png", GL_TEXTURE_2D));

    this->textures.push_back(new Texture("../Images/Harrower/details01_d.png", GL_TEXTURE_2D));
    this->textures.push_back(new Texture("../Images/Harrower/details01_n.png", GL_TEXTURE_2D));

    this->textures.push_back(new Texture("../Images/Harrower/details02_d.png", GL_TEXTURE_2D));
    this->textures.push_back(new Texture("../Images/Harrower/details02_n.png", GL_TEXTURE_2D));

    this->textures.push_back(new Texture("../Images/Harrower/details03_d.png", GL_TEXTURE_2D));
    this->textures.push_back(new Texture("../Images/Harrower/details03_n.png", GL_TEXTURE_2D));

    this->textures.push_back(new Texture("../Images/Harrower/trims01_d.png", GL_TEXTURE_2D));
    this->textures.push_back(new Texture("../Images/Harrower/trims01_n.png", GL_TEXTURE_2D));

    this->textures.push_back(new Texture("../Images/Valor/veh_rep_capital_ship_detail01_d.png", GL_TEXTURE_2D));
    this->textures.push_back(new Texture("../Images/Valor/veh_rep_capital_ship_detail01_n.png", GL_TEXTURE_2D));

    this->textures.push_back(new Texture("../Images/Valor/veh_rep_capital_ship_detail02_d2.png", GL_TEXTURE_2D));
    this->textures.push_back(new Texture("../Images/Valor/veh_rep_capital_ship_detail02_n.png", GL_TEXTURE_2D));

    this->textures.push_back(new Texture("../Images/Valor/veh_rep_capital_ship_metal_gray_d.png", GL_TEXTURE_2D));
    this->textures.push_back(new Texture("../Images/Valor/veh_rep_capital_ship_metal_gray_n.png", GL_TEXTURE_2D));

    this->textures.push_back(new Texture("../Images/Valor/veh_rep_capital_ship_metal_red_d.png", GL_TEXTURE_2D));
    //this->textures.push_back(new Texture("../Images/Harrower/veh_rep_capital_ship_metal_red_n.png", GL_TEXTURE_2D));

    this->textures.push_back(new Texture("../Images/Valor/veh_rep_capital_ship_metal_white_d.png", GL_TEXTURE_2D));
    this->textures.push_back(new Texture("../Images/Valor/veh_rep_capital_ship_metal_white_n.png", GL_TEXTURE_2D));

    this->textures.push_back(new Texture("../Images/Valor/veh_rep_capital_ship_trims01_d.png", GL_TEXTURE_2D));
    this->textures.push_back(new Texture("../Images/Valor/veh_rep_capital_ship_trims01_d2.png", GL_TEXTURE_2D));

    this->textures.push_back(new Texture("../Images/Valor/veh_rep_capital_ship_trims01_n.png", GL_TEXTURE_2D));

    this->textures.push_back(new Texture("../Images/liberator.png", GL_TEXTURE_2D));

    this->textures.push_back(new Texture("../Images/red.png", GL_TEXTURE_2D));
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
    std::vector<Vertex> mesh = loadOBJ("../OBJFiles/skybox.obj");
    skybox->getComponent<Model>()->addMesh(mesh, 5.f,  this->materials[0], this->shaders[1], this->textures[0], this->textures[0]);
    this->gameObjects.push_back(skybox);

    //position -3 0 20
    GameObject* harrower = new GameObject(glm::vec3(-3.f, 0.f, 20.f), glm::vec3(0.f, 0.f, 0.f));
    harrower->addComponent<Model>();
    mesh = loadOBJ("../OBJFiles/Harrower/Base.obj");
    //scale = 0.2
    harrower->getComponent<Model>()->addMesh(mesh, 0.2f, this->materials[0], this->shaders[0], this->textures[1], this->textures[2]);
    mesh = loadOBJ("../OBJFiles/Harrower/Sides.obj");
    harrower->getComponent<Model>()->addMesh(mesh, 0.2f, this->materials[0], this->shaders[0], this->textures[3], this->textures[4]);
    mesh = loadOBJ("../OBJFiles/Harrower/Details.obj");
    harrower->getComponent<Model>()->addMesh(mesh, 0.2f, this->materials[0], this->shaders[0], this->textures[9], this->textures[10]);
    mesh = loadOBJ("../OBJFiles/Harrower/Ports.obj");
    harrower->getComponent<Model>()->addMesh(mesh, 0.2f, this->materials[0], this->shaders[0], this->textures[13], this->textures[14]);

    harrower->addComponent<MeshCollider>();
    mesh = loadOBJ("../OBJFiles/HarrowerHitbox.obj");
    harrower->getComponent<MeshCollider>()->initialize(mesh, 0.2f, glm::vec3(0.f, 0.f, 0.f));
    this->gameObjects.push_back(harrower);

    GameObject* valor = new GameObject(glm::vec3(3.f, 0.f, -10.f), glm::vec3(0.f, 240.f, 0.f));
    valor->addComponent<Model>();

    auto meshes = loadOBJwithManyMeshes("../OBJFiles/Valor.obj");
    valor->getComponent<Model>()->addMesh(meshes[0], 0.4f, this->materials[0], this->shaders[0], this->textures[15], this->textures[16]);
    valor->getComponent<Model>()->addMesh(meshes[1], 0.4f, this->materials[0], this->shaders[0], this->textures[17], this->textures[18]);
    valor->getComponent<Model>()->addMesh(meshes[2], 0.4f, this->materials[0], this->shaders[0], this->textures[22], this->textures[23]);
    valor->getComponent<Model>()->addMesh(meshes[3], 0.4f, this->materials[0], this->shaders[0], this->textures[25], this->textures[26]);
    valor->getComponent<Model>()->addMesh(meshes[4], 0.4f, this->materials[0], this->shaders[0], this->textures[19], this->textures[20]);
    valor->getComponent<Model>()->addMesh(meshes[5], 0.4f, this->materials[0], this->shaders[0], this->textures[21], this->textures[20]);
    valor->getComponent<Model>()->addMesh(meshes[6], 0.4f, this->materials[0], this->shaders[0], this->textures[15], this->textures[16]);
    std::cout << "SIZE = " << meshes.size() << std::endl;
//    valor->addComponent<SphereCollider>();
//    valor->getComponent<SphereCollider>()->initialize(10);
    this->gameObjects.push_back(valor);

    GameObject* camera = new GameObject(glm::vec3(-10.f, 0.f, 0.f), glm::vec3(0.f, -90.f, 0.f));
    camera->addComponent<Camera>();
    Starship* shipModel = new Starship(glm::vec3(-9.f, 0.05f, 0.f), glm::vec3(0.f, -90.f, 0.f));
    this->renderCamera = camera->getComponent<Camera>();

    //-9.4f, -0.05f, 0.f
    GameObject* liberator = new GameObject(glm::vec3(-9.4f, -0.05f, 0.f), glm::vec3(0.f, 90.f, 0.f));
    liberator->addComponent<Model>();
    mesh = loadOBJ("../OBJFiles/Liberator.obj");
    liberator->getComponent<Model>()->addMesh(mesh, 0.1f, this->materials[0], this->shaders[0], this->textures[27], this->textures[0]);
    liberator->addComponent<PlayerMovementController>();
    liberator->addComponent<Presenter>();
    liberator->getComponent<PlayerMovementController>()->initialize(shipModel);
    liberator->getComponent<Presenter>()->initialize(shipModel);
    liberator->addComponent<ShootingHandler>();

    mesh = loadOBJ("../OBJFiles/Bullet.obj");
    std::queue<BulletPresenter*> bullets;
    for(int i = 0; i < 20; i++)
    {
        GameObject* bullet = new GameObject(glm::vec3(-8.75f, -0.01f, -0.265f), glm::vec3(0.f, 90.f, 0.f));
        bullet->addComponent<Model>();
        bullet->getComponent<Model>()->addMesh(mesh, 0.3f, this->materials[0], this->shaders[1], this->textures[28], this->textures[4]);
        bullet->addComponent<BulletPresenter>();
        bullet->getComponent<BulletPresenter>()->initialize(new Bullet(glm::vec3(-50.f, 50.f, 50.f), glm::vec3(0.f, 0.f, 0.f)));
        bullet->setActive(false);
        bullets.push(bullet->getComponent<BulletPresenter>());
        this->gameObjects.push_back(bullet);
    }
    liberator->getComponent<ShootingHandler>()->initialize(bullets);
    liberator->addComponent<PlayerShootingController>();
    Weapon* liberatorWeapon1 = new Weapon(shipModel, glm::vec3(0.65, -0.2, 0.5), glm::vec3(0, 0, 0));
    Weapon* liberatorWeapon2 = new Weapon(shipModel, glm::vec3(-0.65, -0.2, 0.5), glm::vec3(0, 0, 0));
    liberatorWeapon1->Attach(liberator->getComponent<ShootingHandler>());
    liberatorWeapon2->Attach(liberator->getComponent<ShootingHandler>());
    liberator->getComponent<PlayerShootingController>()->insertModel(liberatorWeapon1);
    liberator->getComponent<PlayerShootingController>()->insertModel(liberatorWeapon2);

    camera->addComponent<Follower>();
    camera->getComponent<Follower>()->initialize(liberator, glm::vec3(0, -0.05, 0.5f));
    liberator->addComponent<SphereCollider>();
    liberator->getComponent<SphereCollider>()->initialize(1);
    this->gameObjects.push_back(liberator);
    this->gameObjects.push_back(camera);


    GameObject* direcionalLight = new GameObject(glm::vec3(-50.f, 50.f, 50.f), glm::vec3(0.f, 0.f, 0.f));
    direcionalLight->addComponent<PointLight>();
    this->pointLights.push_back(direcionalLight->getComponent<PointLight>());
    this->gameObjects.push_back(direcionalLight);
}
