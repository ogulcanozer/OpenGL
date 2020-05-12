#pragma once
#include "renderer.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
using namespace std;

class texture {
private:
	unsigned int m_RendererID;
	std::string m_FilePath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BitsPerPixel;
public:
	texture(const std::string& path);
	~texture();

	void bind(unsigned int slot = 0)const;
	void unbind()const;

	inline int getWidth()const { return m_Width; }
	inline int getHeight()const { return m_Height; }
};