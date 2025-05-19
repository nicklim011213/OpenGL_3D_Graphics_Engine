#ifndef PIPELINE_FUNCTIONS
#define PIPELINE_FUNCTIONS

#include <glad.h> 
#include <glfw3.h>
#include "RenderPipeline.h"
#include "SceneHandler.h"

RenderBufferObjects VertexOnly(Scene scene)
{
    RenderBufferObjects Result;
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, scene.GetPoints().size() * sizeof(float), scene.GetPoints().data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, scene.GetIndexs().size() * sizeof(unsigned int), scene.GetIndexs().data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    Result.VAO = VAO;
	return Result;
}

#endif