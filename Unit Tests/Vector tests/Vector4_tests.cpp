#include "gtest/gtest.h"

#include "Math/Vector4.h"
#include "../TestUtilities.h"

constexpr float floatMargin = 0.0000001f;
constexpr double doubleMargin = 0.0000001;

TestUtilities testUtilsVec4;

TEST(Vector4_tests, Constructors) {
	const OMath::Vector4<int> vectorDefaultI;
	EXPECT_EQ(vectorDefaultI.mX, 0);
	EXPECT_EQ(vectorDefaultI.mY, 0);
	EXPECT_EQ(vectorDefaultI.mZ, 0);
	EXPECT_EQ(vectorDefaultI.mW, 0);

	const OMath::Vector4<float> vectorDefaultF;
	EXPECT_EQ(vectorDefaultF.mX, 0);
	EXPECT_EQ(vectorDefaultF.mY, 0);
	EXPECT_EQ(vectorDefaultF.mZ, 0);
	EXPECT_EQ(vectorDefaultF.mW, 0);

	const OMath::Vector4<double> vectorDefaultD;
	EXPECT_EQ(vectorDefaultD.mX, 0);
	EXPECT_EQ(vectorDefaultD.mY, 0);
	EXPECT_EQ(vectorDefaultD.mZ, 0);
	EXPECT_EQ(vectorDefaultD.mW, 0);

	for (int i = 0; i < 100; ++i) {
		const int x = testUtilsVec4.GetRandomInt();
		const int y = testUtilsVec4.GetRandomInt();
		const int z = testUtilsVec4.GetRandomInt();
		const int w = testUtilsVec4.GetRandomInt();

		const OMath::Vector4<int> vector(x, y, z, w);
		EXPECT_EQ(vector.mX, x);
		EXPECT_EQ(vector.mY, y);
		EXPECT_EQ(vector.mZ, z);
		EXPECT_EQ(vector.mW, w);
	}

	for (int i = 0; i < 100; ++i) {
		const float x = testUtilsVec4.GetRandomFloat();
		const float y = testUtilsVec4.GetRandomFloat();
		const float z = testUtilsVec4.GetRandomFloat();
		const float w = testUtilsVec4.GetRandomFloat();

		const OMath::Vector4<float> vector(x, y, z, w);
		EXPECT_EQ(vector.mX, x);
		EXPECT_EQ(vector.mY, y);
		EXPECT_EQ(vector.mZ, z);
		EXPECT_EQ(vector.mW, w);
	}

	for (int i = 0; i < 100; ++i) {
		const double x = testUtilsVec4.GetRandomDouble();
		const double y = testUtilsVec4.GetRandomDouble();
		const double z = testUtilsVec4.GetRandomDouble();
		const double w = testUtilsVec4.GetRandomDouble();

		const OMath::Vector4<double> vector(x, y, z, w);
		EXPECT_EQ(vector.mX, x);
		EXPECT_EQ(vector.mY, y);
		EXPECT_EQ(vector.mZ, z);
		EXPECT_EQ(vector.mW, w);
	}

	for (int i = 0; i < 100; ++i) {
		const int x = testUtilsVec4.GetRandomInt();
		const int y = testUtilsVec4.GetRandomInt();
		const int z = testUtilsVec4.GetRandomInt();
		const int w = testUtilsVec4.GetRandomInt();

		const OMath::Vector4<int> vector(x, y, z, w);
		const auto copyVector(vector);
		EXPECT_EQ(copyVector.mX, x);
		EXPECT_EQ(copyVector.mY, y);
		EXPECT_EQ(copyVector.mZ, z);
		EXPECT_EQ(copyVector.mW, w);
	}

	for (int i = 0; i < 100; ++i) {
		const float x = testUtilsVec4.GetRandomFloat();
		const float y = testUtilsVec4.GetRandomFloat();
		const float z = testUtilsVec4.GetRandomFloat();
		const float w = testUtilsVec4.GetRandomFloat();

		const OMath::Vector4<float> vector(x, y, z, w);
		const auto copyVector(vector);
		EXPECT_EQ(copyVector.mX, x);
		EXPECT_EQ(copyVector.mY, y);
		EXPECT_EQ(copyVector.mZ, z);
		EXPECT_EQ(copyVector.mW, w);
	}

	for (int i = 0; i < 100; ++i) {
		const double x = testUtilsVec4.GetRandomDouble();
		const double y = testUtilsVec4.GetRandomDouble();
		const double z = testUtilsVec4.GetRandomDouble();
		const double w = testUtilsVec4.GetRandomDouble();

		const OMath::Vector4<double> vector(x, y, z, w);
		const auto copyVector(vector);
		EXPECT_EQ(copyVector.mX, x);
		EXPECT_EQ(copyVector.mY, y);
		EXPECT_EQ(copyVector.mZ, z);
		EXPECT_EQ(copyVector.mW, w);
	}
}

