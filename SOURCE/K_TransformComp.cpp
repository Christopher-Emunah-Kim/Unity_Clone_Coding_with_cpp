#include "K_TransformComp.h"
#include "K_Input.h"
#include "K_Time.h"

namespace KHS
{
	TransformComp::TransformComp()
		:m_x(0), m_y(0)
	{
	}
	TransformComp::~TransformComp()
	{
	}
	void TransformComp::Initialize()
	{
	}
	void TransformComp::Update()
	{
		const float DEFAULT_OBJECT_SPEED = 100.0f;

		float deltaTime = Time::GetDeltaTime();

		float moveDistance = DEFAULT_OBJECT_SPEED * deltaTime;

		if (Input::GetKey(EKeyCode::A) || Input::GetKey(EKeyCode::LeftArrow))
		{
			m_x -= moveDistance;
		}

		if (Input::GetKey(EKeyCode::D) || Input::GetKey(EKeyCode::RightArrow))
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
	void TransformComp::LastUpdate()
	{
	}
	void TransformComp::Render(HDC hdc)
	{
	}
	void TransformComp::SetPosition(int x, int y)
	{
		m_x = x;
		m_y = y;
	}
}