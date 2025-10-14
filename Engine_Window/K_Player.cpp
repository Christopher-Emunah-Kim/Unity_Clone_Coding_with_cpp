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

	}
	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}