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

	void SceneManager::Destroy()
	{
		if (m_activeScene != nullptr)
		{
			m_activeScene->Destroy();
		}
	}

	void SceneManager::Release()
	{
		for (auto& pair : m_scenes)
		{
			delete pair.second;
			pair.second = nullptr;
		}
		m_scenes.clear();
		m_activeScene = nullptr;
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