#include "K_PlayScene.h"
#include "K_Player.h"
#include "K_TransformComp.h"
#include "K_SpriteRendererComp.h"
#include "K_Input.h"
#include "K_TitleScene.h"
#include "K_SceneManager.h"

namespace KHS
{
	PlayScene::PlayScene()
		:m_background(nullptr)
	{
	}

    void PlayScene::Initialize()
    {
		{
			m_background = new Player();
			TransformComp* tr = m_background->AddComponent<TransformComp>();
			tr->SetPosition(Vector2D(0,0));
			tr->SetName(L"TR");

			SpriteRendererComp* sr = m_background->AddComponent<SpriteRendererComp>();
			sr->SetName(L"SR");
			sr->ImageLoad(L"CloudOcean");

			AddGameObject(m_background, ELayerType::BACKGROUND);
		}
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

		std::wstring str = L"Play Scene";
		TextOut(hdc, 10, 30, str.c_str(), static_cast<int>(str.size()));
    }
	void PlayScene::OnEnter()
	{
		Scene::OnEnter();
	}
	void PlayScene::OnExit()
	{
		Scene::OnExit();

		TransformComp* tr = m_background->GetComponent<TransformComp>();
		tr->SetPosition(Vector2D(0, 0));
	}
}