#ifndef SHADERHANDLER
#define SHADERHANDLER

#include <string>
#include <vector>
#include "glm/glm.hpp"

class Shader
{
	std::string Source;
	unsigned int ShaderID = -1;

public:

	Shader(std::string Name);

	int GetShaderID();
};

class ShaderProgram
{
	std::vector<Shader> Shaders;
	unsigned int ShaderProgramID;

public:

	void AttachShader(Shader s);

	void UseShaders();

	unsigned int GetShaderProgramID();

	void SetShaderValue(std::string ValueName, glm::mat4 value);
};

#endif