//Saves coordinates
//Returns coordinates in vector numerated by x,y,z
#pragma once
#include"libs.h"
class Vector3 {
	public:
		Vector3(float x, float y, float z);
		~Vector3() {};
		std::vector<float> getCoord();
		void setCoord(float n_x, float n_y, float n_z);

	private:
		float x;
		float y;
		float z;
};

inline Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

std::vector<float> Vector3::getCoord()
{
	std::vector<float> coord;
	coord.push_back(x);
	coord.push_back(y);
	coord.push_back(z);
	return coord;
}

inline void Vector3::setCoord(const float n_x, const float n_y, const float n_z)
{
	this->x = n_x;
	this->y = n_y;
	this->z = n_z;
}

Vector3 operator + ( Vector3 v1, Vector3 v2)
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

bool operator == (Vector3 v1, Vector3 v2)
{
	std::vector<float> coord1 = v1.getCoord();
	std::vector<float> coord2 = v2.getCoord();

	return ((coord1[0] == coord2[0]) && (coord1[1] == coord2[1]) && (coord1[2] == coord2[2]));
}