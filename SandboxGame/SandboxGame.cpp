#include <QtWidgets\qapplication.h>
#include <QtWidgets\qwidget.h>
#include "MyGLWindow.h"
#include <Windows.h>
#include <QtCore\qdebug.h>

int main(int argc, char* argv[])
{
	//LARGE_INTEGER clockFrequency;
	//QueryPerformanceCounter(&clockFrequency);

	//LARGE_INTEGER startTime;
	//LARGE_INTEGER endTime;
	//QueryPerformanceCounter(&startTime);
	//qDebug() << "Hello";
	//QueryPerformanceCounter(&endTime);

	//LARGE_INTEGER delta;
	//delta.QuadPart = endTime.QuadPart - startTime.QuadPart;

	//float deltaSeconds = ((float)delta.QuadPart) / clockFrequency.QuadPart;


	QApplication app(argc,argv);
	MyGLWindow myGlWindow;
	if (!myGlWindow.initialize())
		return -1;
	myGlWindow.show();

	int errorCode = app.exec();
	if (!myGlWindow.shutdown())
	{
		errorCode |= 1;
	}
	return errorCode;
}