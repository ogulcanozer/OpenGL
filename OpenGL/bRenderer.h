#pragma once

#include <glm.hpp>

class bRenderer {



public:
	static void initBatch();
	static void terminateBatch();

	static void beginBatch();
	static void endBatch();
	static void flush();



	struct info {
		uint32_t drawCount = 0;
		uint32_t quadCount = 0;
	};

	static void drawQuad();
	static void drawQuad();
};

