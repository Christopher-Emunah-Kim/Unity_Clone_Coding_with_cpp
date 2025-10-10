#include "K_Scene.h"
#include "K_Layer.h"

namespace KHS
{
	Scene::Scene()
		:m_layers()
	{
		CreateLayers();
	}
	Scene::~Scene()
	{
	}

	void Scene::CreateLayers()
	{
		m_layers.resize((UINT)ELayerType::MAX, nullptr);

		for (size_t i = 0; i < (UINT)ELayerType::MAX; ++i)
		{
			m_layers[i] = new Layer();
		}
	}

	void Scene::Initialize()
	{
		for (Layer* layer : m_layers)
		{
			if (layer == nullptr)
				continue;

			layer->Initialize();
		}
	}

	void Scene::Update()
	{
		for (Layer* layer : m_layers)
		{
			if (layer == nullptr)
				continue;

			layer->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (Layer* layer : m_layers)
		{
			if (layer == nullptr)
				continue;

			layer->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (Layer* layer : m_layers)
		{
			if (layer == nullptr)
				continue;

			layer->Render(hdc);
		}
	}

	void Scene::OnEnter()
	{
	}

	void Scene::OnExit()
	{
	}

	void Scene::AddGameObject(GameObject* gameObject, ELayerType type)
	{
		if (gameObject == nullptr)
			return;

		m_layers[(UINT)type]->AddGameObject(gameObject);
	}
}