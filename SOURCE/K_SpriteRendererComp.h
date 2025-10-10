#pragma once
#include "K_Component.h"	

namespace KHS
{
	const wstring DEFAULT_SPRITE_PATH = L"..\\Resources\\";
	const wstring DEFAULT_SPRITE_EXT = L".png";

	class SpriteRendererComp : public Component
	{
	public:
		SpriteRendererComp();
		virtual ~SpriteRendererComp();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LastUpdate() override;
		virtual void Render(HDC hdc) override;

		void ImageLoad(const std::wstring& path);

	private:
		Gdiplus::Image* m_image;
		UINT m_imageWidth;
		UINT m_imageHeight;
	};
}

