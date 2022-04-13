#ifndef SWTOR_TRANSFORMABLE_H
#define SWTOR_TRANSFORMABLE_H

#include "../../glm/glm/vec3.hpp"
#include "../../glm/glm/gtc/quaternion.hpp"
#include "IUpdatable.h"

class Transformable : public IUpdatable
{
public:
	Transformable(glm::vec3 position, glm::vec3 rotation);

	glm::vec3 getPosition();
    glm::quat getRotation();
    glm::vec3 getFront();

protected:
	void rotateAt(glm::vec3 rotation);
    void rotateAt(glm::quat rotation);
    void rotate(glm::vec3 delta);
    void rotate(glm::quat delta);
	void moveAt(glm::vec3 newPos);
    void move(glm::vec3 delta);
private:
    glm::vec3 position;
    glm::quat rotation;
    glm::vec3 front;

};

#endif //SWTOR_TRANSFORMABLE_H
