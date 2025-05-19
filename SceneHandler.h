#ifndef SCENE
#define SCENE

#include <vector>
#include "ModelHandler.h"
#include "ShaderHandler.h"
#include "CommonDataStructs.h"

class Scene
{
	int IndexOffset = 0;
	UnpackagedPoints(*ModelHandler)(Model model) = nullptr;
	std::vector<float> Points;
	std::vector<unsigned int> Indexes;
	std::vector<float> Textures;
	std::vector<int8_t> Colors;

public:

	int ShaderProgramID = 0;

	void AttachShaderProgram(ShaderProgram shaderProgram);

	void AttachModelHandler(UnpackagedPoints(*ModelHandler)(Model model));

	void AttachModel(Model model);

	std::vector<float>& GetPoints()
	{
		return Points;
	}

	std::vector<unsigned int>& GetIndexs()
	{
		return Indexes;
	}

	std::vector<float>& GetTextures()
	{
		return Textures;
	}

	std::vector<int8_t>& GetColors()
	{
		return Colors;
	}

	int GetIndexOffset()
	{
		return IndexOffset;
	}
};

#endif