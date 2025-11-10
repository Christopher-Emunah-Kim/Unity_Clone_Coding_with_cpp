#pragma once
#include "K_Component.h"

namespace KHS
{

	class ColliderComp : public Component
	{
	public:
		ColliderComp();
		~ColliderComp();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

		Vector2D GetOffset() { return m_offset; }
		void SetOffset(Vector2D offset) { m_offset = offset; }

	private:
		Vector2D m_offset;

	};

}