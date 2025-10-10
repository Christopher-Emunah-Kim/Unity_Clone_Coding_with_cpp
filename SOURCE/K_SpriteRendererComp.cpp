#include "K_SpriteRendererComp.h"
#include "K_TransformComp.h"
#include "K_GameObject.h"

namespace KHS
{
	SpriteRendererComp::SpriteRendererComp()
		:m_image(nullptr)
		, m_imageWidth(0)
		, m_imageHeight(0)
	{
	}
	SpriteRendererComp::~SpriteRendererComp()
	{
	}
	void SpriteRendererComp::Initialize()
	{
	}
	void SpriteRendererComp::Update()
	{
	}
	void SpriteRendererComp::LastUpdate()
	{
	}
	void SpriteRendererComp::Render(HDC hdc)
	{
		TransformComp* transform = GetOwner()->GetComponent<TransformComp>();
		Vector2D pos = transform->GetPosition();

		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage(m_image, Gdiplus::Rect(static_cast<int>(pos.x), static_cast<int>(pos.y), m_imageWidth, m_imageHeight));
	}

	void SpriteRendererComp::ImageLoad(const std::wstring& path)
	{
		
		const wstring combinedPath = DEFAULT_SPRITE_PATH + path + DEFAULT_SPRITE_EXT;
		m_image = Gdiplus::Image::FromFile(combinedPath.c_str());

		if (m_image == nullptr)
		{
			std::wcout << L"Image Load Failed : " << combinedPath << std::endl;
			return;
		}

		m_imageWidth = m_image->GetWidth();
		m_imageHeight = m_image->GetHeight();
	}
}