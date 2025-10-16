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

		void MyAdjustWindowRect(HWND hwnd, UINT width, UINT height);
		void CreateBuffer(UINT width, UINT height);
		void InitializeSubsystems();
		void ClearBuffer(RECT& rc);
		void CopyBuffer(RECT& rc);

	public:
		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

		inline HDC GetHdc() { return m_hdc; }
		inline HWND GetHwnd() { return m_hwnd; }
		inline UINT GetWidth() { return WINDOW_WIDTH; }
		inline UINT GetHeight() { return WINDOW_HEIGHT; }

	private:
		HWND m_hwnd;
		HDC m_hdc; 

		HDC m_backHdc;
		HBITMAP m_backBuffer;
	};
}

