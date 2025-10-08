#pragma once
#include "../SOURCE/K_SceneManager.h"
#include "K_PlayScene.h"

namespace KHS
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::LoadScene(L"PlayScene");
		//SceneManager::CreateScene<TitleScene>(L"TitleScene");
	}
}