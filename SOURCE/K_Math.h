#pragma once
#include <cmath>

namespace KHS
{
#define PI 3.14159265359f

	struct Vector2D
	{
		Vector2D()
			:x(0.0f), y(0.0f)
		{
		}

		Vector2D(float inX, float inY)
			:x(inX), y(inY)
		{
		}

		Vector2D operator+(const Vector2D& other) const
		{
			return Vector2D(x + other.x, y + other.y);
		}
		Vector2D operator+(float scalar) const
		{
			return Vector2D(x + scalar, y + scalar);
		}
		Vector2D operator-(const Vector2D& other) const
		{
			return Vector2D(x - other.x , y - other.y);
		}
		Vector2D operator-(float scalar) const
		{
			return Vector2D(x - scalar, y - scalar);
		}
		Vector2D operator/(const Vector2D& other) const
		{
			return Vector2D(x / other.x , y / other.y);
		}
		Vector2D operator/(float scalar) const
		{
			return Vector2D(x / scalar, y / scalar);
		}
		Vector2D operator*(const Vector2D& other) const
		{
			return Vector2D(x * other.x , y * other.y);
		}
		Vector2D operator*(float scalar) const
		{
			return Vector2D(x * scalar, y * scalar);
		}

		Vector2D& operator+=(const Vector2D& other)
		{
			x += other.x;
			y += other.y;
			return *this;
		}
		Vector2D& operator-=(const Vector2D& other)
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}

		void Clear()
		{
			x = 0.0f;
			y = 0.0f;
		}

		float Length() const
		{
			return sqrtf(x * x + y * y);
		}

		Vector2D Normalize() const
		{
			float len = Length();

			if (len == 0.0f)
			{
				return Vector2D(0.0f, 0.0f);
			}

			return Vector2D(x / len, y / len);
		}

		Vector2D Rotate(const Vector2D& vec , float degree) const
		{
			float radian = ( degree / 180.f ) * PI;
			vec.Normalize();

			float x = cosf(radian) * vec.x - sinf(radian) * vec.y;
			float y = sinf(radian) * vec.x + cosf(radian) * vec.y;

			return Vector2D(x , y);
		}

		float Dot(const Vector2D& other) const
		{
			return x * other.x +  y * other.y;
		}

		float Cross(const Vector2D& other) const
		{
			return x * other.y - y * other.x;
		}


		float x;
		float y;

		static const Vector2D Zero;
		static const Vector2D One;
		static const Vector2D Up;
		static const Vector2D Right;
		static const Vector2D Down;
		static const Vector2D Left;
	};
}