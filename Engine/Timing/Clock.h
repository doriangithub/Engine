#ifndef ENGINE_CLOCK_H
#define ENGINE_CLOCK_H
#include <Windows.h>

namespace Timing
{

	class __declspec(dllexport) Clock   // make fuction viisble out of dll
	{	
		LARGE_INTEGER timeFrequency;
		LARGE_INTEGER timeLastFrame;
		LARGE_INTEGER deltaLAstFrame;
		float deltaTime;
	public:
		bool initialize();
		bool shutdown();
		void newFrame();
		float timeElapsedLastFrame() const;
	};
}

#endif // !ENGINE_CLOCK_H#pragma once
