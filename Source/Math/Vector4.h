#pragma once
namespace Math {
	template <class T>
	class Vector4 {
	public:
		Vector4<T>();
		Vector4<T>(const T& x, const T& y, const T& z, const T& w);
		Vector4<T>(const Vector4<T>& vector) = default;
		~Vector4<T>() = default;

		Vector4<T>& operator=(const Vector4<T>& vector) = default;

		T operator[](const unsigned int index) {
			switch (index) {
			case 0:
				return mX;
			case 1:
				return mY;
			case 2:
				return mZ;
			case 4:
				return mW;
			}

			static_assert(false && "index out of bounds");
			return 0;
		}

		// Returns the squared length of the vector
		T LengthSqrd() const;

		// Returns the length of the vector
		T Length() const;

		// Returns the normalized value of the vector
		Vector4<T> GetNormalized() const;

		// Normalizes the vector
		void Normalize();

		// Returns the dot product of the current vector and the given vector
		T Dot(const Vector4<T>& vector) const;

		T mX;
		T mY;
		T mZ;
		T mW;
	};
	template<class T>
	inline Vector4<T>::Vector4() : mX(0), mY(0), mZ(0), mW(0) {}

	template<class T>
	inline Vector4<T>::Vector4(const T& x, const T& y, const T& z, const T& w) : mX(x), mY(y), mZ(z), mW(w) {}

	template<class T>
	inline T Vector4<T>::LengthSqrd() const {
		return mX * mX + mY * mY + mZ * mZ + mW * mW;
	}

	template<class T>
	inline T Vector4<T>::Length() const {
		return sqrt(LengthSqrd());
	}

	template<class T>
	inline Vector4<T> Vector4<T>::GetNormalized() const {
		Vector4<T> vec(mX, mY, mZ, mW);
		vec.Normalize();
		return vec;
	}

	template<class T>
	inline void Vector4<T>::Normalize() {
		Vector4<T> vec(mX, mY, mZ, mW);
		if (mX + mY != 0) {
			vec /= vec.Length();
			mX = vec.mX;
			mY = vec.mY;
			mZ = vec.mZ;
			mW = vec.mW;
		}
	}

	template<class T>
	inline T Vector4<T>::Dot(const Vector4<T>& vector) const {
		return mX * vector.mX + mY * vector.mY + mZ * vector.mZ + mW * vector.mW;
	}

	template <class T>
	Vector4<T> operator+(const Vector4<T>& vector0, const Vector4<T>& vector1) {
		return { vector0.mX + vector1.mX, vector0.mY + vector1.mY, vector0.mZ + vector1.mZ, vector0.mW + vector1.mW };
	}

	template <class T>
	void operator+=(const Vector4<T>& vector0, const Vector4<T>& vector1) {
		vector0.mX += vector1.mX;
		vector0.mY += vector1.mY;
		vector0.mZ += vector1.mZ;
		vector0.mW += vector1.mW;
	}


	template <class T>
	Vector4<T> operator-(const Vector4<T>& vector0, const Vector4<T>& vector1) {
		return { vector0.mX - vector1.mX, vector0.mY - vector1.mY, vector0.mZ - vector1.mZ, vector0.mW - vector1.mW };
	}

	template <class T>
	void operator-=(const Vector4<T>& vector0, const Vector4<T>& vector1) {
		vector0.mX -= vector1.mX;
		vector0.mY -= vector1.mY;
		vector0.mZ -= vector1.mZ;
		vector0.mW -= vector1.mW;
	}

	template <class T>
	Vector4<T> operator/(const Vector4<T>& vector0, const Vector4<T>& vector1) {
		return { vector0.mX / vector1.mX, vector0.mY / vector1.mY, vector0.mZ / vector1.mZ, vector0.mW / vector1.mW };
	}

	template <class T>
	void operator/=(const Vector4<T>& vector0, const Vector4<T>& vector1) {
		vector0.mX /= vector1.mX;
		vector0.mY /= vector1.mY;
		vector0.mZ /= vector1.mZ;
		vector0.mW /= vector1.mW;
	}

	template <class T>
	Vector4<T> operator*(const Vector4<T>& vector0, const Vector4<T>& vector1) {
		return { vector0.mX * vector1.mX, vector0.mY * vector1.mY, vector0.mZ * vector1.mZ, vector0.mW * vector1.mW };
	}

	template <class T>
	void operator*=(const Vector4<T>& vector0, const Vector4<T>& vector1) {
		vector0.mX *= vector1.mX;
		vector0.mY *= vector1.mY;
		vector0.mZ *= vector1.mZ;
		vector0.mW *= vector1.mW;
	}
}