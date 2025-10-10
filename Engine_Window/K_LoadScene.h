#pragma once
#include "../SOURCE/K_SceneManager.h"
#include "K_PlayScene.h"
#include "K_TitleScene.h"

namespace KHS
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		
		SceneManager::LoadScene(L"TitleScene");
	}
}