TEST(Vector4_tests, Assignment) {
	for (int i = 0; i < 100; i++) {
		const auto x = testUtilsVec4.GetRandomFloat();
		const auto y = testUtilsVec4.GetRandomFloat();
		const auto z = testUtilsVec4.GetRandomFloat();
		const auto w = testUtilsVec4.GetRandomFloat();

		const OMath::Vector4<float> originalVec(x, y, z, w);
		auto copyVector = originalVec;
		EXPECT_EQ(copyVector.mX, x);
		EXPECT_EQ(copyVector.mY, y);
		EXPECT_EQ(copyVector.mZ, z);
		EXPECT_EQ(copyVector.mW, w);
	}

	for (int i = 0; i < 100; i++) {
		const auto x = testUtilsVec4.GetRandomDouble();
		const auto y = testUtilsVec4.GetRandomDouble();
		const auto z = testUtilsVec4.GetRandomDouble();
		const auto w = testUtilsVec4.GetRandomDouble();

		const OMath::Vector4<double> originalVec(x, y, z, w);
		auto copyVector = originalVec;
		EXPECT_EQ(copyVector.mX, x);
		EXPECT_EQ(copyVector.mY, y);
		EXPECT_EQ(copyVector.mZ, z);
		EXPECT_EQ(copyVector.mW, w);
	}

	for (int i = 0; i < 100; i++) {
		const auto x = testUtilsVec4.GetRandomInt();
		const auto y = testUtilsVec4.GetRandomInt();
		const auto z = testUtilsVec4.GetRandomInt();
		const auto w = testUtilsVec4.GetRandomInt();

		const OMath::Vector4<int> originalVec(x, y, z, w);
		auto copyVector = originalVec;
		EXPECT_EQ(copyVector.mX, x);
		EXPECT_EQ(copyVector.mY, y);
		EXPECT_EQ(copyVector.mZ, z);
		EXPECT_EQ(copyVector.mW, w);
	}
}

