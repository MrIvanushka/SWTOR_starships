#include "Vector.h"

std::vector<float> Vector3::getCoord()
{
	std::vector<float> coord;
	coord.push_back(x);
	coord.push_back(y);
	coord.push_back(z);
	return coord;
}

inline Vector3 Vector3::normalize()
{
	float moduleV = this->module();
	this->setCoord(this->x / moduleV, this->y / moduleV, this->z / moduleV);
	return Vector3(this->x, this->y, this->z);
}

float Vector3::angle(Vector3 v)
{
	std::vector<float> coord = v.getCoord();
	float scalar = this->x * coord[0] + this->y * coord[1] + this->z * coord[2];
	float angle = acos(scalar / v.module() / sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2))) * 180.0 / M_PI;
	return angle;
}

inline Vector3 Vector3::cross(Vector3 v)
{
	std::vector<float> coord = v.getCoord();
	return Vector3(this->y * coord[2] - this->z * coord[1], this->z * coord[0] - this->x * coord[2], this->x * coord[1] - this->y * coord[0]);
}

inline float Vector3::module()
{
	float moduleV = sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));

	return moduleV;
}




Vector3 operator + (Vector3 v1, Vector3 v2)
{
	std::vector<float> coord1 = v1.getCoord();
	std::vector<float> coord2 = v2.getCoord();

	return Vector3(coord1[0] + coord2[0], coord1[1] + coord2[1], coord1[2] + coord2[2]);
}

Vector3 operator - (Vector3 v1, Vector3 v2)
{
	std::vector<float> coord1 = v1.getCoord();
	std::vector<float> coord2 = v2.getCoord();

	return Vector3(coord1[0] - coord2[0], coord1[1] - coord2[1], coord1[2] - coord2[2]);
}

Vector3 operator / (Vector3 v, const float a)
{
	std::vector<float> coord = v.getCoord();

	return Vector3(coord[0] / a, coord[1] / a, coord[2] / a);
}

Vector3 operator * (Vector3 v, const float a)
{
	std::vector<float> coord = v.getCoord();

	return Vector3(coord[0] * a, coord[1] * a, coord[2] * a);
}

float operator * (Vector3 v1, Vector3 v2)
{
	std::vector<float> coord1 = v1.getCoord();
	std::vector<float> coord2 = v2.getCoord();
	return coord1[0] * coord2[0] + coord1[1] * coord2[1] + coord1[2] * coord2[2];
}


bool operator == (Vector3 v1, Vector3 v2)
{
	std::vector<float> coord1 = v1.getCoord();
	std::vector<float> coord2 = v2.getCoord();

	return ((coord1[0] == coord2[0]) && (coord1[1] == coord2[1]) && (coord1[2] == coord2[2]));
}
