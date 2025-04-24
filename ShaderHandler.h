#ifndef SHADERHANDLER
#define SHADERHANDLER

#include <string>
#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/algorithm/string.hpp>
#include <vector>

#include <glad.h> 
#include <glfw3.h>
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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