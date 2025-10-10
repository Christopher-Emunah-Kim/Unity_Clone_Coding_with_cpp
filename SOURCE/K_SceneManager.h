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
			scene->Initialize();

			m_scenes.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name);

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		static std::map<const std::wstring, Scene*> m_scenes;
		static Scene* m_activeScene;
	};

}

