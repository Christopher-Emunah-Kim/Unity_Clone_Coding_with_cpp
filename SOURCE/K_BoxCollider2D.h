#pragma once
#include "K_ColliderComp.h"


namespace KHS
{
	class BoxCollider2D : public ColliderComp
	{
	public:
		BoxCollider2D();
		virtual ~BoxCollider2D();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

	private:

	};

}


