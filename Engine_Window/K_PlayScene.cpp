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
#include "K_CameraComp.h"
#include "K_MainCamera.h"

namespace KHS
{
	PlayScene::PlayScene()
		:m_player(nullptr)
	{
	}

    void PlayScene::Initialize()
    {
		//Main Camera
		InitializeMainCamera();

		//Resource Initialize before Object Instantiate
		InitializePlayer();
		InitializeBackground();

		//Intialize Layer and GameObject
		Scene::Initialize();
    }

	void PlayScene::InitializeMainCamera()
	{
		GameObject* camera = ObjectInstantiate::Instantiate<GameObject>(ELayerType::NONE, Vector2D(800.0f, 450.0f));
		CameraComp* cameraComp = camera->AddComponent<CameraComp>();
		mainCamera = cameraComp;
		cameraComp->SetResolution(Vector2D(1600.0f, 900.0f));
	}

	void PlayScene::InitializePlayer()
	{
		m_player = ObjectInstantiate::Instantiate<Player>(ELayerType::PLAYER);

		TransformComp* tr = m_player->GetComponent<TransformComp>();
		tr->SetPosition(Vector2D(WINDOW_WIDTH / 2.0f , WINDOW_HEIGHT / 2.0f));

		SpriteRendererComp* sr = m_player->AddComponent<SpriteRendererComp>();
		sr->SetSize(Vector2D(3.0f , 3.0f));

		m_player->AddComponent<PlayerScript>();

		Texture* playerTexture = ResourceTable::Find<Texture>(L"PackMan");
		sr->SetTexture(playerTexture);
	}

	void PlayScene::InitializeBackground()
	{
		GameObject* background = ObjectInstantiate::Instantiate<GameObject>(ELayerType::BACKGROUND);

		TransformComp* tr = background->GetComponent<TransformComp>();
		tr->SetPosition(Vector2D(0.0f, 0.0f));

		SpriteRendererComp* bgSr = background->AddComponent<SpriteRendererComp>();
		bgSr->SetSize(Vector2D(2.0f , 2.0f));

		Texture* bgTexture = ResourceTable::Find<Texture>(L"Map");
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
		TransformComp* tr = m_player->GetComponent<TransformComp>();
		tr->SetPosition(Vector2D(WINDOW_WIDTH/2.0f , WINDOW_HEIGHT/2.0f));
	}
	void PlayScene::OnExit()
	{
		Scene::OnExit();

		TransformComp* tr = m_player->GetComponent<TransformComp>();
		tr->SetPosition(Vector2D(WINDOW_WIDTH / 2.0f , WINDOW_HEIGHT / 2.0f));
	}
}