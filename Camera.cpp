#ifndef CAMERA
#define CAMERA
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Utility.cpp"

class Camera
{
public:

	float cameraSpeed = 2.5f;
	glm::vec3 cameraPos, cameraFront, cameraUp;
	glm::mat4 view;

	Camera()
	{
		cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
		cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
		cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	}

	void left(Utilites* util)
	{
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed * util->GetDeltaTime();
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	}

	void right(Utilites* util)
	{
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed * util->GetDeltaTime();
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	}

	void forward(Utilites* util)
	{
		cameraPos += cameraSpeed * cameraFront * util->GetDeltaTime();
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	}

	void backwards(Utilites* util)
	{
		cameraPos -= cameraSpeed * cameraFront * util->GetDeltaTime();
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	}
};
#endif