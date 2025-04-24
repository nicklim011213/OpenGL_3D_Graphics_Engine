#ifndef SCENE
#define SCENE

#include <string>
#include <vector>
#include "ModelHandler.h"

class Scene
{
	int IndexOffset = 0;

public:

	std::vector<float> UnpackedPoints;
	std::vector<unsigned int> TriangleIndexes;

	void AddModel(Model model, Point Offset);

	void AddModel(Model model);

	std::vector<float>& GetPoints();
	std::vector<unsigned int>& GetIndexs();
};

#endif