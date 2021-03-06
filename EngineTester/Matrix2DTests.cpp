#include <gtest\gtest.h>
#include <Math\Matrix2D.h>
#include <Math\Vector2D.h>
#include "HelperFunctions.h"
#include <Math\Constants.h>
//#define PI 3.14159265358979323846
using Math::Matrix2D;
using Math::Vector2D;

TEST(Matrix2D, Construction)
{
	Matrix2D identity;
	EXPECT_FLOAT_EQ(identity.r0c0, 1.0f);
	EXPECT_FLOAT_EQ(identity.r0c1, 0.0f);
	EXPECT_FLOAT_EQ(identity.r1c0, 0.0f);
	EXPECT_FLOAT_EQ(identity.r1c1, 1.0f);
}

TEST(Matrix2D, MatrixVectorMultiply)
{
	Matrix2D op(2, -3,
				4, -5);
	Vector2D victim(3, 9);
	Vector2D victimPrime = op * victim;
	EXPECT_FLOAT_EQ(victimPrime.x, -21.0f);
	EXPECT_FLOAT_EQ(victimPrime.y, -33.0f);
}

TEST(Matrix2D, Rotation)
{
	Matrix2D op;
	op = Matrix2D::rotate(0);
	EXPECT_FLOAT_EQ(op.r0c0, 1.0f);
	EXPECT_FLOAT_EQ(op.r0c1, 0.0f);
	EXPECT_FLOAT_EQ(op.r1c0, 0.0f);
	EXPECT_FLOAT_EQ(op.r1c1, 1.0f);

	op = Matrix2D::rotate(Math::PI);
	EXPECT_FLOAT_EQ(op.r0c0, -1.0f);
	EXPECT_TRUE( closeEnough( op.r0c1, 0.0f) );
	EXPECT_TRUE( closeEnough(op.r1c0, 0.0f) );
	EXPECT_FLOAT_EQ(op.r1c1, -1.0f);

	op = Matrix2D::rotate(Math::PI / 2);
	EXPECT_TRUE( closeEnough(op.r0c0, 0.0f) );
	EXPECT_FLOAT_EQ(op.r0c1, -1.0f);
	EXPECT_FLOAT_EQ(op.r1c0, 1.0f);
	EXPECT_TRUE( closeEnough(op.r1c1, 0.0f) );

	op = Matrix2D::rotate(Math::PI / 4);
	const float sqrt2over2 = sqrt(2.0f) / 2.0f; //0.7071067811865475;
	EXPECT_FLOAT_EQ(op.r0c0, sqrt2over2);
	EXPECT_FLOAT_EQ(op.r0c1, -sqrt2over2);
	EXPECT_FLOAT_EQ(op.r1c0, sqrt2over2);
	EXPECT_FLOAT_EQ(op.r1c1, sqrt2over2);

	op = Matrix2D::rotate(-Math::PI / 4);
	EXPECT_FLOAT_EQ(op.r0c0, sqrt2over2);
	EXPECT_FLOAT_EQ(op.r0c1, sqrt2over2);
	EXPECT_FLOAT_EQ(op.r1c0, -sqrt2over2);
	EXPECT_FLOAT_EQ(op.r1c1, sqrt2over2);

	op = Matrix2D::rotate(Math::PI / 3);
	const float sqrt3over2 = sqrt(3.0f) / 2.0f; //0.8660254037844386;
	EXPECT_FLOAT_EQ(op.r0c0, 0.5);
	EXPECT_FLOAT_EQ(op.r0c1, -sqrt3over2);
	EXPECT_FLOAT_EQ(op.r1c0, sqrt3over2);
	EXPECT_FLOAT_EQ(op.r1c1, 0.5);

	op = Matrix2D::rotate(-Math::PI / 3);
	EXPECT_FLOAT_EQ(op.r0c0, 0.5);
	EXPECT_FLOAT_EQ(op.r0c1, sqrt3over2);
	EXPECT_FLOAT_EQ(op.r1c0, -sqrt3over2);
	EXPECT_FLOAT_EQ(op.r1c1, 0.5);
} 