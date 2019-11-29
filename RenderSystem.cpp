#include "RenderSystem.h"
#include <iostream>
//#include "include/glad/glad.h"
//#include "GLFW/glfw3.h"
RenderSystem::RenderSystem()
{
	winWidth = 1920;
	winHeight = 1280;
	std::cout << "Render System Constructed.\n";
}

RenderSystem::~RenderSystem()
{
	std::cout << "Render System Destructed.\n";
}

bool RenderSystem::init(int windowWidth, int windowHeight)
{
	winWidth = windowWidth;
	winHeight = windowHeight;
	std::cout << "Render System Initialized.\n";

	
	return true;
}

bool RenderSystem::cleanup()
{
	std::cout << "Render System Cleaned Up.\n";


	return true;
}

void RenderSystem::doMain() {
	//glfwInit();
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	//if (window == NULL)
	//{
	//	std::cout << "Failed to create GLFW window" << std::endl;
	//	glfwTerminate();
	//	return;
	//}
	//glfwMakeContextCurrent(window);

	//if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	//{
	//	std::cout << "Failed to initialize GLAD" << std::endl;
	//	return;
	//}
	//glViewport(0, 0, 800, 600);


}



