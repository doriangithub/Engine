#ifndef SANDBOX_MY_GL_WINDOW_H
#define SANDBOX_MY_GL_WINDOW_H
#include <QtOpenGL\qgl.h>

class MyGLWindow : public QGLWidget
{
protected:
	void initializeGL();

};

#endif
