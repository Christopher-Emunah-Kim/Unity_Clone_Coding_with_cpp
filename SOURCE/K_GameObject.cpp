
#include "K_GameObject.h"

namespace KHS
{

	GameObject::GameObject()
		:m_x(0), m_y(0)
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{

		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			m_x += -0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			m_x += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			m_y -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			m_y += 0.01f;
		}

	}

	void GameObject::LastUpdate()
	{
	}

	void GameObject::Render(HDC hdc)
	{
		//파랑 브러쉬 생성
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);
		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));

		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Rectangle(hdc, 100 + m_x, 100 + m_y, 200 + m_x, 200 + m_y);

		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}

	void GameObject::SetPosition(float x, float y)
	{
		m_x = x;
		m_y = y;
	}

}