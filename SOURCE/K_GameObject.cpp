
#include "K_GameObject.h"
#include "K_Input.h"
#include "K_Time.h"

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
		const float DEFAULT_OBJECT_SPEED = 100.0f;

		float deltaTime = Time::GetDeltaTime();

		float moveDistance = DEFAULT_OBJECT_SPEED * deltaTime;

		if (Input::GetKey(EKeyCode::A) || Input::GetKey(EKeyCode::LeftArrow))
		{
			m_x -= moveDistance;
		}

		if (Input::GetKey(EKeyCode::D)|| Input::GetKey(EKeyCode::RightArrow))
		{
			m_x += moveDistance;
		}

		if (Input::GetKey(EKeyCode::W) || Input::GetKey(EKeyCode::UpArrow))
		{
			m_y -= moveDistance;
		}

		if (Input::GetKey(EKeyCode::S) || Input::GetKey(EKeyCode::DownArrow))
		{
			m_y += moveDistance;
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