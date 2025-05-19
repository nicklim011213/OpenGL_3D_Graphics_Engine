#include "ModelHandler.h"
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <glad.h> 
#include <glfw3.h>

	void Model::ApplyTexture(std::string Path, int Width, int Height, int ColorDepth)
	{
		unsigned char* data = stbi_load(Path.c_str(), &Width, &Height, &ColorDepth, 0);
		unsigned int TextureID = -1;
		glGenTextures(1, &TextureID);
		glBindTexture(GL_TEXTURE_2D, TextureID);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		stbi_image_free(data);
	}

	Model::Model(std::string Path)
	{
		boost::filesystem::path ModelFolder = boost::filesystem::initial_path();
		ModelFolder /= "Models";
		ModelFolder /= Path;

		boost::filesystem::ifstream ModelReader(ModelFolder);
		std::string line = "";
		while (std::getline(ModelReader, line))
		{
			if (boost::algorithm::contains(line, "#"))
			{
				size_t Xstart, Ystart, Zstart = 0;
				Xstart = line.find("X:");
				Ystart = line.find("Y:");
				Zstart = line.find("Z:");

				std::string XStr, YStr, ZStr;
				XStr = line.substr(Xstart + 2, Ystart - Xstart - 2);
				YStr = line.substr(Ystart + 2, Zstart - Ystart - 2);
				ZStr = line.substr(Zstart + 2);

				Point Temp;
				Temp.X = boost::lexical_cast<float>(XStr);
				Temp.Y = boost::lexical_cast<float>(YStr);
				Temp.Z = boost::lexical_cast<float>(ZStr);
				Vertexs.push_back(Temp);
			}
			else if (boost::algorithm::contains(line, "$"))
			{
				line = line.substr(1);
				std::vector<std::string> SplitValues;
				boost::split(SplitValues, line, boost::is_any_of(","));
				for (std::string SplitValue : SplitValues)
				{
					TriangleIndexs.push_back(boost::lexical_cast<int>(SplitValue));
				}
			}
			else if (boost::algorithm::contains(line, "&"))
			{
				IsTextured = true;
				size_t Xstart, Ystart = 0;
				Xstart = line.find("X:");
				Ystart = line.find("Y:");

				std::string XStr, YStr;
				XStr = line.substr(Xstart + 2, Ystart - Xstart - 2);
				YStr = line.substr(Ystart + 2);

				Point Temp;
				Temp.X = boost::lexical_cast<float>(XStr);
				Temp.Y = boost::lexical_cast<float>(YStr);
				Temp.Z = -1.0f;
				Vertexs.push_back(Temp);
			}
		}
	}

	std::vector<Point> Model::ReadVerts()
	{
		return Vertexs;
	}

	std::vector<int> Model::ReadTrianglesIndexs()
	{
		return TriangleIndexs;
	}