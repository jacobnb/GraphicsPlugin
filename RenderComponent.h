#pragma once
#include "Component.h"
#include <string>
#include <array>
class RenderComponent : public Component {
public:
	RenderComponent();
	~RenderComponent();
	bool init();
	bool cleanup();
	void setMesh();
	void setMesh(float* vertices, int length);
	void setShader();
	void setImage();
	inline unsigned int getVBO() { return VBO; };
	inline unsigned int getVAO() { return VAO; };
private:
	unsigned int VBO;
	unsigned int VAO;
};