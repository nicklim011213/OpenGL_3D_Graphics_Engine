#include <iostream>
#include <vector>
#include "ShaderHandler.cpp"
#include "CommonDataStructs.cpp"

class Item
{
	std::vector<Point> Verts;
	Shader FragmentShader;
	Shader Vertexshader;
};