#pragma once
#include <map>
#include <string>


// working on https://learnopengl.com/Model-Loading/Mesh - added assimp to build bat files.

class RenderSystem {
public:
	RenderSystem();
	~RenderSystem();
	bool init(int windowWidth, int windowHeight);
	bool cleanup();
	void draw();
	bool LoadImage(std::string path, std::string texName);
	void DisplayImage(std::string imgName, int x, int y);

	void doMain();
private:
	// Window* 
	int winWidth, winHeight;
	// camera* ?
};