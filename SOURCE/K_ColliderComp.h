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

		virtual void OnCollisionEnter(ColliderComp* other);
		virtual void OnCollisionStay(ColliderComp* other);
		virtual void OnCollisionExit(ColliderComp* other);



		Vector2D GetOffset() { return m_offset; }
		Vector2D GetSize() { return m_size; }
		UINT32 GetColliderID() { return m_colliderID; }
		
		void SetSize(Vector2D size) { m_size = size; }
		void SetOffset(Vector2D offset) { m_offset = offset; }


	private:
		static UINT COLLISION_ID_COUNT;

		UINT32 m_colliderID;
		Vector2D m_offset;
		Vector2D m_size;

	};

}