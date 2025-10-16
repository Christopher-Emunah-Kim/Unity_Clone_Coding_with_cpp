#include "K_PlayerScript.h"
#include "../SOURCE/K_Input.h"
#include "../SOURCE/K_Time.h"
#include "../SOURCE/K_TransformComp.h"
#include "../SOURCE/K_GameObject.h"
#include "../SOURCE/K_Component.h"
#include "../SOURCE/K_AnimatorComp.h"

namespace KHS
{
	PlayerScript::PlayerScript()
		:ScriptComp() , m_state(EPlayerState::SITDOWN) , m_animator(nullptr)
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
		case EPlayerState::SITDOWN:
		{
			PlayerSitDown();
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
		case EPlayerState::ATTACK:
		{
		}
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
		}

		if ( Input::GetKey(EKeyCode::A) )
		{
			pos.x -= speed;
		}

		if ( Input::GetKey(EKeyCode::W) )
		{
			pos.y -= speed;
		}

		if ( Input::GetKey(EKeyCode::S) )
		{
			pos.y += speed;
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
			m_state = EPlayerState::SITDOWN;
			m_animator->PlayAnmation(L"CatSitDown" , false);
		}
	}

	void PlayerScript::PlayerSitDown()
	{
		if ( Input::GetKey(EKeyCode::D) )
		{
			m_state = EPlayerState::WALK;
			m_animator->PlayAnmation(L"CatRightMove" , true);
		}

		if ( Input::GetKey(EKeyCode::A) )
		{
			m_state = EPlayerState::WALK;
			m_animator->PlayAnmation(L"CatLeftMove" , true);
		}

		if ( Input::GetKey(EKeyCode::W) )
		{
			m_state = EPlayerState::WALK;
			m_animator->PlayAnmation(L"CatFrontMove" , true);
		}

		if ( Input::GetKey(EKeyCode::S) )
		{
			m_state = EPlayerState::WALK;
			m_animator->PlayAnmation(L"CatBackMove" , true);
		}
	}
}