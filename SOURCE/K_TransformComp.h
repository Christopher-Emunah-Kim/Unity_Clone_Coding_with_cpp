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
		virtual void LastUpdate() override;
		virtual void Render(HDC hdc) override;

		void SetPosition(int x, int y);
		
		inline int GetX() { return m_x; }
		inline int GetY() { return m_y; }

	private:
		int m_x;
		int m_y;
	};
}

