#include "K_ColliderComp.h"
#include "K_ScriptComp.h"	
#include "K_GameObject.h"


namespace KHS
{
	UINT ColliderComp::COLLISION_ID_COUNT = 1;

	ColliderComp::ColliderComp()
		:Component(EComponentType::COLLIDER) , m_offset(Vector2D::Zero),
		m_size(Vector2D::One), m_colliderID(COLLISION_ID_COUNT++)
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
	void ColliderComp::OnCollisionEnter(ColliderComp* other)
	{
		ScriptComp* script = GetOwner()->GetComponent<ScriptComp>();
		if (script)
		{
			script->OnCollisionEnter(other);
		}
	}
	void ColliderComp::OnCollisionStay(ColliderComp* other)
	{
		ScriptComp* script = GetOwner()->GetComponent<ScriptComp>();
		if (script)
		{
			script->OnCollisionStay(other);
		}

	}
	void ColliderComp::OnCollisionExit(ColliderComp* other)
	{
		ScriptComp* script = GetOwner()->GetComponent<ScriptComp>();
		if (script)
		{
			script->OnCollisionExit(other);
		}
	}
}