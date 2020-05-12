#include "bRenderer.h"
#include <gl/glew.h>
#include <array>
#include "vertexArray.h"
#include "indexBuffer.h"
#include "shader.h"
#include "vertexBufferLayout.h"


static const size_t maxQuadCount = 1000;
static const size_t maxVertexCount = maxQuadCount * 4;
static const size_t maxIndexCount = maxQuadCount * 6;
static const size_t maxTextures = 1000;

struct Vertex {
	glm::vec3 position;
	glm::vec4 color;
	glm::vec2 texCoords;
	float texIndex;
};

struct bRData {
	GLuint quadVa = 0;
	GLuint quadVbo = 0;
	GLuint quadIbo = 0;

	GLuint whiteTex = 0;
	uint32_t whiteTexSlot = 0;
	uint32_t indexCount = 0;

	Vertex* quadBuffer = nullptr;
	Vertex* quadBufferPtr = nullptr;

	std::array<uint32_t, maxTextures> texSlots;
	uint32_t texSlotIndex = 1;

	

};
static bRData r_Data;

void bRenderer::initBatch()
{
	//r_Data.quadBuffer = new Vertex[maxVertexCount];
	//glCreateVertexArrays(1, &r_Data.quadVa);
	//glBindVertexArray(r_Data.quadVa);
	//vertexArray va;
	//vertexBuffer vbo(position, 4 * 4 * sizeof(GLfloat), GL_STATIC_DRAW);
	//vertexBufferLayout vbl;
	//vbl.push<float>(2);
	//vbl.push<float>(2);
	//va.addLayout(vbo, vbl);
	//indexBuffer ibo(indices, 3 * 2, GL_STATIC_DRAW);

}

void bRenderer::terminateBatch()
{
}

void bRenderer::beginBatch()
{
}

void bRenderer::endBatch()
{
}

void bRenderer::flush()
{
}
