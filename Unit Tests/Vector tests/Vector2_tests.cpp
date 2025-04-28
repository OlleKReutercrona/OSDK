#include "gtest/gtest.h"

#include "Math/Vector2.h"
#include "../TestUtilities.h"

constexpr float floatMargin = 0.0000001f;
constexpr double doubleMargin = 0.0000001;

TestUtilities testUtilsVec2;

TEST(Vector2_tests, Constructors) {
	const OMath::Vector2<int> vectorDefaultI;
	EXPECT_EQ(vectorDefaultI.mX, 0);
	EXPECT_EQ(vectorDefaultI.mY, 0);

	const OMath::Vector2<float> vectorDefaultF;
	EXPECT_EQ(vectorDefaultF.mX, 0);
	EXPECT_EQ(vectorDefaultF.mY, 0);

	const OMath::Vector2<double> vectorDefaultD;
	EXPECT_EQ(vectorDefaultD.mX, 0);
	EXPECT_EQ(vectorDefaultD.mY, 0);

	for (int i = 0; i < 100; ++i) {
		const int x = testUtilsVec2.GetRandomInt();
		const int y = testUtilsVec2.GetRandomInt();

		const OMath::Vector2<int> vector(x, y);
		EXPECT_EQ(vector.mX, x);
		EXPECT_EQ(vector.mY, y);
	}

	for (int i = 0; i < 100; ++i) {
		const float x = testUtilsVec2.GetRandomFloat();
		const float y = testUtilsVec2.GetRandomFloat();

		const OMath::Vector2<float> vector(x, y);
		EXPECT_EQ(vector.mX, x);
		EXPECT_EQ(vector.mY, y);
	}

	for (int i = 0; i < 100; ++i) {
		const double x = testUtilsVec2.GetRandomDouble();
		const double y = testUtilsVec2.GetRandomDouble();

		const OMath::Vector2<double> vector(x, y);
		EXPECT_EQ(vector.mX, x);
		EXPECT_EQ(vector.mY, y);
	}

	for (int i = 0; i < 100; ++i) {
		const int x = testUtilsVec2.GetRandomInt();
		const int y = testUtilsVec2.GetRandomInt();

		const OMath::Vector2<int> vector(x, y);
		const auto copyVector(vector);
		EXPECT_EQ(copyVector.mX, x);
		EXPECT_EQ(copyVector.mY, y);
	}

	for (int i = 0; i < 100; ++i) {
		const float x = testUtilsVec2.GetRandomFloat();
		const float y = testUtilsVec2.GetRandomFloat();

		const OMath::Vector2<float> vector(x, y);
		const auto copyVector(vector);
		EXPECT_EQ(copyVector.mX, x);
		EXPECT_EQ(copyVector.mY, y);
	}

	for (int i = 0; i < 100; ++i) {
		const double x = testUtilsVec2.GetRandomDouble();
		const double y = testUtilsVec2.GetRandomDouble();

		const OMath::Vector2<double> vector(x, y);
		const auto copyVector(vector);
		EXPECT_EQ(copyVector.mX, x);
		EXPECT_EQ(copyVector.mY, y);
	}
}

TEST(Vector2_tests, Assignment) {
	for (int i = 0; i < 100; i++) {
		const auto x = testUtilsVec2.GetRandomFloat();
		const auto y = testUtilsVec2.GetRandomFloat();

		const OMath::Vector2<float> originalVec(x, y);
		auto copyVector = originalVec;
		EXPECT_EQ(copyVector.mX, x);
		EXPECT_EQ(copyVector.mY, y);
	}

	for (int i = 0; i < 100; i++) {
		const auto x = testUtilsVec2.GetRandomDouble();
		const auto y = testUtilsVec2.GetRandomDouble();

		const OMath::Vector2<double> originalVec(x, y);
		auto copyVector = originalVec;
		EXPECT_EQ(copyVector.mX, x);
		EXPECT_EQ(copyVector.mY, y);
	}

	for (int i = 0; i < 100; i++) {
		const auto x = testUtilsVec2.GetRandomInt();
		const auto y = testUtilsVec2.GetRandomInt();

		const OMath::Vector2<int> originalVec(x, y);
		auto copyVector = originalVec;
		EXPECT_EQ(copyVector.mX, x);
		EXPECT_EQ(copyVector.mY, y);
	}
}

