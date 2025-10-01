
#include "K_GameObject.h"
#include "K_Input.h"

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

		if (Input::GetKey(EKeyCode::A) || Input::GetKey(EKeyCode::LeftArrow))
		{
			m_x += -0.01f;
		}

		if (Input::GetKey(EKeyCode::D)|| Input::GetKey(EKeyCode::RightArrow))
		{
			m_x += 0.01f;
		}

		if (Input::GetKey(EKeyCode::W) || Input::GetKey(EKeyCode::UpArrow))
		{
			m_y -= 0.01f;
		}

		if (Input::GetKey(EKeyCode::S) || Input::GetKey(EKeyCode::DownArrow))
		{
			m_y += 0.01f;
		}

	}

	void GameObject::LastUpdate()
	{
	}

	void GameObject::Render(HDC hdc)
	{
		//�Ķ� �귯�� ����
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		// �Ķ� �귯�� DC�� ���� �׸��� ��� �귯�� ��ȯ�� ��ȯ
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