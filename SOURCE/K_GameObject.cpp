
#include "K_GameObject.h"
#include "K_Input.h"
#include "K_Time.h"
#include "K_Component.h"
#include "K_TransformComp.h"

namespace KHS
{

	GameObject::GameObject()
	{
		AddTransformComp();
	}

	GameObject::~GameObject()
	{
		for(Component* component : m_components)
		{
			delete component;
			component = nullptr;
		}
	}

	void GameObject::AddTransformComp()
	{
		AddComponent<TransformComp>();
	}

	void GameObject::Initialize()
	{
		for(Component* component : m_components)
		{
			component->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (Component* component : m_components)
		{
			component->Update();
		}
	}


	void GameObject::LastUpdate()
	{
		for (Component* component : m_components)
		{
			component->LastUpdate();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* component : m_components)
		{
			component->Render(hdc);
		}
	}

}