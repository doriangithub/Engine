#include <GL\glew.h>
#include "MyGLWindow.h"
#include <cassert>
#include <QtGui\qevent.h>
#include <Math\Vector2D.h>
#include <Timing\Clock.h>
#include <Math\Matrix2D.h>
#include <algorithm> 
using Math::Vector2D;
using Math::Matrix2D;
using Timing::Clock;
using std::min;

namespace
{
	Vector2D verts[] =
	{
		Vector2D(+0.0f, +0.1414213562373095f),
		Vector2D(-0.1f, -0.1f),
		Vector2D(+0.1f, -0.1f),
	};

	const unsigned int NUM_VERTS = sizeof(verts) / sizeof(*verts);

	Vector2D shipPosition;
	Vector2D shipVelocity;
	float shipOrientation = 0.0f;
	Clock clock;
}

void MyGLWindow::initializeGL()
{
	GLenum errorcode = glewInit();
	assert(errorcode == 0);

	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);

	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), NULL, GL_DYNAMIC_DRAW);

	connect(&myTimer, SIGNAL(timeout()), this, SLOT(myUpdate()));
	myTimer.start(0);

}

void MyGLWindow::paintGL()
{
	int minSize = min( width(), height() );
	Vector2D viewportLocation;
	viewportLocation.x = width() / 2 - minSize / 2;
	viewportLocation.y = height() / 2 - minSize / 2;
	glViewport(viewportLocation.x, viewportLocation.y, minSize, minSize);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	Vector2D translatedVerts[NUM_VERTS];
	Matrix2D op = Matrix2D::rotate(shipOrientation);
	for (unsigned int i = 0; i < NUM_VERTS; i++)
	{
		translatedVerts[i] = shipPosition + ( op * verts[i] ); // +shipPosition;
	}
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(translatedVerts), translatedVerts);

	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void MyGLWindow::myUpdate()
{
	clock.newFrame();
	rotateShip();
	updateVelocity();
	shipPosition += shipVelocity * clock.timeElapsedLastFrame();
	repaint();
}

bool MyGLWindow::initialize()
{
	return clock.initialize();
}

bool MyGLWindow::shutdown()
{
	return clock.shutdown();
}

void MyGLWindow::rotateShip() 
{
	const float ANGULAR_MOVEMENT = 0.001f;

	if (GetAsyncKeyState(VK_LEFT))
		shipOrientation += ANGULAR_MOVEMENT;
	if (GetAsyncKeyState(VK_RIGHT))
		shipOrientation -= ANGULAR_MOVEMENT;
}

void MyGLWindow::updateVelocity()
{
	const float ACCELERATION = 0.3f * clock.timeElapsedLastFrame();

	Vector2D directionToAccelerate(-sin(shipOrientation), cos(shipOrientation));

	if (GetAsyncKeyState(VK_UP))
		shipVelocity += directionToAccelerate * ACCELERATION;
	if (GetAsyncKeyState(VK_DOWN))
		shipVelocity -= directionToAccelerate * ACCELERATION;
}