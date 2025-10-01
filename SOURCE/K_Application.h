#pragma once
#include "CommonInclude.h"
#include "K_GameObject.h"

namespace KHS
{
	class Application
	{
	public:
		Application();
		~Application();

	private:
		void Update();
		void LateUpdate();
		void Render();

	public:
		void Initialize(HWND hwnd);
		void Run();

	private:
		HWND m_hwnd = nullptr;
		HDC m_hdc = nullptr; 
		
		GameObject m_player;
	};
}

