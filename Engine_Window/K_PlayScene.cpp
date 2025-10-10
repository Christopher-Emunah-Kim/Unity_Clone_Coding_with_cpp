#include "K_PlayScene.h"
#include "K_Player.h"
#include "K_TransformComp.h"
#include "K_SpriteRendererComp.h"

namespace KHS
{
    void PlayScene::Initialize()
    {
		{
			Player* bg = new Player();
			TransformComp* tr
				= bg->AddComponent<TransformComp>();
			tr->SetPosition(Vector2D(0,0));

			tr->SetName(L"TR");

			SpriteRendererComp* sr
				= bg->AddComponent<SpriteRendererComp>();
			sr->SetName(L"SR");
			sr->ImageLoad(L"CloudOcean");

			AddGameObject(bg);
		}
    }

    void PlayScene::Update()
    {
		Scene::Update();
    }

    void PlayScene::LateUpdate()
    {
		Scene::LateUpdate();
    }

    void PlayScene::Render(HDC hdc)
    {
		Scene::Render(hdc);
    }
}