//Saves coordinates
//Returns coordinates in vector numerated by x,y,z
#pragma once
#include"libs.h"
class Vector3 {
	public:
		Vector3(float x, float y, float z);
		~Vector3() {};
		const std::vector<float> get_coord();
		void set_coord(float n_x, float n_y, float n_z);

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

const std::vector<float> Vector3::get_coord()
{
	std::vector<float> coord;
	coord.push_back(x);
	coord.push_back(y);
	coord.push_back(z);
	return coord;
}

inline void Vector3::set_coord(const float n_x, const float n_y, const float n_z)
{
	this->x = n_x;
	this->y = n_y;
	this->z = n_z;
}

Vector3 operator + (const Vector3 v1, const Vector3 v2)
{
	std::vector<float> coord1;
	std::vector<float> coord2;

	return Vector3(coord1[0] + coord2[0], coord1[1] + coord2[1], coord1[2] + coord2[2]);
}

Vector3 operator + (const Vector3 v1, const Vector3 v2)
{
	std::vector<float> coord1;
	std::vector<float> coord2;

	return Vector3(coord1[0] - coord2[0], coord1[1] - coord2[1], coord1[2] - coord2[2]);
}

Vector3 operator / (const Vector3 v, const float a)
{
	std::vector<float> coord;

	return Vector3(coord[0] / a, coord[1] / a, coord[2] / a);
}

Vector3 operator * (const Vector3 v, const float a)
{
	std::vector<float> coord;

	return Vector3(coord[0] * a, coord[1] * a, coord[2] * a);
}

bool operator == (const Vector3 v1, const Vector3 v2)
{
	std::vector<float> coord1;
	std::vector<float> coord2;

	return ((coord1[0] == coord2[0]) && (coord1[1] == coord2[1]) && (coord1[2] == coord2[2]));
}