#include "gtest/gtest.h"

#include "Math/Vector3.h"
#include "../TestUtilities.h"

constexpr float floatMargin = 0.0000001f;
constexpr double doubleMargin = 0.0000001;

TestUtilities testUtilsVec3;

TEST(Vector3_tests, Constructors) {
	const OMath::Vector3<int> vectorDefaultI;
	EXPECT_EQ(vectorDefaultI.mX, 0);
	EXPECT_EQ(vectorDefaultI.mY, 0);
	EXPECT_EQ(vectorDefaultI.mZ, 0);

	const OMath::Vector3<float> vectorDefaultF;
	EXPECT_EQ(vectorDefaultF.mX, 0);
	EXPECT_EQ(vectorDefaultF.mY, 0);
	EXPECT_EQ(vectorDefaultF.mZ, 0);

	const OMath::Vector3<double> vectorDefaultD;
	EXPECT_EQ(vectorDefaultD.mX, 0);
	EXPECT_EQ(vectorDefaultD.mY, 0);
	EXPECT_EQ(vectorDefaultD.mZ, 0);

	for (int i = 0; i < 100; ++i) {
		const int x = testUtilsVec3.GetRandomInt();
		const int y = testUtilsVec3.GetRandomInt();
		const int z = testUtilsVec3.GetRandomInt();

		const OMath::Vector3<int> vector(x, y, z);
		EXPECT_EQ(vector.mX, x);
		EXPECT_EQ(vector.mY, y);
		EXPECT_EQ(vector.mZ, z);
	}

	for (int i = 0; i < 100; ++i) {
		const float x = testUtilsVec3.GetRandomFloat();
		const float y = testUtilsVec3.GetRandomFloat();
		const float z = testUtilsVec3.GetRandomFloat();

		const OMath::Vector3<float> vector(x, y, z);
		EXPECT_EQ(vector.mX, x);
		EXPECT_EQ(vector.mY, y);
		EXPECT_EQ(vector.mZ, z);
	}

	for (int i = 0; i < 100; ++i) {
		const double x = testUtilsVec3.GetRandomDouble();
		const double y = testUtilsVec3.GetRandomDouble();
		const double z = testUtilsVec3.GetRandomDouble();

		const OMath::Vector3<double> vector(x, y, z);
		EXPECT_EQ(vector.mX, x);
		EXPECT_EQ(vector.mY, y);
		EXPECT_EQ(vector.mZ, z);
	}

	for (int i = 0; i < 100; ++i) {
		const int x = testUtilsVec3.GetRandomInt();
		const int y = testUtilsVec3.GetRandomInt();
		const int z = testUtilsVec3.GetRandomInt();

		const OMath::Vector3<int> vector(x, y, z);
		const auto copyVector(vector);
		EXPECT_EQ(copyVector.mX, x);
		EXPECT_EQ(copyVector.mY, y);
		EXPECT_EQ(copyVector.mZ, z);
	}

	for (int i = 0; i < 100; ++i) {
		const float x = testUtilsVec3.GetRandomFloat();
		const float y = testUtilsVec3.GetRandomFloat();
		const float z = testUtilsVec3.GetRandomFloat();

		const OMath::Vector3<float> vector(x, y, z);
		const auto copyVector(vector);
		EXPECT_EQ(copyVector.mX, x);
		EXPECT_EQ(copyVector.mY, y);
		EXPECT_EQ(copyVector.mZ, z);
	}

	for (int i = 0; i < 100; ++i) {
		const double x = testUtilsVec3.GetRandomDouble();
		const double y = testUtilsVec3.GetRandomDouble();
		const double z = testUtilsVec3.GetRandomDouble();

		const OMath::Vector3<double> vector(x, y, z);
		const auto copyVector(vector);
		EXPECT_EQ(copyVector.mX, x);
		EXPECT_EQ(copyVector.mY, y);
		EXPECT_EQ(copyVector.mZ, z);
	}
}

