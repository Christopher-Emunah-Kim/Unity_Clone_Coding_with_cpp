#pragma once
#include "K_Scene.h"

namespace KHS
{

	class SceneManager
	{
	public:
		template <typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			m_activeScene = scene;

			scene->Initialize();
			m_scenes.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name);
		static Scene* GetActiveScene();

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void Destroy();
		static void Release();

	private:
		static std::map<const std::wstring, Scene*> m_scenes;
		static Scene* m_activeScene;
	};

}

