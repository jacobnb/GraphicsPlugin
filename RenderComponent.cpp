#include "RenderComponent.h"
#include <iostream>
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
