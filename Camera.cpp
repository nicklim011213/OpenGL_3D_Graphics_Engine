#ifndef CAMERA
#define CAMERA
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:

	float cameraSpeed = 2.5f;
	glm::vec3 cameraPos, cameraTarget, cameraFront, cameraUp, cameraDirection, cameraRight;
	glm::mat4 view;

	Camera()
	{
		cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
		cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
		cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
		cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

		cameraDirection = glm::normalize(cameraPos - cameraTarget);
		cameraRight = glm::normalize(glm::cross(cameraUp, cameraDirection));
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	}

	void left()
	{
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	}

	void right()
	{
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	}

	void forward()
	{
		cameraPos += cameraSpeed * cameraFront;
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	}

	void backwards() 
	{
		cameraPos -= cameraSpeed * cameraFront;
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	}
};
#endif