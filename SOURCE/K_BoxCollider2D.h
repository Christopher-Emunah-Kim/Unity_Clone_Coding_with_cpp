#pragma once
#include "K_ColliderComp.h"


namespace KHS
{
	class BoxCollider2D : public ColliderComp
	{
	public:
		BoxCollider2D();
		virtual ~BoxCollider2D();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

		inline void SetSize(const Vector2D& size) { m_size = size; }
		inline Vector2D GetSize() const { return m_size; }

	private:
		Vector2D m_size;

	};

}


