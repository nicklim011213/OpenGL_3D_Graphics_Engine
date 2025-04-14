#ifndef UTIL
#define UTIL
#include <glad.h> 
#include <glfw3.h>

class Utilites
{
    float lastFrame = 0.0f;
    float deltaTime = 0.0f;

public:

    float GetDeltaTime()
    {
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        return deltaTime;
    }
};

#endif