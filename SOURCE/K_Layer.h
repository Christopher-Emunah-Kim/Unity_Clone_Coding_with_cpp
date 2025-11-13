#pragma once
#include "CommonInclude.h"
#include "K_Entity.h"
#include "K_GameObject.h"

namespace KHS
{ 
	class Layer : public Entity
	{
	public:
		Layer();
		virtual ~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		void AddGameObject(GameObject* gameObject);

		inline const std::vector<GameObject*>& GetGameObjects() const { return m_gameObjects; }

	private:
		std::vector<GameObject*> m_gameObjects;
	};
}

