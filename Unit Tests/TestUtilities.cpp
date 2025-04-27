#include "TestUtilities.h"

TestUtilities::TestUtilities() : mRandomEngine(6) {}

float TestUtilities::GetRandomFloat(float aMin, float aMax) {
	std::uniform_real_distribution<float> rnd(aMin, aMax);
	return rnd(mRandomEngine);
}

double TestUtilities::GetRandomDouble(double aMin, double aMax) {
	std::uniform_real_distribution<double> rnd(aMin, aMax);
	return rnd(mRandomEngine);
}

int TestUtilities::GetRandomInt(int aMin, int aMax) {
	std::uniform_int_distribution<int> rnd(aMin, aMax);
	return rnd(mRandomEngine);
}
