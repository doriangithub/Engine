#include <gtest\gtest.h>
#include <Math\Matrix3D.h>
#include <Math\Vector3D.h>
#include "HelperFunctions.h"
#include <Math\Constants.h>
using Math::Matrix3D;
using Math::Vector3D;

TEST(Matrix3D, Conctractor)
{
	Matrix3D identity;
	EXPECT_FLOAT_EQ(identity.r0c0, 1.0f);
	EXPECT_FLOAT_EQ(identity.r0c1, 0.0f);
	EXPECT_FLOAT_EQ(identity.r0c2, 0.0f);
	EXPECT_FLOAT_EQ(identity.r1c0, 0.0f);
	EXPECT_FLOAT_EQ(identity.r1c1, 1.0f);
	EXPECT_FLOAT_EQ(identity.r1c2, 0.0f);
	EXPECT_FLOAT_EQ(identity.r2c0, 0.0f);
	EXPECT_FLOAT_EQ(identity.r2c1, 0.0f);
	EXPECT_FLOAT_EQ(identity.r2c2, 1.0f);


	Matrix3D victim(
		1.0f, 2.0f, 3.0f,
		4.0f, 5.0f, 6.0f,
		7.0f, 8.0f, 9.0f);
	EXPECT_FLOAT_EQ(victim.r0c0, 1.0f);
	EXPECT_FLOAT_EQ(victim.r0c1, 2.0f);
	EXPECT_FLOAT_EQ(victim.r0c2, 3.0f);
	EXPECT_FLOAT_EQ(victim.r1c0, 4.0f);
	EXPECT_FLOAT_EQ(victim.r1c1, 5.0f);
	EXPECT_FLOAT_EQ(victim.r1c2, 6.0f);
	EXPECT_FLOAT_EQ(victim.r2c0, 7.0f);
	EXPECT_FLOAT_EQ(victim.r2c1, 8.0f);
	EXPECT_FLOAT_EQ(victim.r2c2, 9.0f);
}

TEST(Matrix3D, MatrixVectorMultiply)
{
	Matrix3D op(
		1.0f, 2.0f, 3.0f,
		4.0f, 5.0f, 6.0f,
		7.0f, 8.0f, 9.0f);

	Vector3D victim(1.0f, 2.0f, 3.0f);

	Vector3D victimPrime = op * victim;
	EXPECT_FLOAT_EQ(victimPrime.x, 14.0f);
	EXPECT_FLOAT_EQ(victimPrime.y, 32.0f);
	EXPECT_FLOAT_EQ(victimPrime.z, 50.0f);
}


