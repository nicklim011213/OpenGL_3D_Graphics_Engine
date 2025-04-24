#include "ShaderHandler.h"

	Shader::Shader(std::string Name)
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

	int Shader::GetShaderID()
	{
		return ShaderID;
	}

	void ShaderProgram::AttachShader(Shader s)
	{
		Shaders.push_back(s);
	}

	void ShaderProgram::UseShaders()
	{
		ShaderProgramID = glCreateProgram();
		for (auto ittr = Shaders.begin(); ittr != Shaders.end(); ++ittr)
		{
			glAttachShader(ShaderProgramID, ittr->GetShaderID());
		}
		glLinkProgram(ShaderProgramID);
	}

	unsigned int ShaderProgram::GetShaderProgramID()
	{
		return ShaderProgramID;
	}

	void ShaderProgram::SetShaderValue(std::string ValueName, glm::mat4 value)
	{
		glUniformMatrix4fv(glGetUniformLocation(ShaderProgramID, ValueName.c_str()), 1, false, &value[0][0]);
	}