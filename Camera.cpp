#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Utility.h"
#include "Camera.h"

	Camera::Camera()
	{
		cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
		cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
		cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		CameraDirection.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		CameraDirection.y = sin(glm::radians(pitch));

	}

	void Camera::left(Utilites* util)
	{
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed * util->GetDeltaTime();
		UpdateView();
	}

	void Camera::right(Utilites* util)
	{
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed * util->GetDeltaTime();
		UpdateView();
	}

	void Camera::forward(Utilites* util)
	{
		cameraPos += cameraSpeed * cameraFront * util->GetDeltaTime();
		UpdateView();
	}

	void Camera::backwards(Utilites* util)
	{
		cameraPos -= cameraSpeed * cameraFront * util->GetDeltaTime();
		UpdateView();
	}

	void Camera::HandleMouse(GLFWwindow* window)
	{
		float xposCursor = static_cast<float>(xpos);
		float yposCursor = static_cast<float>(ypos);
		glfwGetCursorPos(window, &xpos, &ypos);
		float xoffset = xposCursor - lastX;
		float yoffset = lastY - yposCursor; // reversed since y-coordinates range from bottom to top
		lastX = xposCursor;
		lastY = yposCursor;

		const float sensitivity = 0.1f;
		xoffset *= sensitivity;
		yoffset *= sensitivity;

		yaw += xoffset;
		pitch += yoffset;

		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;

		glm::vec3 direction;
		direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		direction.y = sin(glm::radians(pitch));
		direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		cameraFront = glm::normalize(direction);
		UpdateView();
	}

	void Camera::UpdateView()
	{
		view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	}