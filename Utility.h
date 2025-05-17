#ifndef UTIL
#define UTIL
class Utilites
{
    float lastFrame = 0.0f;
    float deltaTime = 0.0f;

public:

    void RefreshDeltaTime();

    float GetDeltaTime();
};

#endif