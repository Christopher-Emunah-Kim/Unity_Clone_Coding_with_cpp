#pragma once
#include "../SOURCE/K_ScriptComp.h"

namespace KHS
{
	class AnimatorComp;
	class PlayerScript : public ScriptComp
	{
	public:
		enum class EPlayerState
		{
			IDLE,
			WALK,
			SLEEP,
			GIVEWATER,
			ATTACK,
			DIE,
			END
		};

		PlayerScript();
		virtual ~PlayerScript();

	private:
		void PlayerIdle();
		void PlayerMove();
		void PlayerGiveWater();

	public:
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(class ColliderComp* other) override;
		virtual void OnCollisionStay(class ColliderComp* other) override;
		virtual void OnCollisionExit(class ColliderComp* other) override;

		void AttackEffect();

	private:
		EPlayerState m_state;
		AnimatorComp* m_animator;
	};
}


