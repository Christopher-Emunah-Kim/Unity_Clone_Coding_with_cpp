#pragma once
#include "K_Entity.h"

namespace KHS
{
	class GameObject;

	class Component : public Entity
	{
	public:
		Component(EComponentType type);
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);


		inline void SetOwner(GameObject* owner) { m_owner = owner; }
		inline GameObject* GetOwner() { return m_owner; }
		inline EComponentType GetType() { return m_type; }

	private:
		GameObject* m_owner;
		EComponentType m_type;
	};
}


