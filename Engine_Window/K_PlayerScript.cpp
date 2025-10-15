#include "K_PlayerScript.h"
#include "../SOURCE/K_Input.h"
#include "../SOURCE/K_Time.h"
#include "../SOURCE/K_TransformComp.h"
#include "../SOURCE/K_GameObject.h"
#include "../SOURCE/K_Component.h"

namespace KHS
{
	PlayerScript::PlayerScript()
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

		UpdatePlayerPosition();
	}

	void PlayerScript::LateUpdate()
	{
		ScriptComp::LateUpdate();
	}

	void PlayerScript::Render(HDC hdc)
	{
		ScriptComp::Render(hdc);
	}

	void PlayerScript::UpdatePlayerPosition()
	{

		if ( Input::GetKey(EKeyCode::D) )
		{
			TransformComp* tr = GetOwner()->GetComponent<TransformComp>();
			Vector2D pos = tr->GetPosition();
			pos.x += 100.0f * Time::GetDeltaTime();

			tr->SetPosition(pos);
		}

		if ( Input::GetKey(EKeyCode::A) )
		{
			TransformComp* tr = GetOwner()->GetComponent<TransformComp>();
			Vector2D pos = tr->GetPosition();
			pos.x -= 100.0f * Time::GetDeltaTime();

			tr->SetPosition(pos);
		}

		if ( Input::GetKey(EKeyCode::W) )
		{
			TransformComp* tr = GetOwner()->GetComponent<TransformComp>();
			Vector2D pos = tr->GetPosition();
			pos.y -= 100.0f * Time::GetDeltaTime();

			tr->SetPosition(pos);
		}

		if ( Input::GetKey(EKeyCode::S) )
		{
			TransformComp* tr = GetOwner()->GetComponent<TransformComp>();
			Vector2D pos = tr->GetPosition();
			pos.y += 100.0f * Time::GetDeltaTime();

			tr->SetPosition(pos);
		}
	}

}