#ifndef SCENE
#define SCENE

#include <vector>
#include "ModelHandler.h"

class Scene
{
	int IndexOffset = 0;
	int IndexOffset_Textured = 0;

public:

	std::vector<float> UnpackedPoints;
	std::vector<unsigned int> TriangleIndexes;

	std::vector<float> UnpackedPoints_Textured;
	std::vector<unsigned int> TriangleIndexes_Textured;

	void AddModel(Model model, Point Offset);

	void AddModel(Model model);

	void AddTexturedModel(Model model, Point Offset);

	void AddTexturedModel(Model model);

	std::vector<float>& GetPoints();

	std::vector<unsigned int>& GetIndexs();

	std::vector<float>& GetPoints_Textured();

	std::vector<unsigned int>& GetIndexs_Textured();
};

#endif