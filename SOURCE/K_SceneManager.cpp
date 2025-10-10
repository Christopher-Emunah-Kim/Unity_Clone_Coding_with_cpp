#include "K_SceneManager.h"

namespace KHS
{
	std::map<const std::wstring, Scene*> SceneManager::m_scenes{};
	Scene* SceneManager::m_activeScene = nullptr;
	
	void SceneManager::Initialize()
	{
	}
	void SceneManager::Update()
	{
		m_activeScene->Update();
	}
	void SceneManager::LateUpdate()
	{
		m_activeScene->LateUpdate();
	}
	void SceneManager::Render(HDC hdc)
	{
		m_activeScene->Render(hdc);
	}

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		std::map<std::wstring, Scene*>::iterator findIter = m_scenes.find(name);

		if (findIter == m_scenes.end())
		{
			return nullptr;

		}

		m_activeScene = findIter->second;

		return m_activeScene;
	}


}