#include "K_PlayerScript.h"
#include "K_Enemy.h"
#include "K_EnemyScript.h"
#include "../SOURCE/K_Input.h"
#include "../SOURCE/K_Time.h"
#include "../SOURCE/K_TransformComp.h"
#include "../SOURCE/K_GameObject.h"
#include "../SOURCE/K_Component.h"
#include "../SOURCE/K_AnimatorComp.h"
#include "../SOURCE/K_ObjectManager.h"
#include "../SOURCE/K_ResourceTable.h"

namespace KHS
{
	PlayerScript::PlayerScript()
		:ScriptComp() , m_state(EPlayerState::IDLE) , m_animator(nullptr)
	{
	}

	PlayerScript::~PlayerScript()
	{
	}

	void PlayerScript::Initialize()
	{
		ScriptComp::Initialize();
	}

	void PlayerScript::Update()
	{
		ScriptComp::Update();

		if ( m_animator == nullptr )
		{
			m_animator = GetOwner()->GetComponent<AnimatorComp>();
		}

		switch ( m_state )
		{
		case EPlayerState::IDLE:
		{
			PlayerIdle();
		}
		break;
		case EPlayerState::WALK:
		{
			PlayerMove();
		}
		break;
		case EPlayerState::SLEEP:
		{
		}
		break;
		case EPlayerState::GIVEWATER:
		{
			PlayerGiveWater();
		}
		break;
		case EPlayerState::ATTACK:
		{
		}
		break;

		default:
			assert(false);
			break;
		}
	}

	void PlayerScript::LateUpdate()
	{
		ScriptComp::LateUpdate();
	}

	void PlayerScript::Render(HDC hdc)
	{
		ScriptComp::Render(hdc);
	}

	void PlayerScript::AttackEffect()
	{
		Enemy* enemy = ObjectManager::Instantiate<Enemy>(ELayerType::ENEMY);
		enemy->AddComponent<EnemyScript>();

		TransformComp* enemyTr = enemy->GetComponent<TransformComp>();
		enemyTr->SetPosition(Vector2D(200.0f, 200.0f));
		enemyTr->SetScale(Vector2D(3.0f, 3.0f));

		Texture* enemyTexture = ResourceTable::Find<Texture>(L"Cat");

		AnimatorComp* enemyAnimator = enemy->AddComponent<AnimatorComp>();

		enemyAnimator->CreateAnimation(L"CatBackMove", enemyTexture,
			Vector2D(0.0f, 0.0f), Vector2D(32.0f, 32.0f), Vector2D(0.0f, 0.0f), 4, 0.5f);
		enemyAnimator->CreateAnimation(L"CatRightMove", enemyTexture,
			Vector2D(0.0f, 32.0f), Vector2D(32.0f, 32.0f), Vector2D(0.0f, 0.0f), 4, 0.5f);
		enemyAnimator->CreateAnimation(L"CatFrontMove", enemyTexture,
			Vector2D(0.0f, 64.0f), Vector2D(32.0f, 32.0f), Vector2D(0.0f, 0.0f), 4, 0.5f);
		enemyAnimator->CreateAnimation(L"CatLeftMove", enemyTexture,
			Vector2D(0.0f, 96.0f), Vector2D(32.0f, 32.0f), Vector2D(0.0f, 0.0f), 4, 0.5f);
		enemyAnimator->CreateAnimation(L"CatSitDown", enemyTexture,
			Vector2D(0.0f, 128.0f), Vector2D(32.0f, 32.0f), Vector2D(0.0f, 0.0f), 4, 0.5f);
		enemyAnimator->CreateAnimation(L"CatGrooming", enemyTexture,
			Vector2D(0.0f, 160.0f), Vector2D(32.0f, 32.0f), Vector2D(0.0f, 0.0f), 4, 0.5f);
		enemyAnimator->CreateAnimation(L"CatSleep", enemyTexture,
			Vector2D(0.0f, 192.0f), Vector2D(32.0f, 32.0f), Vector2D(0.0f, 0.0f), 4, 0.5f);

		enemyAnimator->PlayAnimation(L"CatSitDown", true);
	}


	void PlayerScript::PlayerMove()
	{
		TransformComp* tr = GetOwner()->GetComponent<TransformComp>();
		Vector2D pos = tr->GetPosition();
		Vector2D scale = tr->GetScale();

		float deltaTime = Time::GetDeltaTime();
		float speed = 100.0f * deltaTime;

		if ( Input::GetKey(EKeyCode::D) )
		{
			pos.x += speed;
			m_animator->PlayAnimation(L"RightWalk" , true);
		}

		if ( Input::GetKey(EKeyCode::A) )
		{
			pos.x -= speed;
			m_animator->PlayAnimation(L"LeftWalk" , true);
		}

		if ( Input::GetKey(EKeyCode::W) )
		{
			pos.y -= speed;
			m_animator->PlayAnimation(L"BackWalk" , true);
		}

		if ( Input::GetKey(EKeyCode::S) )
		{
			pos.y += speed;
			m_animator->PlayAnimation(L"FrontWalk" , true);
		}

		float spriteSize = 32.0f;
		float halfWidth = ( spriteSize * scale.x ) * 0.5f;
		float halfHeight = ( spriteSize * scale.y ) * 0.5f;

		// 화면 경계 체크
		if ( pos.x - halfWidth < 0.0f )
			pos.x = halfWidth;
		if ( pos.x + halfWidth > WINDOW_WIDTH )
			pos.x = WINDOW_WIDTH - halfWidth;
		if ( pos.y - halfHeight < 0.0f )
			pos.y = halfHeight;
		if ( pos.y + halfHeight > WINDOW_HEIGHT )
			pos.y = WINDOW_HEIGHT - halfHeight;


		tr->SetPosition(pos);

		if ( Input::GetKeyUp(EKeyCode::D) || Input::GetKeyUp(EKeyCode::A) ||
			Input::GetKeyUp(EKeyCode::W) || Input::GetKeyUp(EKeyCode::S) )
		{
			m_state = EPlayerState::IDLE;
			m_animator->PlayAnimation(L"Idle" , false);
		}
	}

	void PlayerScript::PlayerIdle()
	{
		if ( Input::GetKey(EKeyCode::LButton) )
		{
			m_state = EPlayerState::GIVEWATER;
			m_animator->PlayAnimation(L"FrontGiveWater" , false);
			Vector2D mousePos = Input::GetMousePosition();
		}

		if ( Input::GetKeyDown(EKeyCode::D) || Input::GetKeyDown(EKeyCode::A) ||
			Input::GetKeyDown(EKeyCode::W) || Input::GetKeyDown(EKeyCode::S) )
		{
			m_state = EPlayerState::WALK;
		}
	}

	void PlayerScript::PlayerGiveWater()
	{
		if ( m_animator->IsComplete() == true )
		{
			m_state = EPlayerState::IDLE;
			m_animator->PlayAnimation(L"Idle" , false);
		}
	}
}