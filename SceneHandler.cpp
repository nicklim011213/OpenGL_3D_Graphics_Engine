#include "SceneHandler.h"

	void Scene::AttachShaderProgram(ShaderProgram shaderProgram)
	{
		ShaderProgramID = shaderProgram.GetShaderProgramID();
	}

	void Scene::AttachModelHandler(UnpackagedPoints(*ModelHandler)(Model model))
	{
		this->ModelHandler = ModelHandler;
	}

	void Scene::AttachModel(Model model)
	{
		UnpackagedPoints UnpackagedModel = ModelHandler(model);
		Indexes.insert(Indexes.end(), UnpackagedModel.Indexes.begin(), UnpackagedModel.Indexes.end());
		Points.insert(Points.end(), UnpackagedModel.Points.begin(), UnpackagedModel.Points.end());
		Colors.insert(Colors.end(), UnpackagedModel.Colors.begin(), UnpackagedModel.Colors.end());
		Textures.insert(Textures.end(), UnpackagedModel.Textures.begin(), UnpackagedModel.Textures.end());
		IndexOffset += UnpackagedModel.IndexOffset;
	}