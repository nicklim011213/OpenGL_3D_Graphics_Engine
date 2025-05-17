#ifndef PIPELINE
#define PIPELINE

#include "SceneHandler.h"
#include "CommonDataStructs.h"

class RenderPipeline
{
public:

	void AttachImplementation(RenderBufferObjects(*PipelineFunction)(Scene));

	std::vector<RenderBufferObjects(*)(Scene)> PipelineFunctions;

	std::vector<RenderBufferObjects> Execute(Scene scene);
};
#endif