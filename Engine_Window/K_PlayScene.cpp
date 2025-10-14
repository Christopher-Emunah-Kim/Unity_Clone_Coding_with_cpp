#include "K_PlayScene.h"
#include "K_Player.h"
#include "K_TransformComp.h"
#include "K_SpriteRendererComp.h"
#include "K_Input.h"
#include "K_TitleScene.h"
#include "K_SceneManager.h"
#include "K_ObjectInstantiate.h"
#include "K_ResourceTable.h"
#include "K_PlayerScript.h"

namespace KHS
{
	PlayScene::PlayScene()
		:m_player(nullptr)
	{
	}

    void PlayScene::Initialize()
    {
		//Resource Initialize before Object Instantiate
		m_player = ObjectInstantiate::Instantiate<Player>(ELayerType::PLAYER);

		SpriteRendererComp* sr = m_player->AddComponent<SpriteRendererComp>();
		sr->SetSize(Vector2D(5.0f , 5.0f));

		m_player->AddComponent<PlayerScript>();

		Texture* playerTexture = ResourceTable::Find<Texture>(L"PackMan_R1");
		sr->SetTexture(playerTexture);

		InitializeBackground();

		//Intialize Layer and GameObject
		Scene::Initialize();
    }

	void PlayScene::InitializeBackground()
	{
		GameObject* background = ObjectInstantiate::Instantiate<GameObject>(ELayerType::BACKGROUND);
		SpriteRendererComp* bgSr = background->AddComponent<SpriteRendererComp>();
		bgSr->SetSize(Vector2D(800.0f , 600.0f));

		Texture* bgTexture = ResourceTable::Find<Texture>(L"Background");
		bgSr->SetTexture(bgTexture);
	}

    void PlayScene::Update()
    {
		Scene::Update();
    }

    void PlayScene::LateUpdate()
    {
		Scene::LateUpdate();

		if (Input::GetKeyDown(EKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
    }

    void PlayScene::Render(HDC hdc)
    {
		Scene::Render(hdc);

		/*std::wstring str = L"Play Scene";
		TextOut(hdc, 10, 30, str.c_str(), static_cast<int>(str.size()));*/
    }
	void PlayScene::OnEnter()
	{
		Scene::OnEnter();
	}
	void PlayScene::OnExit()
	{
		Scene::OnExit();

		TransformComp* tr = m_player->GetComponent<TransformComp>();
		tr->SetPosition(Vector2D(0, 0));
	}
}