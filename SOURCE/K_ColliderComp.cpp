#include "K_ColliderComp.h"


namespace KHS
{
	ColliderComp::ColliderComp()
		:Component(EComponentType::COLLIDER) , m_offset(Vector2D::Zero)
	{
	}

	ColliderComp::~ColliderComp()
	{
	}

	void ColliderComp::Initialize()
	{
		Component::Initialize();
	}

	void ColliderComp::Update()
	{
		Component::Update();
	}

	void ColliderComp::LateUpdate()
	{
		Component::LateUpdate();
	}

	void ColliderComp::Render(HDC hdc)
	{
		Component::Render(hdc);
	}
}