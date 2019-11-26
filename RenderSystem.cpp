#include "RenderSystem.h"
#include <iostream>

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




