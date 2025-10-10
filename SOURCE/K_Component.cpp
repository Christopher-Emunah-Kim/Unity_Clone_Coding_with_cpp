#include "K_Component.h"

namespace KHS
{

	Component::Component()
		:m_owner(nullptr)
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

	void Component::LastUpdate()
	{
	}

	void Component::Render(HDC hdc)
	{
	}
}