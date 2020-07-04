#pragma once
#include "rectangle.h"


void Rectangle::addBufferData()
{
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void Rectangle::update(Shader shader)
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
	glUniform1f(xOffset, offset);*/
}