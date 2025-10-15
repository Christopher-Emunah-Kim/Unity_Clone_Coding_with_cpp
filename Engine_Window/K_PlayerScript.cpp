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

		if ( Input::GetKey(EKeyCode::D) )
		{
			pos.x += 100.0f * Time::GetDeltaTime();
			tr->SetPosition(pos);
		}

		if ( Input::GetKey(EKeyCode::A) )
		{
			pos.x -= 100.0f * Time::GetDeltaTime();
			tr->SetPosition(pos);
		}

		if ( Input::GetKey(EKeyCode::W) )
		{
			pos.y -= 100.0f * Time::GetDeltaTime();
			tr->SetPosition(pos);
		}

		if ( Input::GetKey(EKeyCode::S) )
		{
			pos.y += 100.0f * Time::GetDeltaTime();
			tr->SetPosition(pos);
		}

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