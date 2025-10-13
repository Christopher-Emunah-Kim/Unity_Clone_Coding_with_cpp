#include "K_PlayScene.h"
#include "K_Player.h"
#include "K_TransformComp.h"
#include "K_SpriteRendererComp.h"
#include "K_Input.h"
#include "K_TitleScene.h"
#include "K_SceneManager.h"
#include "K_ObjectInstantiate.h"
#include "K_ResourceTable.h"

namespace KHS
{
	PlayScene::PlayScene()
		:m_background(nullptr)
	{
	}

    void PlayScene::Initialize()
    {
		//Resource Initialize before Object Instantiate
		m_background = ObjectInstantiate::Instantiate<Player>(ELayerType::BACKGROUND);

		SpriteRendererComp* sr = m_background->AddComponent<SpriteRendererComp>();
		Texture* bgTexture = ResourceTable::Find<Texture>(L"BG");
		sr->SetTexture(bgTexture);

		//Intialize Layer and GameObject
		Scene::Initialize();
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