#pragma once
#include "K_Component.h"

namespace KHS
{
	class GameObject;
	class CameraComp : public Component
	{
	public:
		CameraComp();
		virtual ~CameraComp();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

		Vector2D CalculatePosition(Vector2D pos);
		void SetResolution(const Vector2D& resolution);
		
		inline void SetTarget(GameObject* target) { m_target = target; }

	private:
		GameObject* m_target;
		Vector2D m_distance;
		Vector2D m_resolution;
		Vector2D m_lookPosition;
		bool m_bUseCustomResolution;
	};
}

