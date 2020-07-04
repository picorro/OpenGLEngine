#pragma once
#include <glad.h>
#include <glfw3.h>
#include <iostream>
#include "shader.h"
#include "stb_image.h"

class Rectangle
{
	float x = 0.5f;
	float y = 0.7f;
public: 

	float vertices[32] = {
		// positions          // colors           // texture coords
		 x,  y, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
		 x, -y, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
		-x, -y, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
		-x,  y, 0.0f,   0.5f, 0.5f, 0.5f,   0.0f, 1.0f  // top left 
	};;

	unsigned int indices[6] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};
	Rectangle()
	{
		
	}
	Rectangle(int a)
	{
		
	}
	void addBufferData();
	void update(Shader shader);
};