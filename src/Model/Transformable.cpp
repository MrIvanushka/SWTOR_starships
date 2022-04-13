#include "Transformable.h"
Transformable::Transformable(glm::vec3 position, glm::vec3 rotation)
{
	this->rotation = glm::quat(rotation);
	this->position = position;
}

void Transformable::rotate(glm::vec3 delta)
{
    rotate(glm::quat(rotation));
}

void Transformable::rotate(glm::quat delta)
{
    this->rotation = delta * this->rotation;
    this->front = glm::vec3(1, 0, 0) * rotation;
}

void Transformable::rotateAt(glm::vec3 newRot)
{
    rotateAt(glm::quat(newRot));
}

void Transformable::rotateAt(glm::quat newRot)
{
    this->rotation = newRot;
    this->front = glm::vec3(1, 0, 0) * newRot;
}

void Transformable::move(glm::vec3 delta)
{
	this->position += delta;
}

void Transformable::moveAt(glm::vec3 newPos)
{
    this->position = newPos;
}

glm::vec3 Transformable::getPosition()
{
	return this->position;
}

glm::quat Transformable::getRotation()
{
	return this->rotation;
}

glm::vec3 Transformable::getFront()
{
	return this->front;
}
