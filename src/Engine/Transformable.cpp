#include "Transform.h"
Transformable::Transformable(Vector3 position, Vector3 direction, Vector3 worldUp, Vector3 rotation)
{
	this->movementSpeed = 0.f;

	this->rotation = rotation;
	this->worldUp = worldUp;
	this->position = position;
	this->front = direction;
	this->right.setCoord(0, 0, 0);
	this->up = worldUp;

	this->pitch = 0.f;
	this->yaw = -90.f;
	this->roll = 0.f;
}

inline void Transformable::rotate(Vector3 delta)
{
	Vector3 x(1, 0, 0);
	Vector3 y(0, 1, 0);
	Vector3 z(0, 0, 1);

	this->rotation = delta + this->rotation;
	this->pitch = 90 - z.angle(rotation);
	this->yaw = y.angle(this->rotation * cos(pitch));

	if (this->pitch >= 360) this->pitch -= 360;
	if (this->yaw >= 360) this->yaw -= 360;
	this->updateVectors();
}

inline void Transformable::move(Vector3 n_coord)
{
	this->position = n_coord;
}

inline Vector3 Transformable::getPosition()
{
	return this->position;
}

inline Vector3 Transformable::getRotation()
{
	return this->rotation;
}

inline Vector3 Transformable::getFront()
{
	return this->front;
}

inline Vector3 Transformable::getAngles()
{
	return Vector3(this->pitch, this->yaw, this->roll);
}

inline float Transformable::radians(const float angle)
{
	float rads = 2 * M_PI * angle / 360;
	return rads;
}

inline void Transformable::updateVectors()
{
	this->front.x = cos(radians(this->yaw)) * cos(radians(this->pitch));
	this->front.y = sin(radians(this->pitch));
	this->front.z = sin(radians(this->yaw)) * cos(radians(this->pitch));

	this->front.normalize();
	this->right = (this->front.cross(this->worldUp)).normalize();
	this->up = (this->right.cross(this->front)).normalize();
}
