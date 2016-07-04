#ifndef ENGINE_MATRIX_3D_H
#define ENGINE_MATRIX_3D_H
#include "Vector3D.h"

namespace Math
{
	struct Matrix3D
	{
		float r0c0;
		float r0c1;
		float r0c2;
		float r1c0;
		float r1c1;
		float r1c2;
		float r2c0;
		float r2c1;
		float r2c2;
	};

	inline Vector3D operator*(const Matrix3D& matrix, const Vector3D& right);

#include "Matrix3D.inl"
}

#endif //ENGINE_MATRIX_3D_H



