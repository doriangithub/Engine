#include <gtest\gtest.h>
#include "Timing\Clock.h"
#include <QtTest\qtest.h>
//#include <QtCore\qdebug.h>
#include <iostream>
using std::cout;

using Timing::Clock;

TEST(Clock, Initialize)
{
	Clock clock;
	clock.initialize();
	clock.timeElapsedLastFrame();
	clock.shutdown();
}

TEST(Clock, FrameTimeMeasuring)
{
	Clock clock;
#ifdef OVERNIGHT_TESTS
	EXPECT_TRUE(clock.initialize());
	clock.newFrame();
	QTest::qSleep(1000);
	clock.newFrame();
	float timedTime = clock.timeElapsedLastFrame();
	EXPECT_TRUE(0.9f < timedTime);
	EXPECT_TRUE(timedTime < 1.1f);

	clock.newFrame();
	QTest::qSleep(500);
	clock.newFrame();
	timedTime = clock.timeElapsedLastFrame();
	EXPECT_TRUE(0.4f < timedTime);
	EXPECT_TRUE(timedTime < 0.6f);

	const int NUM_TESTS = 10 + rand() % 100;
	const float THRESHHOLD = 0.01f;
	for (int i = 0; i < NUM_TESTS; i++)
	{
		cout << ".";
		int thisTestTimeMilliseconds = rand() % 10000;
		float thisTestTimeSeconds = thisTestTimeMilliseconds / 1000.0f;

		clock.newFrame();
		QTest::qSleep(thisTestTimeMilliseconds);
		clock.newFrame();
		float elapsedSeconds = clock.timeElapsedLastFrame();
		EXPECT_TRUE( (thisTestTimeSeconds - THRESHHOLD) < elapsedSeconds );
		EXPECT_TRUE( elapsedSeconds < (thisTestTimeSeconds + THRESHHOLD) );
	}
#endif // OVERNIGHT_TESTS

	clock.newFrame();
	clock.timeElapsedLastFrame();
	EXPECT_TRUE(clock.shutdown());
}