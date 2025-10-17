#include "K_PlayScene.h"
#include "K_Player.h"
#include "K_TransformComp.h"
#include "K_SpriteRendererComp.h"
#include "K_Input.h"
#include "K_TitleScene.h"
#include "K_SceneManager.h"
#include "K_ObjectManager.h"
#include "K_ResourceTable.h"
#include "K_PlayerScript.h"
#include "K_CameraComp.h"
#include "K_MainCamera.h"
#include "K_AnimatorComp.h"
#include "K_Enemy.h"
#include "K_EnemyScript.h"

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
		InitializeEnemy();
		InitializeBackground();

		//Intialize Layer and GameObject
		Scene::Initialize();
    }

	void PlayScene::InitializeMainCamera()
	{
		GameObject* camera = ObjectManager::Instantiate<GameObject>(ELayerType::PARTICLE, 
			Vector2D(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT/2.0f));

		CameraComp* cameraComp = camera->AddComponent<CameraComp>();
		mainCamera = cameraComp;
		cameraComp->SetResolution(Vector2D(static_cast<float>(WINDOW_WIDTH),static_cast<float>( WINDOW_HEIGHT )));
	}

	void PlayScene::InitializePlayer()
	{
		m_player = ObjectManager::Instantiate<Player>(ELayerType::PLAYER);

		mainCamera->SetTarget(m_player);

		TransformComp* tr = m_player->GetComponent<TransformComp>();

		PlayerScript* playerScript = m_player->AddComponent<PlayerScript>();

		Texture* playerTexture = ResourceTable::Find<Texture>(L"Player");

		AnimatorComp* animator = m_player->AddComponent<AnimatorComp>();
		animator->CreateAnimation(L"Idle" , playerTexture ,
			Vector2D(2000.0f , 250.0f) , Vector2D(250.0f , 250.0f) , Vector2D(0.0f , 0.0f) , 1 , 0.1f);
		animator->CreateAnimation(L"FrontGiveWater" , playerTexture ,
			Vector2D(0.0f , 2000.0f) , Vector2D(250.0f , 250.0f) , Vector2D(0.0f , 0.0f) , 12 , 0.1f);
		animator->CreateAnimation(L"RightWalk", playerTexture,
			Vector2D(0.0f , 0.0f) , Vector2D(250.0f , 250.0f) , Vector2D(0.0f , 0.0f) , 6 , 0.1f);
		animator->CreateAnimation(L"LeftWalk", playerTexture,
			Vector2D(1500.0f , 0.0f) , Vector2D(250.0f , 250.0f) , Vector2D(0.0f , 0.0f) , 6 , 0.1f);
		animator->CreateAnimation(L"BackWalk", playerTexture,
			Vector2D(0.0f , 250.0f) , Vector2D(250.0f , 250.0f) , Vector2D(0.0f , 0.0f) , 6 , 0.1f);
		animator->CreateAnimation(L"FrontWalk", playerTexture,
			Vector2D(0.0f , 500.0f) , Vector2D(250.0f , 250.0f) , Vector2D(0.0f , 0.0f) , 3 , 0.1f);


		animator->PlayAnimation(L"Idle" , false);
		animator->GetCompleteEvent(L"FrontGiveWater")
			= std::bind(&PlayerScript::AttackEffect , playerScript);

		tr->SetPosition(Vector2D(100.0f , 100.0f));
		tr->SetScale(Vector2D(1.0f , 1.0f));
	}

	void PlayScene::InitializeEnemy()
	{
		Enemy* enemy = ObjectManager::Instantiate<Enemy>(ELayerType::ENEMY);
		enemy->AddComponent<EnemyScript>();

		TransformComp* enemyTr = enemy->GetComponent<TransformComp>();
		enemyTr->SetPosition(Vector2D(200.0f, 200.0f));
		enemyTr->SetScale(Vector2D(3.0f , 3.0f));


		Texture* enemyTexture = ResourceTable::Find<Texture>(L"Cat");

		AnimatorComp* enemyAnimator = enemy->AddComponent<AnimatorComp>();

		enemyAnimator->CreateAnimation(L"CatBackMove" , enemyTexture ,
			Vector2D(0.0f , 0.0f) , Vector2D(32.0f , 32.0f) , Vector2D(0.0f , 0.0f) , 4 , 0.5f);
		enemyAnimator->CreateAnimation(L"CatRightMove" , enemyTexture ,
			Vector2D(0.0f , 32.0f) , Vector2D(32.0f , 32.0f) , Vector2D(0.0f , 0.0f) , 4 , 0.5f);
		enemyAnimator->CreateAnimation(L"CatFrontMove" , enemyTexture ,
			Vector2D(0.0f , 64.0f) , Vector2D(32.0f , 32.0f) , Vector2D(0.0f , 0.0f) , 4 , 0.5f);
		enemyAnimator->CreateAnimation(L"CatLeftMove" , enemyTexture ,
			Vector2D(0.0f , 96.0f) , Vector2D(32.0f , 32.0f) , Vector2D(0.0f , 0.0f) , 4 , 0.5f);
		enemyAnimator->CreateAnimation(L"CatSitDown" , enemyTexture ,
			Vector2D(0.0f , 128.0f) , Vector2D(32.0f , 32.0f) , Vector2D(0.0f , 0.0f) , 4 , 0.5f);
		enemyAnimator->CreateAnimation(L"CatGrooming" , enemyTexture ,
			Vector2D(0.0f , 160.0f) , Vector2D(32.0f , 32.0f) , Vector2D(0.0f , 0.0f) , 4 , 0.5f);
		enemyAnimator->CreateAnimation(L"CatSleep" , enemyTexture ,
			Vector2D(0.0f , 192.0f) , Vector2D(32.0f , 32.0f) , Vector2D(0.0f , 0.0f) , 4 , 0.5f);

		enemyAnimator->PlayAnimation(L"CatSitDown" , true);
	}

	void PlayScene::InitializeBackground()
	{
		GameObject* background = ObjectManager::Instantiate<GameObject>(ELayerType::BACKGROUND);

		TransformComp* tr = background->GetComponent<TransformComp>();
		tr->SetPosition(Vector2D(0.0f, 0.0f));

		SpriteRendererComp* bgSr = background->AddComponent<SpriteRendererComp>();
		bgSr->SetSize(Vector2D(1.0f , 1.0f));

		Texture* bgTexture = ResourceTable::Find<Texture>(L"CloudOcean");
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