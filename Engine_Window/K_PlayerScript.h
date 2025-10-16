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
			SITDOWN,
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
		void PlayerMove();
		void PlayerSitDown();

	public:
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

	private:
		EPlayerState m_state;
		AnimatorComp* m_animator;
	};
}


