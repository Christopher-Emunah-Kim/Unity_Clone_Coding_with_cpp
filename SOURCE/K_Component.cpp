#include "K_Component.h"

namespace KHS
{

	Component::Component(EComponentType type)
		:m_owner(nullptr) , m_type(type)
	{
	}

	Component::~Component()
	{
	}

	void Component::Initialize()
	{
	}

	void Component::Update()
	{
	}

	void Component::LateUpdate()
	{
	}

	void Component::Render(HDC hdc)
	{
	}
}