#include <gtest\gtest.h>
#include <Math\Vector3D.h>
using Math::Vector3D;

TEST(Vector3D, Constructor)
{
	Vector3D instance(-4.3f, 9.1f, 5.0f);
	EXPECT_FLOAT_EQ(instance.x, -4.3f);
	EXPECT_FLOAT_EQ(instance.y, 9.1f);
	EXPECT_FLOAT_EQ(instance.z, 5.0f);

	Vector3D defaultConstructor;
	EXPECT_FLOAT_EQ(defaultConstructor.x, 0.0f);
	EXPECT_FLOAT_EQ(defaultConstructor.y, 0.0f);
	EXPECT_FLOAT_EQ(defaultConstructor.z, 0.0f);
}

TEST(Vector3D, VectorAddition)
{
	Vector3D first(9, -2, 5);
	Vector3D second(-4, 5.4f, 7);
	Vector3D rezult = first + second;
	EXPECT_FLOAT_EQ(rezult.x, 5);
	EXPECT_FLOAT_EQ(rezult.y, 3.4f);
	EXPECT_FLOAT_EQ(rezult.z, 12);
}

TEST(Vector3D, ScalarMultiplication)
{
	Vector3D instance( 1.0f, 2.0f, 3.0f );
	Vector3D multiplied1 = 5 * instance;
	Vector3D multiplied2 = instance * 5;

	EXPECT_FLOAT_EQ(multiplied1.x, 5.0f);
	EXPECT_FLOAT_EQ(multiplied1.y, 10.0f);
	EXPECT_FLOAT_EQ(multiplied1.z, 15.0f);

	EXPECT_FLOAT_EQ(multiplied1.x, multiplied2.x);
	EXPECT_FLOAT_EQ(multiplied1.y, multiplied2.y);
	EXPECT_FLOAT_EQ(multiplied1.z, multiplied2.z);
}
