#include "K_Texture.h"
#include "K_Application.h"
#include "K_ResourceTable.h"

extern KHS::Application app;

namespace KHS
{
	Texture::Texture()
		:Resource(EResourceType::TEXTURE) , m_type(ETextureType::NONE) , 
		m_image(nullptr) , m_bitmap(nullptr) , m_hdc(nullptr) ,
		m_bAlpha(false) , m_width(0) , m_height(0)
	{
	}

	Texture::~Texture()
	{
		if (m_image != nullptr)
		{
			delete m_image;
			m_image = nullptr;
		}
		if (m_bitmap != nullptr)
		{
			DeleteObject(m_bitmap);
			m_bitmap = nullptr;
		}
		if (m_hdc != nullptr)
		{
			DeleteDC(m_hdc);
			m_hdc = nullptr;
		}
	}

	HRESULT Texture::Load(const std::wstring& path)
	{
		std::wstring ext = path.substr(path.find_last_of(L".") + 1);

		//extension check
		if(ext == L"bmp")
		{
			m_type = ETextureType::bmp;
			m_bitmap = ( HBITMAP ) LoadImage(nullptr , path.c_str() , IMAGE_BITMAP , 0 , 0 , LR_LOADFROMFILE | LR_CREATEDIBSECTION);

			if ( m_bitmap == nullptr )
			{
				return S_FALSE;
			}

			BITMAP info = {};
			GetObject(m_bitmap , sizeof(BITMAP) , &info);

			m_width = info.bmWidth;
			m_height = info.bmHeight;

			HDC mainDC = app.GetHdc();
			m_hdc = CreateCompatibleDC(mainDC);

			HBITMAP oldBitmap = ( HBITMAP ) SelectObject(m_hdc , m_bitmap);
			DeleteObject(oldBitmap);
		}
		else if (ext == L"png")
		{
			m_type = ETextureType::png;
			m_image = Gdiplus::Image::FromFile(path.c_str());
			if (m_image == nullptr)
			{
				return S_FALSE;
			}
			m_width = m_image->GetWidth();
			m_height = m_image->GetHeight();
		}
		else
		{
			m_type = ETextureType::NONE;
			assert(false);
			return E_FAIL;
		}

		return S_OK;
	}

	Texture* Texture::Create(const std::wstring& name, UINT width, UINT height)
	{
		Texture* texture = ResourceTable::Find<Texture>(name);

		if ( texture )
		{
			return texture;
		}

		texture = new Texture();

		texture->SetName(name);
		texture->SetWidth(width);
		texture->SetHeight(height);

		//create bitmap and hdc
		HDC mainDC = app.GetHdc();
		texture->m_bitmap = CreateCompatibleBitmap(mainDC, width, height);
		texture->m_hdc = CreateCompatibleDC(mainDC);

		//select bitmap to hdc
		HBITMAP oldBitmap = (HBITMAP)SelectObject(texture->m_hdc, texture->m_bitmap);
		DeleteObject(oldBitmap);

		//insert to resource table
		ResourceTable::Insert(name + L"Image" , texture);

		return texture;
	}
}