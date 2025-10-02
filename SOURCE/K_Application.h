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
		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

	private:
		HWND m_hwnd;
		HDC m_hdc; 

		HDC m_backHdc;
		HBITMAP m_backBuffer;
		
		GameObject m_player;
	};
}