TEST(Vector3_tests, Assignment) {
	for (int i = 0; i < 100; i++) {
		const auto x = testUtilsVec3.GetRandomFloat();
		const auto y = testUtilsVec3.GetRandomFloat();
		const auto z = testUtilsVec3.GetRandomFloat();

		const OMath::Vector3<float> originalVec(x, y, z);
		auto copyVector = originalVec;
		EXPECT_EQ(copyVector.mX, x);
		EXPECT_EQ(copyVector.mY, y);
		EXPECT_EQ(copyVector.mZ, z);
	}

	for (int i = 0; i < 100; i++) {
		const auto x = testUtilsVec3.GetRandomDouble();
		const auto y = testUtilsVec3.GetRandomDouble();
		const auto z = testUtilsVec3.GetRandomDouble();

		const OMath::Vector3<double> originalVec(x, y, z);
		auto copyVector = originalVec;
		EXPECT_EQ(copyVector.mX, x);
		EXPECT_EQ(copyVector.mY, y);
		EXPECT_EQ(copyVector.mZ, z);
	}

	for (int i = 0; i < 100; i++) {
		const auto x = testUtilsVec3.GetRandomInt();
		const auto y = testUtilsVec3.GetRandomInt();
		const auto z = testUtilsVec3.GetRandomInt();

		const OMath::Vector3<int> originalVec(x, y, z);
		auto copyVector = originalVec;
		EXPECT_EQ(copyVector.mX, x);
		EXPECT_EQ(copyVector.mY, y);
		EXPECT_EQ(copyVector.mZ, z);
	}
}

