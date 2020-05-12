#include "texture.h"

texture::texture(const std::string& path)
	:m_RendererID(0), m_FilePath(path), m_Height(0), m_Width(0), m_BitsPerPixel(0), m_LocalBuffer(nullptr)
{
	Mat img = imread(m_FilePath, IMREAD_UNCHANGED);
	CV_Assert(img.depth() == CV_8U);
	if (img.empty()) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return;
	}
	Mat tmp;
	cv::flip(img, tmp, 0);
	Mat dst;
	cvtColor(tmp, dst, COLOR_BGR2RGBA);
	m_LocalBuffer = dst.ptr<uchar>(0,0);
	m_Height = dst.rows;
	m_Width = dst.cols;
	m_BitsPerPixel = dst.depth();

	glGenTextures(1, &m_RendererID);
	glBindTexture(GL_TEXTURE_2D, m_RendererID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);
	glBindTexture(GL_TEXTURE_2D, 0);
		
	if (m_LocalBuffer) {
		img.release();
		dst.release();
		std::cout << "IMAGE ACQUIRED" << std::endl;
	}

}

texture::~texture()
{
	glDeleteTextures(1, &m_RendererID);
}

void texture::bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, m_RendererID);
}

void texture::unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
