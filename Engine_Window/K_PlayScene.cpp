#include "K_PlayScene.h"

namespace KHS
{
    void PlayScene::Initialize()
    {
		GameObject* obj = new GameObject();
		AddGameObject(obj);
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