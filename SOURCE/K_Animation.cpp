#include "K_Animation.h"
#include "K_Time.h"
#include "K_AnimatorComp.h"
#include "K_TransformComp.h"
#include "K_GameObject.h"
#include "K_MainCamera.h"

namespace KHS
{
	Animation::Animation()
		: Resource(EResourceType::ANIMATION) , m_animator(nullptr) , m_spriteTexture(nullptr) ,
		m_animaionSheet{}, m_currentIndex(-1) , m_time(0.0f) , m_bComplete(false)
	{
	}

	Animation::~Animation()
	{
		m_animaionSheet.clear();
		m_currentIndex = -1;
		m_time = 0.0f;
		m_bComplete = false;
	}

	HRESULT Animation::Load(const std::wstring& path)
	{
		//TO DO : load animation data from file
		return E_NOTIMPL;
	}

	void Animation::Update()
	{
		if ( m_bComplete )
		{
			return;
		}

		if ( m_currentIndex < 0 || m_currentIndex >= static_cast<int>(m_animaionSheet.size()) )
		{
			return;
		}

		m_time += Time::GetDeltaTime();

		SpriteInfo& currentSprite = m_animaionSheet[m_currentIndex];

		if ( m_time > currentSprite.duration )
		{
			m_time = 0.0f;
			
			if(m_currentIndex < static_cast<int>(m_animaionSheet.size()) - 1)
			{
				++m_currentIndex;
			}
			else
			{
				m_bComplete = true;
			} 
		}
	}

	void Animation::Render(HDC hdc)
	{
		/*if ( m_bComplete )
		{
			return;
		}*/

		if ( m_currentIndex < 0 || m_currentIndex >= static_cast<int>(m_animaionSheet.size()) )
		{
			return;
		}

		if ( m_spriteTexture == nullptr )
		{
			return;
		}

		GameObject* owner = m_animator->GetOwner();
		TransformComp* tr = owner->GetComponent<TransformComp>();
		Vector2D pos = tr->GetPosition();


		if ( mainCamera )
		{
			pos = mainCamera->CalculatePosition(pos);
		}

		//Alpha Blending(이미지에 알파채널이 있어야함)
		ProcessAlphaBlending(hdc ,tr, pos);
	}

	void Animation::ProcessAlphaBlending(HDC hdc , TransformComp* tr , Vector2D& pos)
	{
		SpriteInfo sprite = m_animaionSheet[ m_currentIndex ];
		Texture::ETextureType type = m_spriteTexture->GetTextureType();

		if ( type == Texture::ETextureType::bmp )
		{
			BLENDFUNCTION func = {};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = AC_SRC_ALPHA;
			func.SourceConstantAlpha = 125; //0(transparent) ~ 255(opaque)
			//TODO : 피격 시 투명도 조절

			HDC spriteHdc = m_spriteTexture->GetHdc();

			AlphaBlend(hdc ,
				static_cast< int >( pos.x ) ,
				static_cast< int >( pos.y ) ,
				static_cast< int >( sprite.size.x * 5 ) ,
				static_cast< int >( sprite.size.y * 5 ) ,
				spriteHdc ,
				static_cast< int >( sprite.leftTop.x ) ,
				static_cast< int >( sprite.leftTop.y ) ,
				static_cast< int >( sprite.size.x ) ,
				static_cast< int >( sprite.size.y ) ,
				func);
		}
		else if( type == Texture::ETextureType::png )
		{
			//make pixel transparent
			Gdiplus::ImageAttributes imageAttr = {};

			//투명화시킬 색 범위 지정
			imageAttr.SetColorKey(
				Gdiplus::Color(230, 0, 230, 230) , //light magenta
				Gdiplus::Color(255, 0, 255, 255) , //magenta
				Gdiplus::ColorAdjustTypeBitmap);

			Gdiplus::Graphics graphics(hdc);

			float rot = tr->GetRotation();
			graphics.TranslateTransform(pos.x , pos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.x , -pos.y);

			Vector2D scale = tr->GetScale();
			float scaleWidth = sprite.size.x * scale.x;
			float scaleHeight = sprite.size.y * scale.y;

			graphics.DrawImage(
				m_spriteTexture->GetImage() ,
				Gdiplus::Rect
				(
					pos.x - ( scaleWidth / 2.0f )
					, pos.y - ( scaleHeight / 2.0f )
					, scaleWidth
					, scaleHeight
				) ,
				sprite.leftTop.x , sprite.leftTop.y ,
				sprite.size.x , sprite.size.y ,
				Gdiplus::UnitPixel ,
				/*&imageAttr*/nullptr);
		}
		else
		{
			assert(false);
			return;
		}

	}

	void Animation::Reset()
	{
		m_currentIndex = 0;
		m_time = 0.0f;
		m_bComplete = false;
	}

	void Animation::CreateAnimation(const std::wstring& name , Texture* spriteTexture ,
		Vector2D leftTop , Vector2D spriteSize , Vector2D offset ,
		UINT spriteLength , float duration)
	{
		if ( spriteTexture == nullptr )
		{
			assert(false);
			return;
		}

		m_spriteTexture = spriteTexture;

		for ( size_t i = 0; i < spriteLength; ++i )
		{
			SpriteInfo spriteInfo;
			spriteInfo.leftTop = Vector2D(leftTop.x + ( spriteSize.x * i ) , leftTop.y);
			spriteInfo.size = spriteSize;
			spriteInfo.offset = offset;
			spriteInfo.duration = duration;

			m_animaionSheet.push_back(spriteInfo);
		}
	}
}