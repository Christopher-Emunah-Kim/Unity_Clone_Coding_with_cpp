#include "K_Player.h"
#include "K_Input.h"
#include "K_TransformComp.h"
#include "K_Time.h"

namespace KHS
{
	void Player::Initialize()
	{
		GameObject::Initialize();
	}
	void Player::Update()
	{
		GameObject::Update();
	}
	void Player::LastUpdate()
	{
		GameObject::LastUpdate();

		if (Input::GetKeyDown(EKeyCode::RightArrow))
		{
			TransformComp* tr = GetComponent<TransformComp>();
			Vector2D pos = tr->GetPosition();
			pos.x += 100.0f * Time::GetDeltaTime();
			tr->SetPosition(pos);
		}
	}
	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}