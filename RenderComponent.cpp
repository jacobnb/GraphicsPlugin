#include "RenderComponent.h"
#include <iostream>
#include "include/glad/glad.h"
#include "GLFW/glfw3.h"
RenderComponent::RenderComponent()
{
	std::cout << "Render Component Constructed.\n";
}

RenderComponent::~RenderComponent()
{
	std::cout << "Render Component Deconstructed.\n";

}

bool RenderComponent::init()
{
	std::cout << "Render Component Init.\n";
	return true;
}

bool RenderComponent::cleanup()
{
	std::cout << "Render Component Cleanup.\n";
	return true;
}

void RenderComponent::setMesh()
{
	// create vertices.
	float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};
	// init buffer
	glGenBuffers(1, &VBO);
	// bind buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//copy data into buffer.
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// how to interpret the vertex data.
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}
