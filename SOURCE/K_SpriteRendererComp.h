#pragma once
#include "K_Component.h"	

namespace KHS
{
	class SpriteRendererComp : public Component
	{
	public:
		SpriteRendererComp();
		virtual ~SpriteRendererComp();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LastUpdate() override;
		virtual void Render(HDC hdc) override;

	private:

	};
}