TEST(Matrix3D, Rotation)
{
	Matrix3D op;
	op = Matrix3D::rotateZ(0);
	EXPECT_FLOAT_EQ(op.r0c0, 1.0f);
	EXPECT_FLOAT_EQ(op.r0c1, 0.0f);
	EXPECT_FLOAT_EQ(op.r0c2, 0.0f);
	EXPECT_FLOAT_EQ(op.r1c0, 0.0f);
	EXPECT_FLOAT_EQ(op.r1c1, 1.0f);
	EXPECT_FLOAT_EQ(op.r1c2, 0.0f);
	EXPECT_FLOAT_EQ(op.r2c0, 0.0f);
	EXPECT_FLOAT_EQ(op.r2c1, 0.0f);
	EXPECT_FLOAT_EQ(op.r2c2, 1.0f);

	op = Matrix3D::rotateZ(Math::PI);
	EXPECT_FLOAT_EQ(op.r0c0, -1.0f);
	EXPECT_TRUE(closeEnough(op.r0c1, 0.0f));
	EXPECT_FLOAT_EQ(op.r0c2, 0.0f);
	EXPECT_TRUE(closeEnough(op.r1c0, 0.0f));
	EXPECT_FLOAT_EQ(op.r1c1, -1.0f);
	EXPECT_FLOAT_EQ(op.r1c2, 0.0f);
	EXPECT_FLOAT_EQ(op.r2c0, 0.0f);
	EXPECT_FLOAT_EQ(op.r2c1, 0.0f);
	EXPECT_FLOAT_EQ(op.r2c2, 1.0f);

	op = Matrix3D::rotateZ(Math::PI / 2);
	EXPECT_TRUE(closeEnough(op.r0c0, 0.0f));
	EXPECT_FLOAT_EQ(op.r0c1, -1.0f);
	EXPECT_FLOAT_EQ(op.r0c2, 0.0f);
	EXPECT_FLOAT_EQ(op.r1c0, 1.0f);
	EXPECT_TRUE(closeEnough(op.r1c1, 0.0f));
	EXPECT_FLOAT_EQ(op.r1c2, 0.0f);
	EXPECT_FLOAT_EQ(op.r2c0, 0.0f);
	EXPECT_FLOAT_EQ(op.r2c1, 0.0f);
	EXPECT_FLOAT_EQ(op.r2c2, 1.0f);

	op = Matrix3D::rotateZ(Math::PI / 4);
	const float sqrt2over2 = sqrt(2.0f) / 2.0f; //0.7071067811865475;
	EXPECT_FLOAT_EQ(op.r0c0, sqrt2over2);
	EXPECT_FLOAT_EQ(op.r0c1, -sqrt2over2);
	EXPECT_FLOAT_EQ(op.r0c2, 0.0f);
	EXPECT_FLOAT_EQ(op.r1c0, sqrt2over2);
	EXPECT_FLOAT_EQ(op.r1c1, sqrt2over2);
	EXPECT_FLOAT_EQ(op.r1c2, 0.0f);
	EXPECT_FLOAT_EQ(op.r2c0, 0.0f);
	EXPECT_FLOAT_EQ(op.r2c1, 0.0f);
	EXPECT_FLOAT_EQ(op.r2c2, 1.0f);

	op = Matrix3D::rotateZ(-Math::PI / 4);
	EXPECT_FLOAT_EQ(op.r0c0, sqrt2over2);
	EXPECT_FLOAT_EQ(op.r0c1, sqrt2over2);
	EXPECT_FLOAT_EQ(op.r0c2, 0.0f);
	EXPECT_FLOAT_EQ(op.r1c0, -sqrt2over2);
	EXPECT_FLOAT_EQ(op.r1c1, sqrt2over2);
	EXPECT_FLOAT_EQ(op.r1c2, 0.0f);
	EXPECT_FLOAT_EQ(op.r2c0, 0.0f);
	EXPECT_FLOAT_EQ(op.r2c1, 0.0f);
	EXPECT_FLOAT_EQ(op.r2c2, 1.0f);

	op = Matrix3D::rotateZ(Math::PI / 3);
	const float sqrt3over2 = sqrt(3.0f) / 2.0f; //0.8660254037844386;
	EXPECT_FLOAT_EQ(op.r0c0, 0.5);
	EXPECT_FLOAT_EQ(op.r0c1, -sqrt3over2);
	EXPECT_FLOAT_EQ(op.r1c0, sqrt3over2);
	EXPECT_FLOAT_EQ(op.r1c1, 0.5);
	EXPECT_FLOAT_EQ(op.r1c2, 0.0f);
	EXPECT_FLOAT_EQ(op.r2c0, 0.0f);
	EXPECT_FLOAT_EQ(op.r2c1, 0.0f);
	EXPECT_FLOAT_EQ(op.r2c2, 1.0f);

	op = Matrix3D::rotateZ(-Math::PI / 3);
	EXPECT_FLOAT_EQ(op.r0c0, 0.5);
	EXPECT_FLOAT_EQ(op.r0c1, sqrt3over2);
	EXPECT_FLOAT_EQ(op.r0c2, 0.0f);
	EXPECT_FLOAT_EQ(op.r1c0, -sqrt3over2);
	EXPECT_FLOAT_EQ(op.r1c1, 0.5);
	EXPECT_FLOAT_EQ(op.r1c2, 0.0f);
	EXPECT_FLOAT_EQ(op.r2c0, 0.0f);
	EXPECT_FLOAT_EQ(op.r2c1, 0.0f);
	EXPECT_FLOAT_EQ(op.r2c2, 1.0f);
}

TEST(Matrix3D, Translation)
{
	Matrix3D translator = Matrix3D::translate(4, 8);
	Vector3D victim(-3, 8, 1);
	Vector3D victimPrime = translator * victim;
	EXPECT_FLOAT_EQ(victimPrime.x, 1.0f);
	EXPECT_FLOAT_EQ(victimPrime.y, 16);
	EXPECT_FLOAT_EQ(victimPrime.z, 1);
}

TEST(Matrix3D, MatrixMatrixMultiply)
{
	Matrix3D theMatrix( 1, 2, 3,
						4, 5, 6,
						7, 8, 9 );
	Matrix3D rezult = theMatrix * theMatrix;
	EXPECT_FLOAT_EQ(rezult.r0c0, 30);
	EXPECT_FLOAT_EQ(rezult.r0c1, 36);
	EXPECT_FLOAT_EQ(rezult.r0c2, 42);

	EXPECT_FLOAT_EQ(rezult.r1c0, 66);
	EXPECT_FLOAT_EQ(rezult.r1c1, 81);
	EXPECT_FLOAT_EQ(rezult.r1c2, 96);

	EXPECT_FLOAT_EQ(rezult.r2c0, 102);
	EXPECT_FLOAT_EQ(rezult.r2c1, 126);
	EXPECT_FLOAT_EQ(rezult.r2c2, 150);
}