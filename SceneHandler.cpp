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

	void Scene::AddTexturedModel(Model model, Point Offset)
	{
		for (int Index : model.ReadTrianglesIndexs())
		{
			TriangleIndexes_Textured.push_back(Index + IndexOffset);
		}

		for (Point point : model.ReadVerts())
		{
			UnpackedPoints_Textured.push_back(point.X + Offset.X);
			UnpackedPoints_Textured.push_back(point.Y + Offset.Y);
			UnpackedPoints_Textured.push_back(point.Z + Offset.Z);
			++IndexOffset_Textured;
		}
	}

	void Scene::AddTexturedModel(Model model)
	{
		for (int Index : model.ReadTrianglesIndexs())
		{
			TriangleIndexes_Textured.push_back(Index + IndexOffset_Textured);
		}

		for (Point point : model.ReadVerts())
		{
			UnpackedPoints_Textured.push_back(point.X);
			UnpackedPoints_Textured.push_back(point.Y);
			UnpackedPoints_Textured.push_back(point.Z);
			++IndexOffset_Textured;
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

	std::vector<float>& Scene::GetPoints_Textured()
	{
		return UnpackedPoints_Textured;
	}

	std::vector<unsigned int>& Scene::GetIndexs_Textured()
	{
		return TriangleIndexes_Textured;
	}

