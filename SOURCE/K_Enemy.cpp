#include "K_Enemy.h"
#include "K_Input.h"
#include "K_TransformComp.h"
#include "K_Time.h"

namespace KHS
{
	void Enemy::Initialize()
	{
		GameObject::Initialize();
	}
	void Enemy::Update()
	{
		GameObject::Update();
	}
	void Enemy::LastUpdate()
	{
		GameObject::LastUpdate();

	}
	void Enemy::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}