#pragma once
#include "K_Component.h"	

namespace KHS
{
	class TransformComp : public Component
	{
	public:
		TransformComp();
		virtual ~TransformComp();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

		void SetPosition(Vector2D pos);
		void SetRotation(float rotate);
		void SetScale(Vector2D scale);

		inline Vector2D GetPosition() { return m_position; }
		inline Vector2D GetScale() { return m_scale; }
		inline float GetRotation() { return m_rotation; }
		

	private:
		Vector2D m_position;
		Vector2D m_scale;
		float m_rotation;
	};
}

