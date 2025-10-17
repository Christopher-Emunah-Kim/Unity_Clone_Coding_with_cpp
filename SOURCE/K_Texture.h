#pragma once
#include "K_Resource.h"

namespace KHS
{
	class Texture : public Resource
	{
	public:
		enum class ETextureType
		{
			bmp,
			png,
			NONE
		};

		Texture();
		virtual ~Texture();

		virtual HRESULT Load(const std::wstring& path) override;

		static Texture* Create(const std::wstring& name , UINT width , UINT height);

		inline UINT GetWidth() { return m_width; }
		inline UINT GetHeight() { return m_height; }
		inline HDC GetHdc() { return m_hdc; }
		inline ETextureType GetTextureType() { return m_type; }
		inline Gdiplus::Image* GetImage() { return m_image; }
		inline bool HasAlpha() { return m_bAlpha; }

		inline void SetWidth(UINT width) { m_width = width; }
		inline void SetHeight(UINT height) { m_height = height; }
		inline void SetTextureType(ETextureType type) { m_type = type; }

	private:
		ETextureType m_type;
		Gdiplus::Image* m_image;
		HBITMAP m_bitmap;
		HDC m_hdc;

		UINT m_width;
		UINT m_height;
		bool m_bAlpha;
	};
}

