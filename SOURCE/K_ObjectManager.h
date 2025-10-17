#pragma once
#include "K_Component.h"
#include "K_Layer.h"
#include "K_GameObject.h"
#include "K_SceneManager.h"
#include "K_Scene.h"
#include "K_TransformComp.h"

namespace KHS::ObjectManager
{
	template <typename T>
	static T* Instantiate(ELayerType type)
	{
		T* gameObject = new T();
		
		Scene* activeScene = SceneManager::GetActiveScene();
		activeScene->AddGameObject(gameObject, type);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(ELayerType type, Vector2D pos)
	{
		T* gameObject = new T();

		TransformComp* tr = gameObject->GetComponent<TransformComp>();
		tr->SetPosition(pos);

		Scene* activeScene = SceneManager::GetActiveScene();
		activeScene->AddGameObject(gameObject, type);

		return gameObject;
	}

	static void Destroy(GameObject* obj)
	{
		if ( obj == nullptr )
		{
			return;
		}

		obj->Death();
	}
}