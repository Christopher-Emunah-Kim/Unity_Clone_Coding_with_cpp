#include "K_SpriteRendererComp.h"
#include "K_TransformComp.h"
#include "K_GameObject.h"

namespace KHS
{
	SpriteRendererComp::SpriteRendererComp()
		:Component(EComponentType::SPRITERENDERER), m_texture(nullptr), m_imageSize(Vector2D::One)
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
	void SpriteRendererComp::LateUpdate()
	{
	}
	void SpriteRendererComp::Render(HDC hdc)
	{
		if ( m_texture == nullptr )
		{
			assert(false);
		}

		TransformComp* transform = GetOwner()->GetComponent<TransformComp>();
		Vector2D pos = transform->GetPosition();

		if(m_texture->GetTextureType() == Texture::ETextureType::bmp)
		{
			//https://blog.naver.com/power2845/50147965306
			TransparentBlt(hdc , pos.x , pos.y
				, m_texture->GetWidth() * m_imageSize.x , m_texture->GetHeight() * m_imageSize.y
				, m_texture->GetHdc() , 0 , 0 , m_texture->GetWidth() , m_texture->GetHeight()
				, RGB(255 , 0 , 255));
		}
		else if(m_texture->GetTextureType() == Texture::ETextureType::png)
		{
			Gdiplus::Graphics graphics(hdc);
			graphics.DrawImage(m_texture->GetImage(),Gdiplus::Rect(pos.x, pos.y, m_texture->GetWidth()*m_imageSize.x, m_texture->GetHeight()*m_imageSize.y));
		}
	}
}