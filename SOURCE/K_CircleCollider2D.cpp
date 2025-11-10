#include "K_CircleCollider2D.h"

namespace KHS
{
	CircleCollider2D::CircleCollider2D()
		:ColliderComp()
	{
	}

	CircleCollider2D::~CircleCollider2D()
	{
	}

	void CircleCollider2D::Initialize()
	{
		ColliderComp::Initialize();
	}

	void CircleCollider2D::Update()
	{
		ColliderComp::Update();
	}

	void CircleCollider2D::LateUpdate()
	{
		ColliderComp::LateUpdate();
	}

	void CircleCollider2D::Render(HDC hdc)
	{
		ColliderComp::Render(hdc);
	}


}