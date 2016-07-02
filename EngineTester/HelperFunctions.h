#ifndef TESTER_HELPER_FUNCTIONS_H
#define TESTER_HELPER_FUNCTIONS_H
//#include <cmath>

inline bool closeEnough(float left, float right, float treshold = 0.0000001) 
{
	return abs(left - right) < treshold;
}

#endif // !TESTER_HELPER_FUNCTIONS_H