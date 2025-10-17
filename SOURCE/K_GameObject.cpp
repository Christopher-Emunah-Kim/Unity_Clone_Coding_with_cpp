
#include "K_GameObject.h"
#include "K_Input.h"
#include "K_Time.h"
#include "K_Component.h"
#include "K_TransformComp.h"

namespace KHS
{

	GameObject::GameObject()
		: m_state(EObjectState::ACTIVE)
	{
		m_components.resize(( UINT ) EComponentType::END);
		AddTransformComp();
	}

	GameObject::~GameObject()
	{
		for(Component* component : m_components)
		{
			if(component == nullptr)
			{
				continue;
			}
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
			if(component == nullptr)
			{
				continue;
			}

			component->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (Component* component : m_components)
		{
			if ( component == nullptr )
			{
				continue;
			}

			component->Update();
		}
	}


	void GameObject::LastUpdate()
	{
		for (Component* component : m_components)
		{
			if ( component == nullptr )
			{
				continue;
			}

			component->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* component : m_components)
		{
			if ( component == nullptr )
			{
				continue;
			}

			component->Render(hdc);
		}
	}

	void GameObject::SetActive(bool power)
	{
		if ( power == true )
		{
			m_state = EObjectState::ACTIVE;
		}
		
		if( power == false )
		{
			m_state = EObjectState::PAUSED;
		}
	}

	void GameObject::Death()
	{
		m_state = EObjectState::DEAD;
	}
}