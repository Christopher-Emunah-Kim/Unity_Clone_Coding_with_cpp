#include "K_SpriteRendererComp.h"
#include "K_TransformComp.h"
#include "K_GameObject.h"
#include "K_MainCamera.h"

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
		Vector2D scale = transform->GetScale();
		float rot = transform->GetRotation();

		pos = mainCamera->CalculatePosition(pos);

		if(m_texture->GetTextureType() == Texture::ETextureType::bmp)
		{
			if ( m_texture->HasAlpha() )
			{
				BLENDFUNCTION func = {};
				func.BlendOp = AC_SRC_OVER;
				func.BlendFlags = 0;
				func.AlphaFormat = AC_SRC_ALPHA;
				func.SourceConstantAlpha = 255; //0(transparent) ~ 255(opaque)
				//TODO : 피격 시 투명도 조절


				AlphaBlend(hdc ,
					static_cast< int >( pos.x  ) , 
					static_cast< int >( pos.y  ) ,
					m_texture->GetWidth() * m_imageSize.x * scale.x,
					m_texture->GetHeight() * m_imageSize.y * scale.y,
					m_texture->GetHdc() ,
					0 , 0 ,
					m_texture->GetWidth(),
					m_texture->GetHeight(),
					func);
			}
			else
			{
				////https://blog.naver.com/power2845/50147965306
				TransparentBlt(hdc ,
					static_cast< float >( pos.x ) , static_cast< float >( pos.y )
					, m_texture->GetWidth() * m_imageSize.x * scale.x
					, m_texture->GetHeight() * m_imageSize.y * scale.y
					, m_texture->GetHdc()
					, 0 , 0 ,
					m_texture->GetWidth() ,
					m_texture->GetHeight()
					, RGB(255 , 0 , 255));
			}
		}
		else if(m_texture->GetTextureType() == Texture::ETextureType::png)
		{
			//투명화시킬 색 범위 지정
			Gdiplus::ImageAttributes imageAttr = {};

			imageAttr.SetColorKey(
				Gdiplus::Color(230 , 0 , 230 , 230) ,
				Gdiplus::Color(255 , 0 , 255 , 255) , //magenta
				Gdiplus::ColorAdjustTypeBitmap);

			Gdiplus::Graphics graphics(hdc);

			graphics.TranslateTransform(pos.x , pos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.x , -pos.y);

			graphics.DrawImage(
				m_texture->GetImage() ,
				Gdiplus::Rect
				(
					pos.x, pos.y 
					, m_texture->GetWidth() * m_imageSize.x * scale.x
					, m_texture->GetHeight() * m_imageSize.y * scale.y
				) ,
				0, 0 ,
				m_texture->GetWidth(), m_texture->GetHeight(),
				Gdiplus::UnitPixel ,
				/*&imageAttr*/nullptr);
		}
	}
}