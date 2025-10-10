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
		if (m_activeScene != nullptr)
		{
			m_activeScene->OnExit();
		}

		std::map<std::wstring, Scene*>::iterator findIter = m_scenes.find(name);

		if (findIter == m_scenes.end())
		{
			return nullptr;
		}

		m_activeScene = findIter->second;
		m_activeScene->OnEnter();

		return m_activeScene;
	}

	Scene* SceneManager::GetActiveScene()
	{
		return m_activeScene;
	}
}