#include "ModelHandler.h"

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
				TriangleIndexs.push_back(boost::lexical_cast<int>(line.substr(1)));
			}
			else if (boost::algorithm::contains(line, "//"))
			{
				// For comments
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