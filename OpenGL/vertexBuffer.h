#pragma once
#pragma once
class vertexBuffer {
private:
	unsigned int m_RendererID;
public:
	vertexBuffer(const void* data, unsigned int size, int mode);
	vertexBuffer(unsigned int size);
	~vertexBuffer();

	void bind() const;
	void unbind() const;
};