TEST(Vector2_tests, Addition) {
	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec2.GetRandomFloat();
		const auto y1 = testUtilsVec2.GetRandomFloat();
		const auto x2 = testUtilsVec2.GetRandomFloat();
		const auto y2 = testUtilsVec2.GetRandomFloat();

		const OMath::Vector2<float> vector1(x1, y1);
		const OMath::Vector2<float> vector2(x2, y2);
		const auto resultVector = vector1 + vector2;

		EXPECT_NEAR(resultVector.mX, x1 + x2, floatMargin);
		EXPECT_NEAR(resultVector.mY, y1 + y2, floatMargin);

		const auto x3 = testUtilsVec2.GetRandomFloat();
		const auto y3 = testUtilsVec2.GetRandomFloat();

		OMath::Vector2<float> vector4(x3, y3);
		vector4 += resultVector;

		const float xResult = x1 + x2 + x3;
		const float yResult = y1 + y2 + y3;
		EXPECT_NEAR(vector4.mX, xResult, floatMargin);
		EXPECT_NEAR(vector4.mY, yResult, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec2.GetRandomDouble();
		const auto y1 = testUtilsVec2.GetRandomDouble();
		const auto x2 = testUtilsVec2.GetRandomDouble();
		const auto y2 = testUtilsVec2.GetRandomDouble();

		const OMath::Vector2<double> vector1(x1, y1);
		const OMath::Vector2<double> vector2(x2, y2);
		const auto resultVector = vector1 + vector2;

		EXPECT_NEAR(resultVector.mX, x1 + x2, doubleMargin);
		EXPECT_NEAR(resultVector.mY, y1 + y2, doubleMargin);

		const auto x3 = testUtilsVec2.GetRandomDouble();
		const auto y3 = testUtilsVec2.GetRandomDouble();

		OMath::Vector2<double> vector4(x3, y3);
		vector4 += resultVector;

		const auto xResult = x1 + x2 + x3;
		const auto yResult = y1 + y2 + y3;
		EXPECT_NEAR(vector4.mX, xResult, doubleMargin);
		EXPECT_NEAR(vector4.mY, yResult, doubleMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec2.GetRandomInt();
		const auto y1 = testUtilsVec2.GetRandomInt();
		const auto x2 = testUtilsVec2.GetRandomInt();
		const auto y2 = testUtilsVec2.GetRandomInt();

		const OMath::Vector2<int> vector1(x1, y1);
		const OMath::Vector2<int> vector2(x2, y2);
		const auto resultVector = vector1 + vector2;

		EXPECT_EQ(resultVector.mX, x1 + x2);
		EXPECT_EQ(resultVector.mY, y1 + y2);

		const auto x3 = testUtilsVec2.GetRandomInt();
		const auto y3 = testUtilsVec2.GetRandomInt();

		OMath::Vector2<int> vector4(x3, y3);
		vector4 += resultVector;

		const auto xResult = x1 + x2 + x3;
		const auto yResult = y1 + y2 + y3;
		EXPECT_EQ(vector4.mX, x1 + x2 + x3);
		EXPECT_EQ(vector4.mY, y1 + y2 + y3);
	}
}

TEST(Vector2_tests, Subtraction) {
	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec2.GetRandomFloat();
		const auto y1 = testUtilsVec2.GetRandomFloat();
		const auto x2 = testUtilsVec2.GetRandomFloat();
		const auto y2 = testUtilsVec2.GetRandomFloat();

		const OMath::Vector2<float> vector1(x1, y1);
		const OMath::Vector2<float> vector2(x2, y2);
		const auto resultVector = vector1 - vector2;

		EXPECT_NEAR(resultVector.mX, x1 - x2, floatMargin);
		EXPECT_NEAR(resultVector.mY, y1 - y2, floatMargin);

		const auto x3 = testUtilsVec2.GetRandomFloat();
		const auto y3 = testUtilsVec2.GetRandomFloat();

		OMath::Vector2<float> vector4(x3, y3);
		vector4 -= resultVector;

		const auto xValue = x3 - (x1 - x2);
		const auto yValue = y3 - (y1 - y2);

		EXPECT_NEAR(vector4.mX, xValue, floatMargin);
		EXPECT_NEAR(vector4.mY, yValue, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec2.GetRandomDouble();
		const auto y1 = testUtilsVec2.GetRandomDouble();
		const auto x2 = testUtilsVec2.GetRandomDouble();
		const auto y2 = testUtilsVec2.GetRandomDouble();

		const OMath::Vector2<double> vector1(x1, y1);
		const OMath::Vector2<double> vector2(x2, y2);
		const auto resultVector = vector1 - vector2;

		EXPECT_NEAR(resultVector.mX, x1 - x2, doubleMargin);
		EXPECT_NEAR(resultVector.mY, y1 - y2, doubleMargin);

		const auto x3 = testUtilsVec2.GetRandomDouble();
		const auto y3 = testUtilsVec2.GetRandomDouble();

		OMath::Vector2<double> vector4(x3, y3);
		vector4 -= resultVector;

		const auto xValue = x3 - (x1 - x2);
		const auto yValue = y3 - (y1 - y2);

		EXPECT_NEAR(vector4.mX, xValue, floatMargin);
		EXPECT_NEAR(vector4.mY, yValue, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec2.GetRandomInt();
		const auto y1 = testUtilsVec2.GetRandomInt();
		const auto x2 = testUtilsVec2.GetRandomInt();
		const auto y2 = testUtilsVec2.GetRandomInt();
		const auto x3 = testUtilsVec2.GetRandomInt();
		const auto y3 = testUtilsVec2.GetRandomInt();

		const OMath::Vector2<int> vector1(x1, y1);
		const OMath::Vector2<int> vector2(x2, y2);
		const auto resultVector = vector1 - vector2;

		EXPECT_EQ(resultVector.mX, x1 - x2);
		EXPECT_EQ(resultVector.mY, y1 - y2);

		OMath::Vector2<int> vector4(x3, y3);
		vector4 -= resultVector;

	const auto xValue = x3 - (x1 - x2);
		const auto yValue = y3 - (y1 - y2);

		EXPECT_EQ(vector4.mX, xValue);
		EXPECT_EQ(vector4.mY, yValue);
	}
}

TEST(Vector2_tests, Multiplication) {
	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec2.GetRandomFloat();
		const auto y1 = testUtilsVec2.GetRandomFloat();
		const auto x2 = testUtilsVec2.GetRandomFloat();
		const auto y2 = testUtilsVec2.GetRandomFloat();

		const OMath::Vector2<float> vector1(x1, y1);
		const OMath::Vector2<float> vector2(x2, y2);
		const auto resultVector = vector1 * vector2;

		EXPECT_NEAR(resultVector.mX, x1 * x2, floatMargin);
		EXPECT_NEAR(resultVector.mY, y1 * y2, floatMargin);

		const auto x3 = testUtilsVec2.GetRandomFloat();
		const auto y3 = testUtilsVec2.GetRandomFloat();

		OMath::Vector2<float> vector4(x3, y3);
		vector4 *= resultVector;

		const auto xValue = x3 * (x1 * x2);
		const auto yValue = y3 * (y1 * y2);

		EXPECT_NEAR(vector4.mX, xValue, floatMargin);
		EXPECT_NEAR(vector4.mY, yValue, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec2.GetRandomDouble();
		const auto y1 = testUtilsVec2.GetRandomDouble();
		const auto x2 = testUtilsVec2.GetRandomDouble();
		const auto y2 = testUtilsVec2.GetRandomDouble();

		const OMath::Vector2<double> vector1(x1, y1);
		const OMath::Vector2<double> vector2(x2, y2);
		const auto resultVector = vector1 * vector2;

		EXPECT_NEAR(resultVector.mX, x1 * x2, doubleMargin);
		EXPECT_NEAR(resultVector.mY, y1 * y2, doubleMargin);

		const auto x3 = testUtilsVec2.GetRandomDouble();
		const auto y3 = testUtilsVec2.GetRandomDouble();

		OMath::Vector2<double> vector4(x3, y3);
		vector4 *= resultVector;

		const auto xValue = x3 * (x1 * x2);
		const auto yValue = y3 * (y1 * y2);

		EXPECT_NEAR(vector4.mX, xValue, floatMargin);
		EXPECT_NEAR(vector4.mY, yValue, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec2.GetRandomInt();
		const auto y1 = testUtilsVec2.GetRandomInt();
		const auto x2 = testUtilsVec2.GetRandomInt();
		const auto y2 = testUtilsVec2.GetRandomInt();
		const auto x3 = testUtilsVec2.GetRandomInt();
		const auto y3 = testUtilsVec2.GetRandomInt();

		const OMath::Vector2<int> vector1(x1, y1);
		const OMath::Vector2<int> vector2(x2, y2);
		const auto resultVector = vector1 * vector2;

		EXPECT_EQ(resultVector.mX, x1 * x2);
		EXPECT_EQ(resultVector.mY, y1 * y2);

		OMath::Vector2<int> vector4(x3, y3);
		vector4 *= resultVector;

		const auto xValue = x3 * (x1 * x2);
		const auto yValue = y3 * (y1 * y2);

		EXPECT_EQ(vector4.mX, xValue);
		EXPECT_EQ(vector4.mY, yValue);
	}
}

TEST(Vector2_tests, LengthSquared) {
	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec2.GetRandomFloat();
		const auto y1 = testUtilsVec2.GetRandomFloat();

		const OMath::Vector2<float> vector(x1, y1);
		const auto lengthSqrd = vector.LengthSqrd();
		const auto expectedValue = x1 * x1 + y1 * y1;

		EXPECT_NEAR(lengthSqrd, expectedValue, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec2.GetRandomDouble();
		const auto y1 = testUtilsVec2.GetRandomDouble();

		const OMath::Vector2<double> vector(x1, y1);
		const auto lengthSqrd = vector.LengthSqrd();
		const auto expectedValue = x1 * x1 + y1 * y1;

		EXPECT_NEAR(lengthSqrd, expectedValue, doubleMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec2.GetRandomInt();
		const auto y1 = testUtilsVec2.GetRandomInt();

		const OMath::Vector2<int> vector(x1, y1);
		const auto result = vector.LengthSqrd();
		const auto expectedValue = x1 * x1 + y1 * y1;
		EXPECT_EQ(result, expectedValue);
	}
}

TEST(Vector2_tests, Length) {
	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec2.GetRandomFloat();
		const auto y1 = testUtilsVec2.GetRandomFloat();

		const OMath::Vector2<float> vector(x1, y1);
		const auto length = vector.Length();
		const float expectedValue = sqrt(x1 * x1 + y1 * y1);

		EXPECT_NEAR(length, expectedValue, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec2.GetRandomDouble();
		const auto y1 = testUtilsVec2.GetRandomDouble();

		const OMath::Vector2<double> vector(x1, y1);
		const auto length = vector.Length();
		const double expectedValue = sqrt(x1 * x1 + y1 * y1);

		EXPECT_NEAR(length, expectedValue, doubleMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec2.GetRandomInt();
		const auto y1 = testUtilsVec2.GetRandomInt();

		const OMath::Vector2<int> vector(x1, y1);
		const auto length = vector.Length();
		const int expectedValue = static_cast<int>(sqrt(x1 * x1 + y1 * y1));

		EXPECT_EQ(length, expectedValue);
	}
}

TEST(Vector2_tests, GetNormalized) {
	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec2.GetRandomFloat();
		const auto y1 = testUtilsVec2.GetRandomFloat();

		const OMath::Vector2<float> vector(x1, y1);
		const auto normalizedVector = vector.GetNormalized();
		const auto length = vector.Length();
		const OMath::Vector2<float> expectedValue(
			vector.mX / length,
			vector.mY / length);

		EXPECT_NEAR(normalizedVector.mX, expectedValue.mX, floatMargin);
		EXPECT_NEAR(normalizedVector.mY, expectedValue.mY, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec2.GetRandomDouble();
		const auto y1 = testUtilsVec2.GetRandomDouble();

		const OMath::Vector2<double> vector(x1, y1);
		const auto normalizedVector = vector.GetNormalized();
		const auto length = vector.Length();
		const OMath::Vector2<double> expectedValue(
			vector.mX / length,
			vector.mY / length);

		EXPECT_NEAR(normalizedVector.mX, expectedValue.mX, doubleMargin);
		EXPECT_NEAR(normalizedVector.mY, expectedValue.mY, doubleMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec2.GetRandomInt();
		const auto y1 = testUtilsVec2.GetRandomInt();

		const OMath::Vector2<int> vector(x1, y1);
		const auto normalizedVector = vector.GetNormalized();
		const auto length = vector.Length();
		const OMath::Vector2<int> expectedValue(
			vector.mX / length,
			vector.mY / length);

		EXPECT_EQ(normalizedVector.mX, expectedValue.mX);
		EXPECT_EQ(normalizedVector.mY, expectedValue.mY);
	}
}

TEST(Vector2_tests, Length_Zero) {
	OMath::Vector2<float> vectorF;
	EXPECT_EQ(vectorF.Length(), 0.0f);

	OMath::Vector2<double> vectorD;
	EXPECT_EQ(vectorD.Length(), 0.0);

	OMath::Vector2<int> vectorI;
	EXPECT_EQ(vectorI.Length(), 0);
}

TEST(Vector2_tests, Normalize_Zero) {
	OMath::Vector2<float> vectorF;
	vectorF.Normalize();
	OMath::Vector2<float> normalizedVectorF = vectorF.GetNormalized();
	EXPECT_EQ(vectorF.Length(), 0.0f);
	EXPECT_EQ(normalizedVectorF.Length(), 0.0f);

	OMath::Vector2<double> vectorD;
	vectorD.Normalize();
	OMath::Vector2<double> normalizedVectorD = vectorD.GetNormalized();
	EXPECT_EQ(vectorD.Length(), 0.0);
	EXPECT_EQ(normalizedVectorD.Length(), 0.0);

	OMath::Vector2<int> vectorI;
	vectorI .Normalize();
	OMath::Vector2<int> normalizedVectorI = vectorI.GetNormalized();
	EXPECT_EQ(vectorI.Length(), 0);
	EXPECT_EQ(normalizedVectorI.Length(), 0);
}

TEST(Vector2_tests, Dot) {
	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec2.GetRandomFloat();
		const auto x2 = testUtilsVec2.GetRandomFloat();
		const auto y1 = testUtilsVec2.GetRandomFloat();
		const auto y2 = testUtilsVec2.GetRandomFloat();

		const OMath::Vector2<float> vector1(x1, y1);
		const OMath::Vector2<float> vector2(x2, y2);
		const auto dot = vector1.Dot(vector2);

		const auto controlDot = x1 * x2 + y1 * y2;

		EXPECT_NEAR(dot, controlDot, floatMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec2.GetRandomDouble();
		const auto x2 = testUtilsVec2.GetRandomDouble();
		const auto y1 = testUtilsVec2.GetRandomDouble();
		const auto y2 = testUtilsVec2.GetRandomDouble();

		const OMath::Vector2<double> vector1(x1, y1);
		const OMath::Vector2<double> vector2(x2, y2);
		const auto dot = vector1.Dot(vector2);

		const auto controlDot = x1 * x2 + y1 * y2;

		EXPECT_NEAR(dot, controlDot, doubleMargin);
	}

	for (int i = 0; i < 100; i++) {
		const auto x1 = testUtilsVec2.GetRandomInt();
		const auto x2 = testUtilsVec2.GetRandomInt();
		const auto y1 = testUtilsVec2.GetRandomInt();
		const auto y2 = testUtilsVec2.GetRandomInt();

		const OMath::Vector2<int> vector1(x1, y1);
		const OMath::Vector2<int> vector2(x2, y2);
		const auto dot = vector1.Dot(vector2);

		const auto controlDot = x1 * x2 + y1 * y2;

		EXPECT_EQ(dot, controlDot);
	}
}