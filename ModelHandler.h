#ifndef MODELHANDLER
#define MODELHANDLER

#include <string>
#include <vector>
#include "CommonDataStructs.h"

class Model
{
	std::vector<Point> Vertexs;
	std::vector<int> TriangleIndexs;
	int PointIndexOffset = 0;
	bool IsTextured = false;
	bool IsColored = false;

public:

	Model(std::string Path);

	void ApplyTexture(std::string Path, int Width, int Height, int ColorDepth = 8);

	std::vector<Point> ReadVerts();

	std::vector<int> ReadTrianglesIndexs();

	bool IsTexturedModel()
	{
		return IsTextured;
	}

	bool IsColoredModel()
	{
		return IsColored;
	}
};

#endif