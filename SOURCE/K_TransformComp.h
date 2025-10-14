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
		Vector2D GetPosition() { return m_position; }

	private:
		Vector2D m_position;
	};
}

