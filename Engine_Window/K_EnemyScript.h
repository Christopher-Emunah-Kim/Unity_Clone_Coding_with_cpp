#pragma once
#include "../SOURCE/K_ScriptComp.h"

namespace KHS
{
	class AnimatorComp;
	class TransformComp;

	class EnemyScript : public ScriptComp
	{
	public:
		enum class EEnemyState
		{
			IDLE ,
			SITDOWN ,
			WALK ,
			SLEEP ,
			ATTACK ,
			DIE ,
			END
		};

		enum class EEnemyDir
		{
			LEFT,
			RIGHT,
			UP,
			DOWN,
			END
		};

	public:
		EnemyScript();
		virtual ~EnemyScript();

	private:
		void EnemyMove();
		void EnemySitDown();
		void PlayAnimByDir(EEnemyDir dir);
		void MoveByDir(TransformComp* tr);

	public:
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

	private:
		EEnemyState m_state;
		EEnemyDir m_dir;
		AnimatorComp* m_animator;
		float m_time;
	};
}


