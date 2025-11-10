#pragma once
#include "K_ColliderComp.h"

namespace KHS
{

	class CircleCollider2D : public ColliderComp
	{
	public:
		CircleCollider2D();
		virtual ~CircleCollider2D();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

	private:
		float m_radius;

	};

}



