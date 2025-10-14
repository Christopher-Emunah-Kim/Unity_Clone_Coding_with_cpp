#pragma once
#include "K_Component.h"	
#include "K_Texture.h"
#include "K_Math.h"

namespace KHS
{

	class SpriteRendererComp : public Component
	{
	public:
		SpriteRendererComp();
		virtual ~SpriteRendererComp();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

		inline void SetTexture(Texture* texture) { m_texture = texture; }
		inline void SetSize(Vector2D size) { m_imageSize = size; }

	private:
		Texture* m_texture;
		Vector2D m_imageSize;
	};
}

