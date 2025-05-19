#ifndef COMMONDATASTRUCTS
#define COMMONDATASTRUCTS
#include <vector>

struct Point
{
	// Position Values
	float X = 0;
	float Y = 0;
	float Z = 0;
	// Color Values
	int8_t C1 = 0;
	int8_t C2 = 0;
	int8_t C3 = 0;
	// Textures Values
	float T1 = 0;
	float T2 = 0;

	Point(float x, float y, float z);

	Point();
};

struct RenderBufferObjects
{
	unsigned int VAO;
};

struct UnpackagedPoints
{
	std::vector<float> Points;
	std::vector<unsigned int> Indexes;
	std::vector<float> Textures;
	std::vector<int8_t> Colors;
	int IndexOffset = 0;
};
#endif // !COMMONDATASTRUCTS