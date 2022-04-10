//
// Created by ivan on 10.04.2022.
//

#include "GameObject.h"

OrientedPoint::OrientedPoint(glm::vec3 position, glm::vec3 rotation)
{
    this->position = position;
    this->rotation = rotation;
}

GameObject::GameObject(glm::vec3 position, glm::vec3 rotation) : OrientedPoint(position, rotation)
{}

glm::vec3 OrientedPoint::getPosition()
{
    return position;
}
glm::vec3 OrientedPoint::getRotation()
{
    return rotation;
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

void GameObject::render()
{
    for (Component* component : this->components)
    {
        if (component->enabled)
            component->render();
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