TEST(Vector4_tests, Addition) {
	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec4.GetRandomFloat();
		const auto y1 = testUtilsVec4.GetRandomFloat();
		const auto z1 = testUtilsVec4.GetRandomFloat();
		const auto w1 = testUtilsVec4.GetRandomFloat();

		const auto x2 = testUtilsVec4.GetRandomFloat();
		const auto y2 = testUtilsVec4.GetRandomFloat();
		const auto z2 = testUtilsVec4.GetRandomFloat();
		const auto w2 = testUtilsVec4.GetRandomFloat();

		const OMath::Vector4<float> vector1(x1, y1, z1, w1);
		const OMath::Vector4<float> Vector4(x2, y2, z2, w2);
		const auto resultVector = vector1 + Vector4;

		EXPECT_NEAR(resultVector.mX, x1 + x2, floatMargin);
		EXPECT_NEAR(resultVector.mY, y1 + y2, floatMargin);
		EXPECT_NEAR(resultVector.mZ, z1 + z2, floatMargin);
		EXPECT_NEAR(resultVector.mW, w1 + w2, floatMargin);

		const auto x3 = testUtilsVec4.GetRandomFloat();
		const auto y3 = testUtilsVec4.GetRandomFloat();
		const auto z3 = testUtilsVec4.GetRandomFloat();
		const auto w3 = testUtilsVec4.GetRandomFloat();

		OMath::Vector4<float> vector4(x3, y3, z3, w3);
		vector4 += resultVector;

		const float xResult = x1 + x2 + x3;
		const float yResult = y1 + y2 + y3;
		const float zResult = z1 + z2 + z3;
		const float wResult = w1 + w2 + w3;
		EXPECT_NEAR(vector4.mX, xResult, floatMargin);
		EXPECT_NEAR(vector4.mY, yResult, floatMargin);
		EXPECT_NEAR(vector4.mZ, zResult, floatMargin);
		EXPECT_NEAR(vector4.mW, wResult, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec4.GetRandomDouble();
		const auto y1 = testUtilsVec4.GetRandomDouble();
		const auto z1 = testUtilsVec4.GetRandomDouble();
		const auto w1 = testUtilsVec4.GetRandomDouble();

		const auto x2 = testUtilsVec4.GetRandomDouble();
		const auto y2 = testUtilsVec4.GetRandomDouble();
		const auto z2 = testUtilsVec4.GetRandomDouble();
		const auto w2 = testUtilsVec4.GetRandomDouble();

		const OMath::Vector4<double> vector1(x1, y1, z1, w1);
		const OMath::Vector4<double> Vector4(x2, y2, z2, w2);
		const auto resultVector = vector1 + Vector4;

		EXPECT_NEAR(resultVector.mX, x1 + x2, doubleMargin);
		EXPECT_NEAR(resultVector.mY, y1 + y2, doubleMargin);
		EXPECT_NEAR(resultVector.mZ, z1 + z2, doubleMargin);
		EXPECT_NEAR(resultVector.mW, w1 + w2, doubleMargin);

		const auto x3 = testUtilsVec4.GetRandomDouble();
		const auto y3 = testUtilsVec4.GetRandomDouble();
		const auto z3 = testUtilsVec4.GetRandomDouble();
		const auto w3 = testUtilsVec4.GetRandomDouble();

		OMath::Vector4<double> vector4(x3, y3, z3, w3);
		vector4 += resultVector;

		const auto xResult = x1 + x2 + x3;
		const auto yResult = y1 + y2 + y3;
		const auto zResult = z1 + z2 + z3;
		const auto wResult = w1 + w2 + w3;
		EXPECT_NEAR(vector4.mX, xResult, doubleMargin);
		EXPECT_NEAR(vector4.mY, yResult, doubleMargin);
		EXPECT_NEAR(vector4.mZ, zResult, doubleMargin);
		EXPECT_NEAR(vector4.mW, wResult, doubleMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec4.GetRandomInt();
		const auto y1 = testUtilsVec4.GetRandomInt();
		const auto z1 = testUtilsVec4.GetRandomInt();
		const auto w1 = testUtilsVec4.GetRandomInt();

		const auto x2 = testUtilsVec4.GetRandomInt();
		const auto y2 = testUtilsVec4.GetRandomInt();
		const auto z2 = testUtilsVec4.GetRandomInt();
		const auto w2 = testUtilsVec4.GetRandomInt();

		const OMath::Vector4<int> vector1(x1, y1, z1, w1);
		const OMath::Vector4<int> Vector4(x2, y2, z2, w2);
		const auto resultVector = vector1 + Vector4;

		EXPECT_EQ(resultVector.mX, x1 + x2);
		EXPECT_EQ(resultVector.mY, y1 + y2);
		EXPECT_EQ(resultVector.mZ, z1 + z2);
		EXPECT_EQ(resultVector.mW, w1 + w2);

		const auto x3 = testUtilsVec4.GetRandomInt();
		const auto y3 = testUtilsVec4.GetRandomInt();
		const auto z3 = testUtilsVec4.GetRandomInt();
		const auto w3 = testUtilsVec4.GetRandomInt();

		OMath::Vector4<int> vector4(x3, y3, z3, w3);
		vector4 += resultVector;

		const auto xResult = x1 + x2 + x3;
		const auto yResult = y1 + y2 + y3;
		const auto zResult = z1 + z2 + z3;
		const auto wResult = w1 + w2 + w3;
		EXPECT_EQ(vector4.mX, x1 + x2 + x3);
		EXPECT_EQ(vector4.mY, y1 + y2 + y3);
		EXPECT_EQ(vector4.mZ, z1 + z2 + z3);
		EXPECT_EQ(vector4.mW, w1 + w2 + w3);
	}
}

TEST(Vector4_tests, Subtraction) {
	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec4.GetRandomFloat();
		const auto y1 = testUtilsVec4.GetRandomFloat();
		const auto z1 = testUtilsVec4.GetRandomFloat();
		const auto w1 = testUtilsVec4.GetRandomFloat();

		const auto x2 = testUtilsVec4.GetRandomFloat();
		const auto y2 = testUtilsVec4.GetRandomFloat();
		const auto z2 = testUtilsVec4.GetRandomFloat();
		const auto w2 = testUtilsVec4.GetRandomFloat();

		const OMath::Vector4<float> vector1(x1, y1, z1, w1);
		const OMath::Vector4<float> Vector4(x2, y2, z2, w2);
		const auto resultVector = vector1 - Vector4;

		EXPECT_NEAR(resultVector.mX, x1 - x2, floatMargin);
		EXPECT_NEAR(resultVector.mY, y1 - y2, floatMargin);
		EXPECT_NEAR(resultVector.mZ, z1 - z2, floatMargin);
		EXPECT_NEAR(resultVector.mW, w1 - w2, floatMargin);

		const auto x3 = testUtilsVec4.GetRandomFloat();
		const auto y3 = testUtilsVec4.GetRandomFloat();
		const auto z3 = testUtilsVec4.GetRandomFloat();
		const auto w3 = testUtilsVec4.GetRandomFloat();

		OMath::Vector4<float> vector4(x3, y3, z3, w3);
		vector4 -= resultVector;

		const auto xValue = x3 - (x1 - x2);
		const auto yValue = y3 - (y1 - y2);
		const auto zValue = z3 - (z1 - z2);
		const auto wValue = w3 - (w1 - w2);

		EXPECT_NEAR(vector4.mX, xValue, floatMargin);
		EXPECT_NEAR(vector4.mY, yValue, floatMargin);
		EXPECT_NEAR(vector4.mZ, zValue, floatMargin);
		EXPECT_NEAR(vector4.mW, wValue, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec4.GetRandomDouble();
		const auto y1 = testUtilsVec4.GetRandomDouble();
		const auto z1 = testUtilsVec4.GetRandomDouble();
		const auto w1 = testUtilsVec4.GetRandomDouble();

		const auto x2 = testUtilsVec4.GetRandomDouble();
		const auto y2 = testUtilsVec4.GetRandomDouble();
		const auto z2 = testUtilsVec4.GetRandomDouble();
		const auto w2 = testUtilsVec4.GetRandomDouble();

		const OMath::Vector4<double> vector1(x1, y1, z1, w1);
		const OMath::Vector4<double> Vector4(x2, y2, z2, w2);
		const auto resultVector = vector1 - Vector4;

		EXPECT_NEAR(resultVector.mX, x1 - x2, doubleMargin);
		EXPECT_NEAR(resultVector.mY, y1 - y2, doubleMargin);
		EXPECT_NEAR(resultVector.mZ, z1 - z2, doubleMargin);
		EXPECT_NEAR(resultVector.mW, w1 - w2, doubleMargin);

		const auto x3 = testUtilsVec4.GetRandomDouble();
		const auto y3 = testUtilsVec4.GetRandomDouble();
		const auto z3 = testUtilsVec4.GetRandomDouble();
		const auto w3 = testUtilsVec4.GetRandomDouble();

		OMath::Vector4<double> vector4(x3, y3, z3, w3);
		vector4 -= resultVector;

		const auto xValue = x3 - (x1 - x2);
		const auto yValue = y3 - (y1 - y2);
		const auto zValue = z3 - (z1 - z2);
		const auto wValue = w3 - (w1 - w2);

		EXPECT_NEAR(vector4.mX, xValue, floatMargin);
		EXPECT_NEAR(vector4.mY, yValue, floatMargin);
		EXPECT_NEAR(vector4.mZ, zValue, floatMargin);
		EXPECT_NEAR(vector4.mW, wValue, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec4.GetRandomInt();
		const auto y1 = testUtilsVec4.GetRandomInt();
		const auto z1 = testUtilsVec4.GetRandomInt();
		const auto w1 = testUtilsVec4.GetRandomInt();

		const auto x2 = testUtilsVec4.GetRandomInt();
		const auto y2 = testUtilsVec4.GetRandomInt();
		const auto z2 = testUtilsVec4.GetRandomInt();
		const auto w2 = testUtilsVec4.GetRandomInt();

		const auto x3 = testUtilsVec4.GetRandomInt();
		const auto y3 = testUtilsVec4.GetRandomInt();
		const auto z3 = testUtilsVec4.GetRandomInt();
		const auto w3 = testUtilsVec4.GetRandomInt();

		const OMath::Vector4<int> vector1(x1, y1, z1, w1);
		const OMath::Vector4<int> Vector4(x2, y2, z2, w2);
		const auto resultVector = vector1 - Vector4;

		EXPECT_EQ(resultVector.mX, x1 - x2);
		EXPECT_EQ(resultVector.mY, y1 - y2);
		EXPECT_EQ(resultVector.mZ, z1 - z2);
		EXPECT_EQ(resultVector.mW, w1 - w2);

		OMath::Vector4<int> vector4(x3, y3, z3, w3);
		vector4 -= resultVector;

		const auto xValue = x3 - (x1 - x2);
		const auto yValue = y3 - (y1 - y2);
		const auto zValue = z3 - (z1 - z2);
		const auto wValue = w3 - (w1 - w2);

		EXPECT_EQ(vector4.mX, xValue);
		EXPECT_EQ(vector4.mY, yValue);
		EXPECT_EQ(vector4.mZ, zValue);
		EXPECT_EQ(vector4.mW, wValue);
	}
}

TEST(Vector4_tests, Multiplication) {
	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec4.GetRandomFloat();
		const auto y1 = testUtilsVec4.GetRandomFloat();
		const auto z1 = testUtilsVec4.GetRandomFloat();
		const auto w1 = testUtilsVec4.GetRandomFloat();

		const auto x2 = testUtilsVec4.GetRandomFloat();
		const auto y2 = testUtilsVec4.GetRandomFloat();
		const auto z2 = testUtilsVec4.GetRandomFloat();
		const auto w2 = testUtilsVec4.GetRandomFloat();

		const OMath::Vector4<float> vector1(x1, y1, z1, w1);
		const OMath::Vector4<float> Vector4(x2, y2, z2, w2);
		const auto resultVector = vector1 * Vector4;

		EXPECT_NEAR(resultVector.mX, x1 * x2, floatMargin);
		EXPECT_NEAR(resultVector.mY, y1 * y2, floatMargin);
		EXPECT_NEAR(resultVector.mZ, z1 * z2, floatMargin);
		EXPECT_NEAR(resultVector.mW, w1 * w2, floatMargin);

		const auto x3 = testUtilsVec4.GetRandomFloat();
		const auto y3 = testUtilsVec4.GetRandomFloat();
		const auto z3 = testUtilsVec4.GetRandomFloat();
		const auto w3 = testUtilsVec4.GetRandomFloat();

		OMath::Vector4<float> vector4(x3, y3, z3, w3);
		vector4 *= resultVector;

		const auto xValue = x3 * (x1 * x2);
		const auto yValue = y3 * (y1 * y2);
		const auto zValue = z3 * (z1 * z2);
		const auto wValue = w3 * (w1 * w2);

		EXPECT_NEAR(vector4.mX, xValue, floatMargin);
		EXPECT_NEAR(vector4.mY, yValue, floatMargin);
		EXPECT_NEAR(vector4.mZ, zValue, floatMargin);
		EXPECT_NEAR(vector4.mW, wValue, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec4.GetRandomDouble();
		const auto y1 = testUtilsVec4.GetRandomDouble();
		const auto z1 = testUtilsVec4.GetRandomDouble();
		const auto w1 = testUtilsVec4.GetRandomDouble();

		const auto x2 = testUtilsVec4.GetRandomDouble();
		const auto y2 = testUtilsVec4.GetRandomDouble();
		const auto z2 = testUtilsVec4.GetRandomDouble();
		const auto w2 = testUtilsVec4.GetRandomDouble();

		const OMath::Vector4<double> vector1(x1, y1, z1, w1);
		const OMath::Vector4<double> Vector4(x2, y2, z2, w2);
		const auto resultVector = vector1 * Vector4;

		EXPECT_NEAR(resultVector.mX, x1 * x2, doubleMargin);
		EXPECT_NEAR(resultVector.mY, y1 * y2, doubleMargin);
		EXPECT_NEAR(resultVector.mZ, z1 * z2, doubleMargin);
		EXPECT_NEAR(resultVector.mW, w1 * w2, doubleMargin);

		const auto x3 = testUtilsVec4.GetRandomDouble();
		const auto y3 = testUtilsVec4.GetRandomDouble();
		const auto z3 = testUtilsVec4.GetRandomDouble();
		const auto w3 = testUtilsVec4.GetRandomDouble();

		OMath::Vector4<double> vector4(x3, y3, z3, w3);
		vector4 *= resultVector;

		const auto xValue = x3 * (x1 * x2);
		const auto yValue = y3 * (y1 * y2);
		const auto zValue = z3 * (z1 * z2);
		const auto wValue = w3 * (w1 * w2);

		EXPECT_NEAR(vector4.mX, xValue, floatMargin);
		EXPECT_NEAR(vector4.mY, yValue, floatMargin);
		EXPECT_NEAR(vector4.mZ, zValue, floatMargin);
		EXPECT_NEAR(vector4.mW, wValue, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec4.GetRandomInt();
		const auto y1 = testUtilsVec4.GetRandomInt();
		const auto z1 = testUtilsVec4.GetRandomInt();
		const auto w1 = testUtilsVec4.GetRandomInt();

		const auto x2 = testUtilsVec4.GetRandomInt();
		const auto y2 = testUtilsVec4.GetRandomInt();
		const auto z2 = testUtilsVec4.GetRandomInt();
		const auto w2 = testUtilsVec4.GetRandomInt();

		const auto x3 = testUtilsVec4.GetRandomInt();
		const auto y3 = testUtilsVec4.GetRandomInt();
		const auto z3 = testUtilsVec4.GetRandomInt();
		const auto w3 = testUtilsVec4.GetRandomInt();

		const OMath::Vector4<int> vector1(x1, y1, z1, w1);
		const OMath::Vector4<int> Vector4(x2, y2, z2, w2);
		const auto resultVector = vector1 * Vector4;

		EXPECT_EQ(resultVector.mX, x1 * x2);
		EXPECT_EQ(resultVector.mY, y1 * y2);
		EXPECT_EQ(resultVector.mZ, z1 * z2);
		EXPECT_EQ(resultVector.mW, w1 * w2);

		OMath::Vector4<int> vector4(x3, y3, z3, w3);
		vector4 *= resultVector;

		const auto xValue = x3 * (x1 * x2);
		const auto yValue = y3 * (y1 * y2);
		const auto zValue = z3 * (z1 * z2);
		const auto wValue = w3 * (w1 * w2);

		EXPECT_EQ(vector4.mX, xValue);
		EXPECT_EQ(vector4.mY, yValue);
		EXPECT_EQ(vector4.mZ, zValue);
		EXPECT_EQ(vector4.mW, wValue);
	}
}

TEST(Vector4_tests, LengthSquared) {
	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec4.GetRandomFloat();
		const auto y1 = testUtilsVec4.GetRandomFloat();
		const auto z1 = testUtilsVec4.GetRandomFloat();
		const auto w1 = testUtilsVec4.GetRandomFloat();

		const OMath::Vector4<float> vector(x1, y1, z1, w1);
		const auto lengthSqrd = vector.LengthSqrd();
		const auto expectedValue = x1 * x1 + y1 * y1 + z1 * z1 + w1 * w1;

		EXPECT_NEAR(lengthSqrd, expectedValue, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec4.GetRandomDouble();
		const auto y1 = testUtilsVec4.GetRandomDouble();
		const auto z1 = testUtilsVec4.GetRandomDouble();
		const auto w1 = testUtilsVec4.GetRandomDouble();

		const OMath::Vector4<double> vector(x1, y1, z1, w1);
		const auto lengthSqrd = vector.LengthSqrd();
		const auto expectedValue = x1 * x1 + y1 * y1 + z1 * z1 + w1 * w1;

		EXPECT_NEAR(lengthSqrd, expectedValue, doubleMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec4.GetRandomInt();
		const auto y1 = testUtilsVec4.GetRandomInt();
		const auto z1 = testUtilsVec4.GetRandomInt();
		const auto w1 = testUtilsVec4.GetRandomInt();

		const OMath::Vector4<int> vector(x1, y1, z1, w1);
		const auto result = vector.LengthSqrd();
		const auto expectedValue = x1 * x1 + y1 * y1 + z1 * z1 + w1 * w1;
		EXPECT_EQ(result, expectedValue);
	}
}

TEST(Vector4_tests, Length) {
	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec4.GetRandomFloat();
		const auto y1 = testUtilsVec4.GetRandomFloat();
		const auto z1 = testUtilsVec4.GetRandomFloat();
		const auto w1 = testUtilsVec4.GetRandomFloat();

		const OMath::Vector4<float> vector(x1, y1, z1, w1);
		const auto length = vector.Length();
		const float expectedValue = sqrt(x1 * x1 + y1 * y1 + z1 * z1 + w1 * w1);

		EXPECT_NEAR(length, expectedValue, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec4.GetRandomDouble();
		const auto y1 = testUtilsVec4.GetRandomDouble();
		const auto z1 = testUtilsVec4.GetRandomDouble();
		const auto w1 = testUtilsVec4.GetRandomDouble();

		const OMath::Vector4<double> vector(x1, y1, z1, w1);
		const auto length = vector.Length();
		const double expectedValue = sqrt(x1 * x1 + y1 * y1 + z1 * z1 + w1 * w1);

		EXPECT_NEAR(length, expectedValue, doubleMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec4.GetRandomInt();
		const auto y1 = testUtilsVec4.GetRandomInt();
		const auto z1 = testUtilsVec4.GetRandomInt();
		const auto w1 = testUtilsVec4.GetRandomInt();

		const OMath::Vector4<int> vector(x1, y1, z1, w1);
		const auto length = vector.Length();
		const int expectedValue = static_cast<int>(sqrt(x1 * x1 + y1 * y1 + z1 * z1 + w1 * w1));

		EXPECT_EQ(length, expectedValue);
	}
}

TEST(Vector4_tests, GetNormalized) {
	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec4.GetRandomFloat();
		const auto y1 = testUtilsVec4.GetRandomFloat();
		const auto z1 = testUtilsVec4.GetRandomFloat();
		const auto w1 = testUtilsVec4.GetRandomFloat();

		const OMath::Vector4<float> vector(x1, y1, z1, w1);
		const auto normalizedVector = vector.GetNormalized();
		const auto length = vector.Length();
		const OMath::Vector4<float> expectedValue(
			vector.mX / length,
			vector.mY / length,
			vector.mZ / length,
			vector.mW / length);

		EXPECT_NEAR(normalizedVector.mX, expectedValue.mX, floatMargin);
		EXPECT_NEAR(normalizedVector.mY, expectedValue.mY, floatMargin);
		EXPECT_NEAR(normalizedVector.mZ, expectedValue.mZ, floatMargin);
		EXPECT_NEAR(normalizedVector.mW, expectedValue.mW, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec4.GetRandomDouble();
		const auto y1 = testUtilsVec4.GetRandomDouble();
		const auto z1 = testUtilsVec4.GetRandomDouble();
		const auto w1 = testUtilsVec4.GetRandomDouble();

		const OMath::Vector4<double> vector(x1, y1, z1, w1);
		const auto normalizedVector = vector.GetNormalized();
		const auto length = vector.Length();
		const OMath::Vector4<double> expectedValue(
			vector.mX / length,
			vector.mY / length,
			vector.mZ / length,
			vector.mW / length);

		EXPECT_NEAR(normalizedVector.mX, expectedValue.mX, doubleMargin);
		EXPECT_NEAR(normalizedVector.mY, expectedValue.mY, doubleMargin);
		EXPECT_NEAR(normalizedVector.mZ, expectedValue.mZ, doubleMargin);
		EXPECT_NEAR(normalizedVector.mW, expectedValue.mW, doubleMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec4.GetRandomInt();
		const auto y1 = testUtilsVec4.GetRandomInt();
		const auto z1 = testUtilsVec4.GetRandomInt();
		const auto w1 = testUtilsVec4.GetRandomInt();

		const OMath::Vector4<int> vector(x1, y1, z1, w1);
		const auto normalizedVector = vector.GetNormalized();
		const auto length = vector.Length();
		const OMath::Vector4<int> expectedValue(
			vector.mX / length,
			vector.mY / length,
			vector.mZ / length,
			vector.mW / length);

		EXPECT_EQ(normalizedVector.mX, expectedValue.mX);
		EXPECT_EQ(normalizedVector.mY, expectedValue.mY);
		EXPECT_EQ(normalizedVector.mZ, expectedValue.mZ);
		EXPECT_EQ(normalizedVector.mW, expectedValue.mW);
	}
}

TEST(Vector4_tests, Length_Zero) {
	OMath::Vector4<float> vectorF;
	EXPECT_EQ(vectorF.Length(), 0.0f);

	OMath::Vector4<double> vectorD;
	EXPECT_EQ(vectorD.Length(), 0.0);

	OMath::Vector4<int> vectorI;
	EXPECT_EQ(vectorI.Length(), 0);
}

TEST(Vector4_tests, Normalize_Zero) {
	OMath::Vector4<float> vectorF;
	vectorF.Normalize();
	OMath::Vector4<float> normalizedVectorF = vectorF.GetNormalized();
	EXPECT_EQ(vectorF.Length(), 0.0f);
	EXPECT_EQ(normalizedVectorF.Length(), 0.0f);

	OMath::Vector4<double> vectorD;
	vectorD.Normalize();
	OMath::Vector4<double> normalizedVectorD = vectorD.GetNormalized();
	EXPECT_EQ(vectorD.Length(), 0.0);
	EXPECT_EQ(normalizedVectorD.Length(), 0.0);

	OMath::Vector4<int> vectorI;
	vectorI.Normalize();
	OMath::Vector4<int> normalizedVectorI = vectorI.GetNormalized();
	EXPECT_EQ(vectorI.Length(), 0);
	EXPECT_EQ(normalizedVectorI.Length(), 0);
}

TEST(Vector4_tests, Dot) {
	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec4.GetRandomFloat();
		const auto x2 = testUtilsVec4.GetRandomFloat();
		const auto y1 = testUtilsVec4.GetRandomFloat();
		const auto y2 = testUtilsVec4.GetRandomFloat();
		const auto z1 = testUtilsVec4.GetRandomFloat();
		const auto z2 = testUtilsVec4.GetRandomFloat();
		const auto w1 = testUtilsVec4.GetRandomFloat();
		const auto w2 = testUtilsVec4.GetRandomFloat();

		const OMath::Vector4<float> vector1(x1, y1, z1, w1);
		const OMath::Vector4<float> Vector4(x2, y2, z2, w2);
		const auto dot = vector1.Dot(Vector4);

		const auto controlDot = x1 * x2 + y1 * y2 + z1 * z2 + w1 * w2;

		EXPECT_NEAR(dot, controlDot, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec4.GetRandomDouble();
		const auto x2 = testUtilsVec4.GetRandomDouble();
		const auto y1 = testUtilsVec4.GetRandomDouble();
		const auto y2 = testUtilsVec4.GetRandomDouble();
		const auto z1 = testUtilsVec4.GetRandomDouble();
		const auto z2 = testUtilsVec4.GetRandomDouble();		
		const auto w1 = testUtilsVec4.GetRandomDouble();
		const auto w2 = testUtilsVec4.GetRandomDouble();

		const OMath::Vector4<double> vector1(x1, y1, z1, w1);
		const OMath::Vector4<double> Vector4(x2, y2, z2, w2);
		const auto dot = vector1.Dot(Vector4);

		const auto controlDot = x1 * x2 + y1 * y2 + z1 * z2 + w1 * w2;

		EXPECT_NEAR(dot, controlDot, doubleMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec4.GetRandomInt();
		const auto x2 = testUtilsVec4.GetRandomInt();
		const auto y1 = testUtilsVec4.GetRandomInt();
		const auto y2 = testUtilsVec4.GetRandomInt();
		const auto z1 = testUtilsVec4.GetRandomInt();
		const auto z2 = testUtilsVec4.GetRandomInt();
		const auto w1 = testUtilsVec4.GetRandomInt();
		const auto w2 = testUtilsVec4.GetRandomInt();

		const OMath::Vector4<int> vector1(x1, y1, z1, w1);
		const OMath::Vector4<int> Vector4(x2, y2, z2, w2);
		const auto dot = vector1.Dot(Vector4);

		const auto controlDot = x1 * x2 + y1 * y2 + z1 * z2 + w1 * w2;

		EXPECT_EQ(dot, controlDot);
	}
}