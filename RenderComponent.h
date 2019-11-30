#pragma once
#include "Component.h"
#include <string>

class RenderComponent : public Component {
public:
	RenderComponent();
	~RenderComponent();
	bool init();
	bool cleanup();
	void setMesh();
	void setShader();
	void setImage();
	inline unsigned int getVBO() { return VBO; };
	inline unsigned int getVAO() { return VAO; };
private:
	unsigned int VBO;
	unsigned int VAO;
};