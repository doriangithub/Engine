#include <GL\glew.h>
#include "MyGLWindow.h"
#include <cassert>
//#include <iostream>


void MyGLWindow::initializeGL()
{
	GLenum errorcode = glewInit();
	assert(errorcode == 0);

	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);

	float verts[] =
	{
		+0.0f, +0.1f,
		-0.1f, -0.1f,
		+0.1f, -0.1f,
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

	connect(&myTimer, SIGNAL(timeout()), this, SLOT(myUpdate()));
	myTimer.start(0);

}

void MyGLWindow::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void MyGLWindow::myUpdate()
{
	//std::cout << "Frame" << std::endl;
}