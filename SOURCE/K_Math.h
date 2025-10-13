#pragma once

namespace KHS::Math
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

		float x;
		float y;

		static const Vector2D Zero;
		static const Vector2D One;
	};
	static const Vector2D Zero = Vector2D(0.0f , 0.0f);
	static const Vector2D One = Vector2D(1.0f , 1.0f);
}