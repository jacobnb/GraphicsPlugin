// GraphicsTester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../RenderComponent.h"
#include "../RenderSystem.h"
int main()
{

	auto rs = new RenderSystem();
	rs->init(800, 600);
	auto rc = new RenderComponent();
	rc->init();
	auto rctwo = new RenderComponent();
	rctwo->init();
	float arr[] = {
	-1.0f, -1.0f, 0.0f,
	 -0.5f, -0.5f, 0.0f,
	 -1.0f,  0.5f, 0.0f
	};
	float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};

	rctwo->setMesh(arr, 9);
	rs->addRenderComp(rctwo);

	rc->setMesh();
	rs->addRenderComp(rc);

	


	while (rs->draw());
	rc->cleanup();
	rs->cleanup();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
