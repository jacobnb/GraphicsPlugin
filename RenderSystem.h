#pragma once
#include <map>
#include <string>
#include "include/glad/glad.h"
#include "GLFW/glfw3.h"
#include <vector>

class RenderComponent;

class RenderSystem {
public:
	RenderSystem();
	~RenderSystem();
	bool init(int windowWidth, int windowHeight);
	bool cleanup();
	bool draw();
	bool LoadImage(std::string path, std::string texName);
	void DisplayImage(std::string imgName, int x, int y);

	void addRenderComp(RenderComponent* rc);
	void doMain();
private:
	GLFWwindow* window;

	unsigned int shaderProgram;

	bool initShaderProgram();
	std::vector<RenderComponent*> renderComponents;
};