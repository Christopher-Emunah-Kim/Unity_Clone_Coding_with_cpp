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
	};
}