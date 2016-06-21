#include <gtest\gtest.h>

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
	EXPECT_TRUE(clock.initialize());
	sleep(1000);
	clock.newFrame();
	float timedTime = clock.timeElapsedLastFrame();
	EXPECT_TRUE(0.9f < timedTime);
	EXPECT_TRUE(timedTime < 1.1f);

	clock.newFrame();
	sleep(500);
	clock.newFrame();
	timedTime = clock.timeElapsedLastFrame();
	EXPECT_TRUE(0.4f < timedTime);
	EXPECT_TRUE(timedTime < 0.6f);

	const int NUM_TESTS = 10 + rand() % 100;
	const float THRESHHOLD = 0.1f;
	for (int i = 0, i < NUM_TESTS; i++)
	{
		int thisTestTimeMilliseconds = rand() % 10000;
		float thisTestTimeSeconds = thisTestTimeMilliseconds / 1000.0f;

		clock.newFrame();
		sleep(thisTestTimeMilliseconds);
		clock.newFrame();
		float elapsedSeconds = clock.timeElapsedLastFrame();
		EXPECT_TRUE( (thisTestTimeSeconds - THRESHHOLD) < elapsedSeconds );
		EXPECT_TRUE( elapsedSeconds < (thisTestTimeSeconds + THRESHHOLD) );
	}

	clock.newFrame();
	clock.timeElapsedLastFrame();
	EXPECT_TRUE(clock.shutdown());
}