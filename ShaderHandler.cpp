#ifndef SHADERHANDLER
#define SHADER

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

	Shader(std::string Name)
	{
		boost::filesystem::path ShaderFolder = boost::filesystem::initial_path();
		ShaderFolder /= "Shaders";
		ShaderFolder /= Name;
		boost::filesystem::ifstream ShaderReader(ShaderFolder);
		std::string line = "";
		while (std::getline(ShaderReader, line))
		{
			Source += line + '\n';
		}
		if (ShaderFolder.filename().extension() == ".vs")
		{
			ShaderID = glCreateShader(GL_VERTEX_SHADER);
		}
		else if (ShaderFolder.filename().extension() == ".fs")
		{
			ShaderID = glCreateShader(GL_FRAGMENT_SHADER);
		}

		auto SourceCpy = Source.c_str();
		glShaderSource(ShaderID, 1, &SourceCpy, NULL);
		glCompileShader(ShaderID);

		int success;
		char infoLog[512];
		glGetShaderiv(ShaderID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(ShaderID, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
	}

	int GetShaderID()
	{
		return ShaderID;
	}
};

class ShaderProgram
{
	std::vector<Shader> Shaders;
	unsigned int ShaderProgramID;
		
public:

	void AttachShader(Shader s)
	{
		Shaders.push_back(s);
	}

	void UseShaders()
	{
		ShaderProgramID = glCreateProgram();
		for (auto ittr = Shaders.begin(); ittr != Shaders.end(); ++ittr)
		{
			glAttachShader(ShaderProgramID, ittr->GetShaderID());
		}
		glLinkProgram(ShaderProgramID);
	}

	unsigned int GetShaderProgramID()
	{
		return ShaderProgramID;
	}

	void SetShaderValue(std::string ValueName, glm::mat4 value)
	{
		glUniformMatrix4fv(glGetUniformLocation(ShaderProgramID, ValueName.c_str()), 1, false, &value[0][0]);
	}
};

#endif