#include "K_PlayScene.h"
#include "K_Player.h"
#include "K_TransformComp.h"
#include "K_SpriteRendererComp.h"

namespace KHS
{
    void PlayScene::Initialize()
    {
		/*GameObject* obj = new GameObject();
		AddGameObject(obj);*/
		{
			Player* pl = new Player();
			TransformComp* tr
				= pl->AddComponent<TransformComp>();
			tr->SetPosition(800, 450);

			tr->SetName(L"TR");

			SpriteRendererComp* sr
				= pl->AddComponent<SpriteRendererComp>();
			sr->SetName(L"SR");

			AddGameObject(pl);
		}

		{
			Player* pl = new Player();
			TransformComp* tr
				= pl->AddComponent<TransformComp>();
			tr->SetPosition(100, 650);

			tr->SetName(L"TR");

			SpriteRendererComp* sr
				= pl->AddComponent<SpriteRendererComp>();
			sr->SetName(L"SR");

			AddGameObject(pl);
		}

		{
			Player* pl = new Player();
			TransformComp* tr
				= pl->AddComponent<TransformComp>();
			tr->SetPosition(300, 450);

			tr->SetName(L"TR");

			SpriteRendererComp* sr
				= pl->AddComponent<SpriteRendererComp>();
			sr->SetName(L"SR");

			AddGameObject(pl);
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