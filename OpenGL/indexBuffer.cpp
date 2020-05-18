#include "indexBuffer.h"
#include "renderer.h"


indexBuffer::indexBuffer(unsigned int* data, unsigned int count, int mode)
    :m_Count(count)
{
    ASSERT(sizeof(GLuint) == sizeof(unsigned int));

    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, mode);
}

indexBuffer::~indexBuffer()
{
    glDeleteBuffers(1, &m_RendererID);
}

void indexBuffer::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}
void indexBuffer::unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
