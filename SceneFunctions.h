#ifndef SCENEFUNCTIONS
#define SCENEFUNCTIONS
#include <vector>
#include "ModelHandler.h"
#include "CommonDataStructs.h"

UnpackagedPoints AddModelVertex(Model model)
{
	UnpackagedPoints Result;
	for (int Index : model.ReadTrianglesIndexs())
	{
		Result.Indexes.push_back(Index);
	}

	for (Point point : model.ReadVerts())
	{
		Result.Points.push_back(point.X);
		Result.Points.push_back(point.Y);
		Result.Points.push_back(point.Z);
		Result.IndexOffset++;
	}
	return Result;
}

#endif