TEST(Vector3_tests, Addition) {
	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomFloat();
		const auto y1 = testUtilsVec3.GetRandomFloat();
		const auto z1 = testUtilsVec3.GetRandomFloat();
		const auto x2 = testUtilsVec3.GetRandomFloat();
		const auto y2 = testUtilsVec3.GetRandomFloat();
		const auto z2 = testUtilsVec3.GetRandomFloat();

		const OMath::Vector3<float> vector1(x1, y1, z1);
		const OMath::Vector3<float> Vector3(x2, y2, z2);
		const auto resultVector = vector1 + Vector3;

		EXPECT_NEAR(resultVector.mX, x1 + x2, floatMargin);
		EXPECT_NEAR(resultVector.mY, y1 + y2, floatMargin);
		EXPECT_NEAR(resultVector.mZ, z1 + z2, floatMargin);

		const auto x3 = testUtilsVec3.GetRandomFloat();
		const auto y3 = testUtilsVec3.GetRandomFloat();
		const auto z3 = testUtilsVec3.GetRandomFloat();

		OMath::Vector3<float> vector4(x3, y3, z3);
		vector4 += resultVector;

		const float xResult = x1 + x2 + x3;
		const float yResult = y1 + y2 + y3;
		const float zResult = z1 + z2 + z3;
		EXPECT_NEAR(vector4.mX, xResult, floatMargin);
		EXPECT_NEAR(vector4.mY, yResult, floatMargin);
		EXPECT_NEAR(vector4.mZ, zResult, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomDouble();
		const auto y1 = testUtilsVec3.GetRandomDouble();
		const auto z1 = testUtilsVec3.GetRandomDouble();
		const auto x2 = testUtilsVec3.GetRandomDouble();
		const auto y2 = testUtilsVec3.GetRandomDouble();
		const auto z2 = testUtilsVec3.GetRandomDouble();

		const OMath::Vector3<double> vector1(x1, y1, z1);
		const OMath::Vector3<double> Vector3(x2, y2, z2);
		const auto resultVector = vector1 + Vector3;

		EXPECT_NEAR(resultVector.mX, x1 + x2, doubleMargin);
		EXPECT_NEAR(resultVector.mY, y1 + y2, doubleMargin);
		EXPECT_NEAR(resultVector.mZ, z1 + z2, doubleMargin);

		const auto x3 = testUtilsVec3.GetRandomDouble();
		const auto y3 = testUtilsVec3.GetRandomDouble();
		const auto z3 = testUtilsVec3.GetRandomDouble();

		OMath::Vector3<double> vector4(x3, y3, z3);
		vector4 += resultVector;

		const auto xResult = x1 + x2 + x3;
		const auto yResult = y1 + y2 + y3;
		const auto zResult = z1 + z2 + z3;
		EXPECT_NEAR(vector4.mX, xResult, doubleMargin);
		EXPECT_NEAR(vector4.mY, yResult, doubleMargin);
		EXPECT_NEAR(vector4.mZ, zResult, doubleMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomInt();
		const auto y1 = testUtilsVec3.GetRandomInt();
		const auto z1 = testUtilsVec3.GetRandomInt();
		const auto x2 = testUtilsVec3.GetRandomInt();
		const auto y2 = testUtilsVec3.GetRandomInt();
		const auto z2 = testUtilsVec3.GetRandomInt();

		const OMath::Vector3<int> vector1(x1, y1, z1);
		const OMath::Vector3<int> Vector3(x2, y2, z2);
		const auto resultVector = vector1 + Vector3;

		EXPECT_EQ(resultVector.mX, x1 + x2);
		EXPECT_EQ(resultVector.mY, y1 + y2);
		EXPECT_EQ(resultVector.mZ, z1 + z2);

		const auto x3 = testUtilsVec3.GetRandomInt();
		const auto y3 = testUtilsVec3.GetRandomInt();
		const auto z3 = testUtilsVec3.GetRandomInt();

		OMath::Vector3<int> vector4(x3, y3, z3);
		vector4 += resultVector;

		const auto xResult = x1 + x2 + x3;
		const auto yResult = y1 + y2 + y3;
		const auto zResult = z1 + z2 + z3;
		EXPECT_EQ(vector4.mX, x1 + x2 + x3);
		EXPECT_EQ(vector4.mY, y1 + y2 + y3);
		EXPECT_EQ(vector4.mZ, z1 + z2 + z3);
	}
}

TEST(Vector3_tests, Subtraction) {
	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomFloat();
		const auto y1 = testUtilsVec3.GetRandomFloat();
		const auto z1 = testUtilsVec3.GetRandomFloat();
		const auto x2 = testUtilsVec3.GetRandomFloat();
		const auto y2 = testUtilsVec3.GetRandomFloat();
		const auto z2 = testUtilsVec3.GetRandomFloat();

		const OMath::Vector3<float> vector1(x1, y1, z1);
		const OMath::Vector3<float> Vector3(x2, y2, z2);
		const auto resultVector = vector1 - Vector3;

		EXPECT_NEAR(resultVector.mX, x1 - x2, floatMargin);
		EXPECT_NEAR(resultVector.mY, y1 - y2, floatMargin);
		EXPECT_NEAR(resultVector.mZ, z1 - z2, floatMargin);

		const auto x3 = testUtilsVec3.GetRandomFloat();
		const auto y3 = testUtilsVec3.GetRandomFloat();
		const auto z3 = testUtilsVec3.GetRandomFloat();

		OMath::Vector3<float> vector4(x3, y3, z3);
		vector4 -= resultVector;

		const auto xValue = x3 - (x1 - x2);
		const auto yValue = y3 - (y1 - y2);
		const auto zValue = z3 - (z1 - z2);

		EXPECT_NEAR(vector4.mX, xValue, floatMargin);
		EXPECT_NEAR(vector4.mY, yValue, floatMargin);
		EXPECT_NEAR(vector4.mZ, zValue, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomDouble();
		const auto y1 = testUtilsVec3.GetRandomDouble();
		const auto z1 = testUtilsVec3.GetRandomDouble();
		const auto x2 = testUtilsVec3.GetRandomDouble();
		const auto y2 = testUtilsVec3.GetRandomDouble();
		const auto z2 = testUtilsVec3.GetRandomDouble();

		const OMath::Vector3<double> vector1(x1, y1, z1);
		const OMath::Vector3<double> Vector3(x2, y2, z2);
		const auto resultVector = vector1 - Vector3;

		EXPECT_NEAR(resultVector.mX, x1 - x2, doubleMargin);
		EXPECT_NEAR(resultVector.mY, y1 - y2, doubleMargin);
		EXPECT_NEAR(resultVector.mZ, z1 - z2, doubleMargin);

		const auto x3 = testUtilsVec3.GetRandomDouble();
		const auto y3 = testUtilsVec3.GetRandomDouble();
		const auto z3 = testUtilsVec3.GetRandomDouble();

		OMath::Vector3<double> vector4(x3, y3, z3);
		vector4 -= resultVector;

		const auto xValue = x3 - (x1 - x2);
		const auto yValue = y3 - (y1 - y2);
		const auto zValue = z3 - (z1 - z2);

		EXPECT_NEAR(vector4.mX, xValue, floatMargin);
		EXPECT_NEAR(vector4.mY, yValue, floatMargin);
		EXPECT_NEAR(vector4.mZ, zValue, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomInt();
		const auto y1 = testUtilsVec3.GetRandomInt();
		const auto z1 = testUtilsVec3.GetRandomInt();
		const auto x2 = testUtilsVec3.GetRandomInt();
		const auto y2 = testUtilsVec3.GetRandomInt();
		const auto z2 = testUtilsVec3.GetRandomInt();
		const auto x3 = testUtilsVec3.GetRandomInt();
		const auto y3 = testUtilsVec3.GetRandomInt();
		const auto z3 = testUtilsVec3.GetRandomInt();

		const OMath::Vector3<int> vector1(x1, y1, z1);
		const OMath::Vector3<int> Vector3(x2, y2, z2);
		const auto resultVector = vector1 - Vector3;

		EXPECT_EQ(resultVector.mX, x1 - x2);
		EXPECT_EQ(resultVector.mY, y1 - y2);
		EXPECT_EQ(resultVector.mZ, z1 - z2);

		OMath::Vector3<int> vector4(x3, y3, z3);
		vector4 -= resultVector;

		const auto xValue = x3 - (x1 - x2);
		const auto yValue = y3 - (y1 - y2);
		const auto zValue = z3 - (z1 - z2);

		EXPECT_EQ(vector4.mX, xValue);
		EXPECT_EQ(vector4.mY, yValue);
		EXPECT_EQ(vector4.mZ, zValue);
	}
}

TEST(Vector3_tests, Multiplication) {
	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomFloat();
		const auto y1 = testUtilsVec3.GetRandomFloat();
		const auto z1 = testUtilsVec3.GetRandomFloat();
		const auto x2 = testUtilsVec3.GetRandomFloat();
		const auto y2 = testUtilsVec3.GetRandomFloat();
		const auto z2 = testUtilsVec3.GetRandomFloat();

		const OMath::Vector3<float> vector1(x1, y1, z1);
		const OMath::Vector3<float> Vector3(x2, y2, z2);
		const auto resultVector = vector1 * Vector3;

		EXPECT_NEAR(resultVector.mX, x1 * x2, floatMargin);
		EXPECT_NEAR(resultVector.mY, y1 * y2, floatMargin);
		EXPECT_NEAR(resultVector.mZ, z1 * z2, floatMargin);

		const auto x3 = testUtilsVec3.GetRandomFloat();
		const auto y3 = testUtilsVec3.GetRandomFloat();
		const auto z3 = testUtilsVec3.GetRandomFloat();

		OMath::Vector3<float> vector4(x3, y3, z3);
		vector4 *= resultVector;

		const auto xValue = x3 * (x1 * x2);
		const auto yValue = y3 * (y1 * y2);
		const auto zValue = z3 * (z1 * z2);

		EXPECT_NEAR(vector4.mX, xValue, floatMargin);
		EXPECT_NEAR(vector4.mY, yValue, floatMargin);
		EXPECT_NEAR(vector4.mZ, zValue, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomDouble();
		const auto y1 = testUtilsVec3.GetRandomDouble();
		const auto z1 = testUtilsVec3.GetRandomDouble();
		const auto x2 = testUtilsVec3.GetRandomDouble();
		const auto y2 = testUtilsVec3.GetRandomDouble();
		const auto z2 = testUtilsVec3.GetRandomDouble();

		const OMath::Vector3<double> vector1(x1, y1, z1);
		const OMath::Vector3<double> Vector3(x2, y2, z2);
		const auto resultVector = vector1 * Vector3;

		EXPECT_NEAR(resultVector.mX, x1 * x2, doubleMargin);
		EXPECT_NEAR(resultVector.mY, y1 * y2, doubleMargin);
		EXPECT_NEAR(resultVector.mZ, z1 * z2, doubleMargin);

		const auto x3 = testUtilsVec3.GetRandomDouble();
		const auto y3 = testUtilsVec3.GetRandomDouble();
		const auto z3 = testUtilsVec3.GetRandomDouble();

		OMath::Vector3<double> vector4(x3, y3, z3);
		vector4 *= resultVector;

		const auto xValue = x3 * (x1 * x2);
		const auto yValue = y3 * (y1 * y2);
		const auto zValue = z3 * (z1 * z2);

		EXPECT_NEAR(vector4.mX, xValue, floatMargin);
		EXPECT_NEAR(vector4.mY, yValue, floatMargin);
		EXPECT_NEAR(vector4.mZ, zValue, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomInt();
		const auto y1 = testUtilsVec3.GetRandomInt();
		const auto z1 = testUtilsVec3.GetRandomInt();
		const auto x2 = testUtilsVec3.GetRandomInt();
		const auto y2 = testUtilsVec3.GetRandomInt();
		const auto z2 = testUtilsVec3.GetRandomInt();
		const auto x3 = testUtilsVec3.GetRandomInt();
		const auto y3 = testUtilsVec3.GetRandomInt();
		const auto z3 = testUtilsVec3.GetRandomInt();

		const OMath::Vector3<int> vector1(x1, y1, z1);
		const OMath::Vector3<int> Vector3(x2, y2, z2);
		const auto resultVector = vector1 * Vector3;

		EXPECT_EQ(resultVector.mX, x1 * x2);
		EXPECT_EQ(resultVector.mY, y1 * y2);
		EXPECT_EQ(resultVector.mZ, z1 * z2);

		OMath::Vector3<int> vector4(x3, y3, z3);
		vector4 *= resultVector;

		const auto xValue = x3 * (x1 * x2);
		const auto yValue = y3 * (y1 * y2);
		const auto zValue = z3 * (z1 * z2);

		EXPECT_EQ(vector4.mX, xValue);
		EXPECT_EQ(vector4.mY, yValue);
		EXPECT_EQ(vector4.mZ, zValue);
	}
}

TEST(Vector3_tests, LengthSquared) {
	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomFloat();
		const auto y1 = testUtilsVec3.GetRandomFloat();
		const auto z1 = testUtilsVec3.GetRandomFloat();

		const OMath::Vector3<float> vector(x1, y1, z1);
		const auto lengthSqrd = vector.LengthSqrd();
		const auto expectedValue = x1 * x1 + y1 * y1 + z1 * z1;

		EXPECT_NEAR(lengthSqrd, expectedValue, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomDouble();
		const auto y1 = testUtilsVec3.GetRandomDouble();
		const auto z1 = testUtilsVec3.GetRandomDouble();

		const OMath::Vector3<double> vector(x1, y1, z1);
		const auto lengthSqrd = vector.LengthSqrd();
		const auto expectedValue = x1 * x1 + y1 * y1 + z1 * z1;

		EXPECT_NEAR(lengthSqrd, expectedValue, doubleMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomInt();
		const auto y1 = testUtilsVec3.GetRandomInt();
		const auto z1 = testUtilsVec3.GetRandomInt();

		const OMath::Vector3<int> vector(x1, y1, z1);
		const auto result = vector.LengthSqrd();
		const auto expectedValue = x1 * x1 + y1 * y1 + z1 * z1;
		EXPECT_EQ(result, expectedValue);
	}
}

TEST(Vector3_tests, Length) {
	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomFloat();
		const auto y1 = testUtilsVec3.GetRandomFloat();
		const auto z1 = testUtilsVec3.GetRandomFloat();

		const OMath::Vector3<float> vector(x1, y1, z1);
		const auto length = vector.Length();
		const float expectedValue = sqrt(x1 * x1 + y1 * y1 + z1 * z1);

		EXPECT_NEAR(length, expectedValue, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomDouble();
		const auto y1 = testUtilsVec3.GetRandomDouble();
		const auto z1 = testUtilsVec3.GetRandomDouble();

		const OMath::Vector3<double> vector(x1, y1, z1);
		const auto length = vector.Length();
		const double expectedValue = sqrt(x1 * x1 + y1 * y1 + z1 * z1);

		EXPECT_NEAR(length, expectedValue, doubleMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomInt();
		const auto y1 = testUtilsVec3.GetRandomInt();
		const auto z1 = testUtilsVec3.GetRandomInt();

		const OMath::Vector3<int> vector(x1, y1, z1);
		const auto length = vector.Length();
		const int expectedValue = static_cast<int>(sqrt(x1 * x1 + y1 * y1 + z1 * z1));

		EXPECT_EQ(length, expectedValue);
	}
}

TEST(Vector3_tests, GetNormalized) {
	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomFloat();
		const auto y1 = testUtilsVec3.GetRandomFloat();
		const auto z1 = testUtilsVec3.GetRandomFloat();

		const OMath::Vector3<float> vector(x1, y1, z1);
		const auto normalizedVector = vector.GetNormalized();
		const auto length = vector.Length();
		const OMath::Vector3<float> expectedValue(
			vector.mX / length,
			vector.mY / length,
			vector.mZ / length);

		EXPECT_NEAR(normalizedVector.mX, expectedValue.mX, floatMargin);
		EXPECT_NEAR(normalizedVector.mY, expectedValue.mY, floatMargin);
		EXPECT_NEAR(normalizedVector.mZ, expectedValue.mZ, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomDouble();
		const auto y1 = testUtilsVec3.GetRandomDouble();
		const auto z1 = testUtilsVec3.GetRandomDouble();

		const OMath::Vector3<double> vector(x1, y1, z1);
		const auto normalizedVector = vector.GetNormalized();
		const auto length = vector.Length();
		const OMath::Vector3<double> expectedValue(
			vector.mX / length,
			vector.mY / length,
			vector.mZ / length);

		EXPECT_NEAR(normalizedVector.mX, expectedValue.mX, doubleMargin);
		EXPECT_NEAR(normalizedVector.mY, expectedValue.mY, doubleMargin);
		EXPECT_NEAR(normalizedVector.mZ, expectedValue.mZ, doubleMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomInt();
		const auto y1 = testUtilsVec3.GetRandomInt();
		const auto z1 = testUtilsVec3.GetRandomInt();

		const OMath::Vector3<int> vector(x1, y1, z1);
		const auto normalizedVector = vector.GetNormalized();
		const auto length = vector.Length();
		const OMath::Vector3<int> expectedValue(
			vector.mX / length,
			vector.mY / length,
			vector.mZ / length);

		EXPECT_EQ(normalizedVector.mX, expectedValue.mX);
		EXPECT_EQ(normalizedVector.mY, expectedValue.mY);
		EXPECT_EQ(normalizedVector.mZ, expectedValue.mZ);
	}
}

TEST(Vector3_tests, Length_Zero) {
	OMath::Vector3<float> vectorF;
	EXPECT_EQ(vectorF.Length(), 0.0f);

	OMath::Vector3<double> vectorD;
	EXPECT_EQ(vectorD.Length(), 0.0);

	OMath::Vector3<int> vectorI;
	EXPECT_EQ(vectorI.Length(), 0);
}

TEST(Vector3_tests, Normalize_Zero) {
	OMath::Vector3<float> vectorF;
	vectorF.Normalize();
	OMath::Vector3<float> normalizedVectorF = vectorF.GetNormalized();
	EXPECT_EQ(vectorF.Length(), 0.0f);
	EXPECT_EQ(normalizedVectorF.Length(), 0.0f);

	OMath::Vector3<double> vectorD;
	vectorD.Normalize();
	OMath::Vector3<double> normalizedVectorD = vectorD.GetNormalized();
	EXPECT_EQ(vectorD.Length(), 0.0);
	EXPECT_EQ(normalizedVectorD.Length(), 0.0);

	OMath::Vector3<int> vectorI;
	vectorI.Normalize();
	OMath::Vector3<int> normalizedVectorI = vectorI.GetNormalized();
	EXPECT_EQ(vectorI.Length(), 0);
	EXPECT_EQ(normalizedVectorI.Length(), 0);
}

TEST(Vector3_tests, Dot) {
	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomFloat();
		const auto x2 = testUtilsVec3.GetRandomFloat();
		const auto y1 = testUtilsVec3.GetRandomFloat();
		const auto y2 = testUtilsVec3.GetRandomFloat();
		const auto z1 = testUtilsVec3.GetRandomFloat();
		const auto z2 = testUtilsVec3.GetRandomFloat();

		const OMath::Vector3<float> vector1(x1, y1, z1);
		const OMath::Vector3<float> Vector3(x2, y2, z2);
		const auto dot = vector1.Dot(Vector3);

		const auto controlDot = x1 * x2 + y1 * y2 + z1 * z2;

		EXPECT_NEAR(dot, controlDot, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomDouble();
		const auto x2 = testUtilsVec3.GetRandomDouble();
		const auto y1 = testUtilsVec3.GetRandomDouble();
		const auto y2 = testUtilsVec3.GetRandomDouble();
		const auto z1 = testUtilsVec3.GetRandomDouble();
		const auto z2 = testUtilsVec3.GetRandomDouble();

		const OMath::Vector3<double> vector1(x1, y1, z1);
		const OMath::Vector3<double> Vector3(x2, y2, z2);
		const auto dot = vector1.Dot(Vector3);

		const auto controlDot = x1 * x2 + y1 * y2 + z1 * z2;

		EXPECT_NEAR(dot, controlDot, doubleMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomInt();
		const auto x2 = testUtilsVec3.GetRandomInt();
		const auto y1 = testUtilsVec3.GetRandomInt();
		const auto y2 = testUtilsVec3.GetRandomInt();
		const auto z1 = testUtilsVec3.GetRandomInt();
		const auto z2 = testUtilsVec3.GetRandomInt();

		const OMath::Vector3<int> vector1(x1, y1, z1);
		const OMath::Vector3<int> Vector3(x2, y2, z2);
		const auto dot = vector1.Dot(Vector3);

		const auto controlDot = x1 * x2 + y1 * y2 + z1 * z2;

		EXPECT_EQ(dot, controlDot);
	}
}

TEST(Vector3_tests, Cross) {
	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomFloat();
		const auto x2 = testUtilsVec3.GetRandomFloat();
		const auto y1 = testUtilsVec3.GetRandomFloat();
		const auto y2 = testUtilsVec3.GetRandomFloat();
		const auto z1 = testUtilsVec3.GetRandomFloat();
		const auto z2 = testUtilsVec3.GetRandomFloat();

		const OMath::Vector3<float> vector1(x1, y1, z1);
		const OMath::Vector3<float> Vector3(x2, y2, z2);
		const auto cross = vector1.Cross(Vector3);

		const OMath::Vector3<float> controlCross = {
			y1 * z2 - z1 * y2, 
			z1 * x2 - x1 * z2,
			x1 * y2 - y1 * x2};

		EXPECT_NEAR(cross.mX, controlCross.mX, floatMargin);
		EXPECT_NEAR(cross.mY, controlCross.mY, floatMargin);
		EXPECT_NEAR(cross.mZ, controlCross.mZ, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomDouble();
		const auto x2 = testUtilsVec3.GetRandomDouble();
		const auto y1 = testUtilsVec3.GetRandomDouble();
		const auto y2 = testUtilsVec3.GetRandomDouble();
		const auto z1 = testUtilsVec3.GetRandomDouble();
		const auto z2 = testUtilsVec3.GetRandomDouble();

		const OMath::Vector3<double> vector1(x1, y1, z1);
		const OMath::Vector3<double> Vector3(x2, y2, z2);
		const auto cross = vector1.Cross(Vector3);

		const OMath::Vector3<double> controlCross = {
			y1 * z2 - z1 * y2,
			z1 * x2 - x1 * z2,
			x1 * y2 - y1 * x2 };

		EXPECT_NEAR(cross.mX, controlCross.mX, doubleMargin);
		EXPECT_NEAR(cross.mY, controlCross.mY, doubleMargin);
		EXPECT_NEAR(cross.mZ, controlCross.mZ, doubleMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec3.GetRandomInt();
		const auto x2 = testUtilsVec3.GetRandomInt();
		const auto y1 = testUtilsVec3.GetRandomInt();
		const auto y2 = testUtilsVec3.GetRandomInt();
		const auto z1 = testUtilsVec3.GetRandomInt();
		const auto z2 = testUtilsVec3.GetRandomInt();

		const OMath::Vector3<int> vector1(x1, y1, z1);
		const OMath::Vector3<int> Vector3(x2, y2, z2);
		const auto cross = vector1.Cross(Vector3);

		const OMath::Vector3<int> controlCross = {
			y1 * z2 - z1 * y2,
			z1 * x2 - x1 * z2,
			x1 * y2 - y1 * x2 };

		EXPECT_EQ(cross.mX, controlCross.mX);
		EXPECT_EQ(cross.mY, controlCross.mY);
		EXPECT_EQ(cross.mZ, controlCross.mZ);
	}
}