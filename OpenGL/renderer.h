#pragma once
#include <GL/glew.h>
#include "vertexArray.h"
#include "indexBuffer.h"
#include "shader.h"

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();
bool GLLogCall(const char* function, const char* file, const char* line);

class renderer {

public:

	void clear() const;
	void draw(const vertexArray& va, const indexBuffer& ib, const shader& shader) const;
	

};

