#pragma once

namespace KHS
{
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
		Vector2D operator-(const Vector2D& other) const
		{
			return Vector2D(x - other.x , y - other.y);
		}
		Vector2D operator/(float scalar) const
		{
			return Vector2D(x / scalar, y / scalar);
		}
		Vector2D operator*(float scalar) const
		{
			return Vector2D(x * scalar, y * scalar);
		}


		float x;
		float y;

		static const Vector2D Zero;
		static const Vector2D One;
	};
}