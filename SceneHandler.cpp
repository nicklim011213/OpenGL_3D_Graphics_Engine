#ifndef SCENE
#define SCENE

#include <string>
#include <vector>
#include "ModelHandler.cpp"
#include "CommonDataStructs.cpp"

class Scene
{
	int IndexOffset = 0;

public:

	std::vector<float> UnpackedPoints;
	std::vector<unsigned int> TriangleIndexes;

	void AddModel(Model model, Point Offset)
	{
		for (int Index : model.ReadTrianglesIndexs())
		{
			TriangleIndexes.push_back(Index + IndexOffset);
		}

		for (Point point : model.ReadVerts())
		{
			UnpackedPoints.push_back(point.X + Offset.X);
			UnpackedPoints.push_back(point.Y + Offset.Y);
			UnpackedPoints.push_back(point.Z + Offset.Z);
			++IndexOffset;
		}
	}

	void AddModel(Model model)
	{
		for (int Index : model.ReadTrianglesIndexs())
		{
			TriangleIndexes.push_back(Index + IndexOffset);
		}

		for (Point point : model.ReadVerts())
		{
			UnpackedPoints.push_back(point.X);
			UnpackedPoints.push_back(point.Y);
			UnpackedPoints.push_back(point.Z);
			++IndexOffset;
		}
	}

	std::vector<float>& GetPoints()
	{
		return UnpackedPoints;
	}

	std::vector<unsigned int>& GetIndexs()
	{
		return TriangleIndexes;
	}
};

#endif

