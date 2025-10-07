#include "K_Scene.h"

namespace KHS
{
	Scene::Scene()
		:Entity(), m_gameObjects()
	{
	}
	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
	}

	void Scene::Update()
	{
		for (GameObject* obj : m_gameObjects)
		{
			obj->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (GameObject* obj : m_gameObjects)
		{
			obj->LastUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (GameObject* obj : m_gameObjects)
		{
			obj->Render(hdc);
		}
	}
}