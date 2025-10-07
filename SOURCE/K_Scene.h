#pragma once
#include "K_Entity.h"
#include "K_GameObject.h"

namespace KHS
{
	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

	private:
		std::vector<GameObject*> m_gameObjects;
	};
}