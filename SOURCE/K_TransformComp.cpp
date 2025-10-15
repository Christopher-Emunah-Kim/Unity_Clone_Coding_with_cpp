#include "K_TransformComp.h"
#include "K_Input.h"
#include "K_Time.h"

namespace KHS
{
	TransformComp::TransformComp()
		:Component(EComponentType::TRANSFORM) , m_position(Vector2D::Zero) , 
		m_scale(Vector2D::One) , m_rotation(0.0f)
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
		/*const float DEFAULT_OBJECT_SPEED = 100.0f;

		float deltaTime = Time::GetDeltaTime();

		float moveDistance = DEFAULT_OBJECT_SPEED * deltaTime;

		if (Input::GetKey(EKeyCode::A) || Input::GetKey(EKeyCode::LeftArrow))
		{
			m_position.x -= moveDistance;
		}

		if (Input::GetKey(EKeyCode::D) || Input::GetKey(EKeyCode::RightArrow))
		{
			m_position.x += moveDistance;
		}

		if (Input::GetKey(EKeyCode::W) || Input::GetKey(EKeyCode::UpArrow))
		{
			m_position.y -= moveDistance;
		}

		if (Input::GetKey(EKeyCode::S) || Input::GetKey(EKeyCode::DownArrow))
		{
			m_position.y += moveDistance;
		}*/
	}
	void TransformComp::LateUpdate()
	{
	}
	void TransformComp::Render(HDC hdc)
	{
	}
	void TransformComp::SetPosition(Vector2D pos)
	{
		m_position.x = pos.x;
		m_position.y = pos.y;
	}
	void TransformComp::SetRotation(float rotate)
	{
		m_rotation = rotate;
	}
	void TransformComp::SetScale(Vector2D scale)
	{
		m_scale.x = scale.x;
		m_scale.y = scale.y;
	}
}