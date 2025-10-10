#include "K_Layer.h"

namespace KHS
{

	Layer::Layer()
	{
	}

	Layer::~Layer()
	{
	}

	void Layer::Initialize()
	{
		for (GameObject* obj : m_gameObjects)
		{
			if (obj == nullptr)
				continue;

			obj->Initialize();
		}
	}

	void Layer::Update()
	{
		for (GameObject* obj : m_gameObjects)
		{
			if (obj == nullptr)
				continue;

			obj->Update();
		}
	}

	void Layer::LateUpdate()
	{
		for (GameObject* obj : m_gameObjects)
		{
			if (obj == nullptr)
				continue;

			obj->LastUpdate();
		}
	}

	void Layer::Render(HDC hdc)
	{
		for (GameObject* obj : m_gameObjects)
		{
			if(obj == nullptr)
				continue;

			obj->Render(hdc);
		}
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		if(gameObject == nullptr)
			return;

		m_gameObjects.push_back(gameObject);
	}
}