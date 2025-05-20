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
	float C1 = 0;
	float C2 = 0;
	float C3 = 0;
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
	std::vector<float> Colors;
	int IndexOffset = 0;
};
#endif // !COMMONDATASTRUCTS