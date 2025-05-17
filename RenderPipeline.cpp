#include <glad.h> 
#include <glfw3.h>
#include "RenderPipeline.h"
#include "SceneHandler.h"

void RenderPipeline::AttachImplementation(RenderBufferObjects(*PipelineFunction)(Scene))
{
	PipelineFunctions.push_back(PipelineFunction);
}

std::vector<RenderBufferObjects> RenderPipeline::Execute(Scene scene)
{
	std::vector<RenderBufferObjects> Result;
	for (auto& PipelineFunction : PipelineFunctions)
	{
		Result.push_back(PipelineFunction(scene));
	}
	return Result;
}
