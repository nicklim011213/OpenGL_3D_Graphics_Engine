#ifndef MODELHANDLER
#define MODELHANDLER

#include <string>
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

	std::vector<Point> ReadVerts();

	std::vector<int> ReadTrianglesIndexs();
};

#endif