#pragma once
#include "CommonInclude.h"

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

		float m_speed;
		float m_x;
		float m_y;
	};
}

