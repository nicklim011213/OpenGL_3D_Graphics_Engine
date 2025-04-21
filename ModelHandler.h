#ifndef MODELHANDLER
#define MODELHANDLER

#include <iostream>
#include <vector>
#include "CommonDataStructs.h"
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>

class Model
{
	std::vector<Point> Vertexs;
	std::vector<int> TriangleIndexs;
	int PointIndexOffset = 0;

public:

	Model(std::string Path);

	const std::vector<Point>& ReadVerts();

	const std::vector<int>& ReadTrianglesIndexs();
};

#endif