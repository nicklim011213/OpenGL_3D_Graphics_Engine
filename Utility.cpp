#include "Utility.h"

    void Utilites::RefreshDeltaTime()
    {
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
    }

    float Utilites::GetDeltaTime()
    {
        return deltaTime;
    }