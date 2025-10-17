#include "K_EnemyScript.h"
#include "../SOURCE/K_Input.h"
#include "../SOURCE/K_Time.h"
#include "../SOURCE/K_TransformComp.h"
#include "../SOURCE/K_GameObject.h"
#include "../SOURCE/K_Component.h"
#include "../SOURCE/K_AnimatorComp.h"
#include "../SOURCE/K_ObjectManager.h"

namespace KHS
{
	EnemyScript::EnemyScript()
		:ScriptComp() , m_state(EEnemyState::SITDOWN), m_dir(EEnemyDir::END), 
		m_animator(nullptr) , m_time(0.0f) , m_deathTime(0.0f)
	{
	}

	EnemyScript::~EnemyScript()
	{
	}

	void EnemyScript::Initialize()
	{
		ScriptComp::Initialize();
	}

	void EnemyScript::Update()
	{
		ScriptComp::Update();

		m_deathTime += Time::GetDeltaTime();
		if ( m_deathTime > 6.0f )
		{
			ObjectManager::Destroy(GetOwner());
			return;
		}

		if ( m_animator == nullptr )
		{
			m_animator = GetOwner()->GetComponent<AnimatorComp>();
		}

		switch ( m_state )
		{
		case EEnemyState::SITDOWN:
		{
			EnemySitDown();
		}
		break;
		case EEnemyState::WALK:
		{
			EnemyMove();
		}
		break;
		case EEnemyState::SLEEP:
		{
		}
		break;
		case EEnemyState::ATTACK:
		{
		}
		break;
		}

	}

	void EnemyScript::LateUpdate()
	{
		ScriptComp::LateUpdate();
	}

	void EnemyScript::Render(HDC hdc)
	{
		ScriptComp::Render(hdc);
	}


	void EnemyScript::EnemyMove()
	{
		TransformComp* tr = GetOwner()->GetComponent<TransformComp>();
		
		MoveByDir(tr);

		if ( m_time > 2.0f )
		{
			int isSleep = rand() % 2;
			if ( isSleep == 1 )
			{
				m_state = EEnemyState::SLEEP;
				m_animator->PlayAnimation(L"CatSleep" , false);
				m_time = 0.0f;
			}
			else
			{
				m_state = EEnemyState::SITDOWN;
				m_animator->PlayAnimation(L"CatSitDown" , true);
				m_time = 0.0f;
			}
		}
	}

	void EnemyScript::MoveByDir(TransformComp* tr)
	{
		Vector2D pos = tr->GetPosition();
		Vector2D scale = tr->GetScale();

		float deltaTime = Time::GetDeltaTime();
		float speed = 100.0f * deltaTime;

		m_time += deltaTime;

		switch ( m_dir )
		{
		case EEnemyDir::RIGHT:
		{
			pos.x += speed;
		}
		break;
		case EEnemyDir::LEFT:
		{
			pos.x -= speed;
		}
		break;
		case EEnemyDir::UP:
		{
			pos.y -= speed;
		}
		break;
		case EEnemyDir::DOWN:
		{
			pos.y += speed;
		}
		break;

		default:
		{
			assert(false);
		}
		break;
		}

		float spriteSize = 32.0f;
		float halfWidth = ( spriteSize * scale.x ) * 0.5f;
		float halfHeight = ( spriteSize * scale.y ) * 0.5f;

		if ( pos.x - halfWidth < 0.0f )
			pos.x = halfWidth;
		if ( pos.x + halfWidth > WINDOW_WIDTH )
			pos.x = WINDOW_WIDTH - halfWidth;
		if ( pos.y - halfHeight < 0.0f )
			pos.y = halfHeight;
		if ( pos.y + halfHeight > WINDOW_HEIGHT )
			pos.y = WINDOW_HEIGHT - halfHeight;

		tr->SetPosition(pos);
	}

	void EnemyScript::EnemySitDown()
	{
		m_time += Time::GetDeltaTime();

		if(m_time > 2.0f)
		{
			m_state = EEnemyState::WALK;

			int dir = rand() % 4;
			m_dir = static_cast< EEnemyDir >( dir );

			PlayAnimByDir(m_dir);

			m_time = 0.0f;
		}
	}

	void EnemyScript::PlayAnimByDir(EEnemyDir dir)
	{
		switch ( dir )
		{
		case EEnemyDir::RIGHT:
		{
			m_state = EEnemyState::WALK;
			m_animator->PlayAnimation(L"CatRightMove" , true);
		}
		break;
		case EEnemyDir::LEFT:
		{
			m_state = EEnemyState::WALK;
			m_animator->PlayAnimation(L"CatLeftMove" , true);
		}
		break;
		case EEnemyDir::UP:
		{
			m_state = EEnemyState::WALK;
			m_animator->PlayAnimation(L"CatFrontMove" , true);
		}
		break;
		case EEnemyDir::DOWN:
		{
			m_state = EEnemyState::WALK;
			m_animator->PlayAnimation(L"CatBackMove" , true);
		}
		break;

		default:
		{
			assert(false);
		}
		break;
		}
	}

}