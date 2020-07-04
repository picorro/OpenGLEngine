#pragma once
#include <glad.h>
#include <glfw3.h>
#include <iostream>
#include "shader.h"
#include "stb_image.h"

const int v = 9;
class rec
{
	float x = 0.8f;
public:

	float vertices[32] = {
		// positions          // colors           // texture coords
		 x,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
		 x, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
		-x, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
		-x,  0.5f, 0.0f,   0.5f, 0.5f, 0.5f,   0.0f, 1.0f  // top left 
	};;

	unsigned int indices[6] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};
	rec()
	{

	}
	rec(int a)
	{

	}
	//void addBufferData();
	//void update(Shader shader);
};

#pragma once
#include "rectangle.h"


/*void rec::addBufferData()
{
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void rec::update(Shader shader)
{
	/*float timeValue = glfwGetTime();
	float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
	float redValue = (sin(timeValue / 3.0f) + 0.5f);
	float blueValue = (sin(timeValue / 4.0f) + 0.5f);
	int vertexColorLocation = glGetUniformLocation(shader.ID, "ourColor");
	glUniform4f(vertexColorLocation, redValue, greenValue, greenValue, 1.0f);
	int xOffset = glGetUniformLocation(shader.ID, "xOffset");
	static float offset = 0;
	offset += 0.005f;
	if (offset >= 1.5f)
		offset = -1.5f;
	glUniform1f(xOffset, offset);
}*/