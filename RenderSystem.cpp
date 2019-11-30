#include "RenderSystem.h"
#include "RenderComponent.h"
#include <iostream>

const char* vertshader = "#version 330 core \n layout(location = 0) in vec3 aPos;\n void main() \n {	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);}";
const char* fragShader = "#version 330 core \n out vec4 FragColor; void main(){	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);}";

RenderSystem::RenderSystem()
{
	std::cout << "Render System Constructed.\n";
	window = nullptr;
}

RenderSystem::~RenderSystem()
{
	std::cout << "Render System Destructed.\n";
}

bool RenderSystem::init(int windowWidth, int windowHeight)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(windowWidth, windowHeight, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return false;
	}
	glViewport(0, 0, 800, 600);

	auto framebuffer_size_callback = [](GLFWwindow* window, int width, int height) -> void {
		glViewport(0, 0, width, height);
	};

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!initShaderProgram()) {
		std::cout << "Failed to init shader program.\n";
		return false;
	}


	std::cout << "Render System Initialized.\n";
	return true;
}

bool RenderSystem::cleanup()
{
	std::cout << "Render System Cleaned Up.\n";
	return true; 
}

bool RenderSystem::draw()
{
	// check and call events and swap the buffers
	glfwPollEvents();
	glfwSwapBuffers(window);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(shaderProgram);
	for(RenderComponent* rc : renderComponents)
	{
		glBindVertexArray(rc->getVAO());
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
	
	if (glfwWindowShouldClose(window)) {
		// TODO: !! Shouldn't be processing input in renderer.
		glfwTerminate();
		return false;
	}
	return true;
}

void RenderSystem::addRenderComp(RenderComponent* rc)
{
	renderComponents.push_back(rc);
}

void RenderSystem::doMain() {

}

bool RenderSystem::initShaderProgram()
{
	//=========Vertex Shader==========
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertshader, NULL);
	glCompileShader(vertexShader);
	//check errors
	int  success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		return false;
	}

	//===========Fragment Shader=============
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragShader, NULL);
	glCompileShader(fragmentShader);
	//check errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		return false;
	}

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM\n" << infoLog << std::endl;
		return false;
	}
	// Once shaders are linked to program can delete.
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	return true;
}





