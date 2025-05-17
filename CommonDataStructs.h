#ifndef COMMONDATASTRUCTS
#define COMMONDATASTRUCTS
struct Point
{
	float X = 0;
	float Y = 0;
	float Z = 0;

	Point(float x, float y, float z);

	Point();
};

struct RenderBufferObjects
{
	unsigned int VAO;
};
#endif // !COMMONDATASTRUCTS