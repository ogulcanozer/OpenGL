#include "vertexBuffer.h"
#include "renderer.h"
vertexBuffer::vertexBuffer(const void* data, unsigned int size, int mode)
{
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, size, data, mode);
}

vertexBuffer::~vertexBuffer()
{
    glDeleteBuffers(1, &m_RendererID);
}

void vertexBuffer::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}
void vertexBuffer::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
