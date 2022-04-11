//getCoord() - returns coordinates in vector
//setCoord() - sets coordinates
//.normalize() - normalizes vector and returns coordinates in Vector3
//.cross(Vector3 v) - calculates vector product and returns coordinates in Vector3
//.angle(Vector3 v) - calculates angle between this and given Vector3 and returns angle in grad
//.module() - calculates module of this vector and returns length
//overloaded operators +, - for two Vector3
//overloaded operators *, / for Vector3 and scalar
//overloaded operator * for calculating scalar product of two Vector3


#pragma once
#include <vector>
#define M_PI 3.14159265

class Vector3 {
public:
	Vector3()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}
	~Vector3() {};

	std::vector<float> getCoord();

	Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void setCoord(const float n_x, const float n_y, const float n_z)
	{
		this->x = n_x;
		this->y = n_y;
		this->z = n_z;
	}

	float module();
	Vector3 normalize();
	Vector3 cross(Vector3 v);
	float angle(Vector3 v);


	Vector3 operator =(Vector3 v) {
		std::vector<float> coord = v.getCoord();
		this->x = coord[0];
		this->y = coord[1];
		this->z = coord[2];
		return Vector3(this->x, this->y, this->z);
	}

	friend Vector3 operator + (Vector3 v1, Vector3 v2);

	friend Vector3 operator - (Vector3 v1, Vector3 v2);

	friend Vector3 operator / (Vector3 v, const float a);

	friend Vector3 operator * (Vector3 v, const float a);

	friend float operator * (Vector3 v1, Vector3 v2);

	friend bool operator == (Vector3 v1, Vector3 v2);

	float x;
	float y;
	float z;
};

