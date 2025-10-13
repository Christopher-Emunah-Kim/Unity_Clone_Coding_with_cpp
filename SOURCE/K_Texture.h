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

		inline UINT GetWidth() { return m_width; }
		inline UINT GetHeight() { return m_height; }
		inline HDC GetHdc() { return m_hdc; }
		inline ETextureType GetTextureType() { return m_type; }
		inline Gdiplus::Image* GetImage() { return m_image; }

	private:
		ETextureType m_type;
		Gdiplus::Image* m_image;
		HBITMAP m_bitmap;
		HDC m_hdc;

		UINT m_width;
		UINT m_height;
	};
}

