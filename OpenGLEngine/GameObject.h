#pragma once

#include "libs.h"
#include <set>

class Component;

class GameObject
{
	glm::vec3 position;
	glm::vec3 rotation;
	std::set<GameObject*> children;
	std::set<Component*> components;
public:
	GameObject(glm::vec3 position, glm::vec3 rotation);
	~GameObject();
	virtual void update(float deltaTime);
	void move(glm::vec3 delta);
	void rotate(glm::vec3 delta);
	void addChild(GameObject* child);
	void removeChild(GameObject* child);

	template<typename T>
	void addComponent()
	{
		if (this->getComponent<T>() != nullptr)
			throw std::logic_error("GameObject already contains component that you are trying to add.");

		this->components.insert(new T(this));
	}
	template<typename T>
	T* getComponent()
	{
		for (Component* component : components)
		{
			T* typedComponent dynamic_cast<T*>(component);
			if (typedComponent != null)
				return typedComponent;
		}
		return nullptr;
	}
};

class Component
{
protected:
	GameObject* gameObject;
public:
	bool enabled;

	Component(GameObject* object, bool enabledOnStart = true)
	{
		enabled = enabledOnStart;
		gameObject = object;
	}
	~Component()
	{
		delete gameObject;
	}

	virtual void update(float deltaTime) {}
};