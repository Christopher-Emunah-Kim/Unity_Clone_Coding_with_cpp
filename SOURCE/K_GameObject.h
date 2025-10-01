#pragma once
#include "CommonInclude.h"

namespace KHS
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LastUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y);

		inline float GetX() const { return m_x; }
		inline float GetY() const { return m_y; }

	private:
		float m_x;
		float m_y;
	};

}


