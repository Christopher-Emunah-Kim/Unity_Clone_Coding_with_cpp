#pragma once
#include "CommonInclude.h"
#include "K_Component.h"

namespace KHS
{
	
	class GameObject
	{
	public:
		enum class EObjectState
		{
			ACTIVE,
			PAUSED,
			DEAD,
			END
		};


		GameObject();
		~GameObject();

	private:
		void AddTransformComp();

	public:
		virtual void Initialize();
		virtual void Update();
		virtual void LastUpdate();
		virtual void Render(HDC hdc);

		template <typename T>
		T* AddComponent()
		{
			static_assert(std::is_base_of<Component, T>::value, "T must be derived from Component");

			T* component = new T();
			component->Initialize();
			component->SetOwner(this);

			m_components[(UINT)component->GetType()] = component;

			return component;
		}

		template <typename T>
		T* GetComponent()
		{
			static_assert(std::is_base_of<Component, T>::value, "T must be derived from Component");

			for (Component* component : m_components)
			{
				T* castedComponent = dynamic_cast<T*>(component);

				if (castedComponent != nullptr)
				{
					return castedComponent;
				}
			}
			return nullptr;
		}

		void SetActive(bool power);
		void Death();

		inline EObjectState GetState() { return m_state; }

	private:
		EObjectState m_state;
		std::vector<Component*> m_components;
	};

}


