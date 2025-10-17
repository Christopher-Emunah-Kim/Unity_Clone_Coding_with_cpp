#include "K_Layer.h"

namespace KHS
{

	Layer::Layer()
	{
	}

	Layer::~Layer()
	{
		for (GameObject* obj : m_gameObjects)
		{
			if ( obj == nullptr )
			{
				continue;
			}

			delete obj;
			obj = nullptr;
		}
		m_gameObjects.clear();
	}

	void Layer::Initialize()
	{
		for (GameObject* obj : m_gameObjects)
		{
			if ( obj == nullptr )
			{
				continue;
			}

			obj->Initialize();
		}
	}

	void Layer::Update()
	{
		for (GameObject* obj : m_gameObjects)
		{
			if ( obj == nullptr )
			{
				continue;
			}

			GameObject::EObjectState state = obj->GetState();

			if ( state == GameObject::EObjectState::PAUSED
				|| state == GameObject::EObjectState::DEAD )
			{
				continue;
			}

			obj->Update();
		}
	}

	void Layer::LateUpdate()
	{
		for (GameObject* obj : m_gameObjects)
		{
			if ( obj == nullptr )
			{
				continue;
			}

			GameObject::EObjectState state = obj->GetState();

			if ( state == GameObject::EObjectState::PAUSED
				|| state == GameObject::EObjectState::DEAD )
			{
				continue;
			}

			obj->LastUpdate();
		}
	}

	void Layer::Render(HDC hdc)
	{
		for (GameObject* obj : m_gameObjects)
		{
			if ( obj == nullptr )
			{
				continue;
			}

			GameObject::EObjectState state = obj->GetState();

			if ( state == GameObject::EObjectState::PAUSED
				|| state == GameObject::EObjectState::DEAD )
			{
				continue;
			}

			obj->Render(hdc);
		}
	}

	void Layer::Destroy()
	{
		for(std::vector<GameObject*>::iterator iter = m_gameObjects.begin(); iter != m_gameObjects.end();  )
		{
			GameObject::EObjectState state = ( *iter )->GetState();
			if(state == GameObject::EObjectState::DEAD )
			{
				GameObject* deathObj = ( *iter );
				iter = m_gameObjects.erase(iter);

				delete deathObj;
				deathObj = nullptr;

				continue;
			}
			
			//erase로 인해 iter가 다음 원소를 가리키므로 
			//지워지지 않는 경우에만 ++iter
			++iter;
		}
	}


	void Layer::AddGameObject(GameObject* gameObject)
	{
		if(gameObject == nullptr)
			return;

		m_gameObjects.push_back(gameObject);
	}
}