#include "GameObject.h"

GameObject::GameObject(glm::vec3 position, glm::vec3 rotation)
{
	this->position = position;
	this->rotation = rotation;
}
GameObject::~GameObject()
{
	for (Component* component : components)
	{
		delete component;
	}
}

void GameObject::update(float deltaTime)
{
	for (Component* component : this->components)
	{
		if(component->enabled)
			component->update(deltaTime);
	}
}

void GameObject::move(glm::vec3 delta)
{
	for (GameObject* child : this->children)
	{
		child->move(delta);
	}
	this->position += delta;
}

void GameObject::rotate(glm::vec3 delta)
{
	for (GameObject* child : this->children)
	{
		child->rotate(delta);
		//+rotate around center point
	}
}

void GameObject::addChild(GameObject* newChild)
{
	this->children.insert(newChild);
}

void GameObject::removeChild(GameObject* newChild)
{
	this->children.erase(newChild);
}