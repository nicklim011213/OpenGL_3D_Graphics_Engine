#include <string>
#include <vector>
#include "ModelHandler.h"
#include "CommonDataStructs.h"
#include "SceneHandler.h"

	void Scene::AddModel(Model model, Point Offset)
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

	void Scene::AddModel(Model model)
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

	std::vector<float>& Scene::GetPoints()
	{
		return UnpackedPoints;
	}

	std::vector<unsigned int>& Scene::GetIndexs()
	{
		return TriangleIndexes;
	}

