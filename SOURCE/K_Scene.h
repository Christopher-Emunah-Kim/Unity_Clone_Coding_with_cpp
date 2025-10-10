#pragma once
#include "K_Entity.h"
#include "K_Layer.h"

namespace KHS
{
	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

	private:
		void CreateLayers();

	public:
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObject, ELayerType type);

		Layer* GetLayer(ELayerType type);
	private:
		std::vector<Layer*> m_layers;
	};
}