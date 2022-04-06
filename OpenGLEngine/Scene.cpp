#include "Scene.h"
#include "Game.h"

Scene::Scene()
{}
Scene::Scene(int GL_VERSION_MAJOR, int GL_VERSION_MINOR, const glm::mat4& ViewMatrix, const glm::mat4& ProjectionMatrix)
{
	this->initShaders(GL_VERSION_MAJOR, GL_VERSION_MINOR);
	this->initTextures();
	this->initMaterials();
	this->initModels();
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

	for (auto*& i : this->models)
		delete i;

	for (size_t i = 0; i < this->pointLights.size(); i++)
		delete this->pointLights[i];
}

void Scene::initShaders(int GL_VERSION_MAJOR, int GL_VERSION_MINOR)
{
	this->shaders.push_back(new Shader(GL_VERSION_MAJOR, GL_VERSION_MINOR,
		"Shaders/vertex_core.glsl", "Shaders/fragment_directional.glsl"));
	this->shaders.push_back(new Shader(GL_VERSION_MAJOR, GL_VERSION_MINOR,
		"Shaders/vertex_unlit.glsl", "Shaders/fragment_unlit.glsl"));
}

void Scene::initTextures()
{
	//TEXTURE 0
	this->textures.push_back(new Texture("Images/pusheen.png", GL_TEXTURE_2D));
	this->textures.push_back(new Texture("Images/pusheen_specular.png", GL_TEXTURE_2D));

	//TEXTURE 1
	this->textures.push_back(new Texture("Images/panels01_d.png", GL_TEXTURE_2D));
	this->textures.push_back(new Texture("Images/panels01_n.png", GL_TEXTURE_2D));

	this->textures.push_back(new Texture("Images/skybox.png", GL_TEXTURE_2D));
}

void Scene::initMaterials()
{
	this->materials.push_back(new Material(glm::vec3(0.1f), glm::vec3(1.f), glm::vec3(1.f),
		0, 1));
}

void Scene::initModels()
{
	this->skybox = new Model(
		glm::vec3(2.f, 0.f, 2.f), glm::vec3(180.f, 0.f, 0.f), 5,
		this->materials[0],
		this->textures[4],
		this->textures[TEX_CONTAINER_SPECULAR],
		"OBJFiles/skybox.obj"
	);


	this->models.push_back(new Model(
		glm::vec3(-3.f, 0.f, 20.f), glm::vec3(0.f, 0.f, 0.f), 0.2,
		this->materials[0],
		this->textures[TEX_CONTAINER],
		this->textures[TEX_CONTAINER_SPECULAR],
		"OBJFiles/Harrower.obj"
	)
	);

	this->models.push_back(new Model(
		glm::vec3(3.f, 0.f, -10.f), glm::vec3(0.f, 60.f, 0.f), 0.4,
		this->materials[0],
		this->textures[TEX_CONTAINER],
		this->textures[TEX_CONTAINER_SPECULAR],
		"OBJFiles/Valor.obj"
	)
	);
}

void Scene::initPointLights()
{
	this->pointLights.push_back(new PointLight(glm::vec3(-50.f, 50.f, 50.f)));
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

}

void Scene::render()
{
	skybox->render(this->shaders[1]);
	//Render models
	for (auto& i : this->models)
		i->render(this->shaders[SHADER_CORE_PROGRAM]);
}