#pragma once
#include "Vector.h"
class Transformable
{
public:
	//Constructors
	Transformable(Vector3 position, Vector3 direction, Vector3 worldUp, Vector3 rotation);
	~Transformable() {};

	//getMethods
	Vector3 getPosition();
	Vector3 getRotation();
	Vector3 getFront();
	Vector3 getAngles();

protected:
	float movementSpeed;

	Vector3 worldUp;
	Vector3 position;
	Vector3 rotation;
	Vector3 front;
	Vector3 right;
	Vector3 up;

	float pitch;
	float yaw;
	float roll;

	//Additional methods
	float radians(const float angle);

	//Movement
	void rotate(Vector3 delta);
	void move(Vector3 n_coord);
	void updateVectors();
};