#pragma once
#include "Component.h"
#include <string>
#include <memory>
// fake types until implemeneted.
typedef std::string fakeMesh;
typedef std::string fakeShader;
typedef std::string fakePicture;

// data required for 2d and 3d Data.
struct Data3D {
	std::unique_ptr<fakeMesh> mesh;
	std::unique_ptr<fakeShader> shader;
};
struct Data2D {
	std::unique_ptr<fakePicture> image;
};

// Can only hold 2D or 3D data not both.
//union Data {
//	Data3D data3D;
//	Data2D data2D;
//};

class RenderComponent : public Component {
public:
	RenderComponent();
	~RenderComponent();
	bool init();
	bool cleanup();
	void setMesh(fakeMesh mesh);
	void setShader(fakeShader shader);
	void setImage(fakePicture image);
private:
	Data3D data;
	bool is2D;
};