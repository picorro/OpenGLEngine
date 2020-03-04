#pragma once
#include <glad.h>
#include <glfw3.h>
#include <iostream>
#include "shader.h"
#include "stb_image.h"

const int v = 9;
class Triangle
{
	float vertices[18] = {
		// positions        
		 0.5f, 0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
		 0.0f, -0.5f, 0.0f,
	};
public:
	void addBufferData();
	void update(Shader shader);
};
