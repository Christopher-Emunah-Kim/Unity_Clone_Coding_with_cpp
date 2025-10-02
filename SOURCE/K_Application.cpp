#include "K_Application.h"
#include "K_Input.h"
#include "K_Time.h"
#include "../Editor_Window/framework.h"

namespace KHS
{
	Application::Application()
		:m_hwnd(nullptr), m_hdc(nullptr), m_backHdc(nullptr), m_backBuffer(nullptr)
	{
	}

	Application::~Application()
	{
		if (m_backBuffer != nullptr)
		{
			DeleteObject(m_backBuffer);
			m_backBuffer = nullptr;
		}

		if (m_backHdc != nullptr)
		{
			DeleteDC(m_backHdc);
			m_backHdc = nullptr;
		}

		if (m_hdc != nullptr)
		{
			ReleaseDC(m_hwnd, m_hdc);
			m_hdc = nullptr;
		}
	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		m_hwnd = hwnd;
		m_hdc = GetDC(m_hwnd); 

		//Double Buffering
		//클라이언트 영역 크기 조정
	    //윈도우 스타일 (최대화 버튼 제거 연산, 테두리 크기 변경 제거 비트 연산) 
	    //AdjustWindowRect함수 : 윈도우 스타일에 맞게 클라이언트 영역 크기를 조정
	    //myRect : 조정할 RECT 구조체 포인터
		RECT myRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT }; //클라이언트 영역 크기 설정
		AdjustWindowRectEx(&myRect, WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX & ~WS_THICKFRAME, FALSE, 0);

		m_backHdc = CreateCompatibleDC(m_hdc);
		m_backBuffer = CreateCompatibleBitmap(m_hdc, width, height);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(m_backHdc, m_backBuffer);
		DeleteObject(oldBitmap);


		m_player.SetPosition(0.0f, 0.0f);

		Input::Initialize();
		Time::Initialize();
	}

	void Application::Run()
	{
		if (Time::CanUpdate())
		{
			Update();
			LateUpdate();
			Render();
		}
	}

	void Application::Update()
	{
		Input::Update();

		m_player.Update();
	}

	void Application::LateUpdate()
	{
		//애플리케이션 레이트 업데이트 코드 작성
	}

	void Application::Render()
	{
		RECT rect;
		GetClientRect(m_hwnd, &rect);
		PatBlt(m_backHdc, 0, 0, rect.right, rect.bottom, WHITENESS);

		//Rendering Code
		Time::Render(m_backHdc);
		m_player.Render(m_backHdc);

		BitBlt(m_hdc, 0, 0, rect.right, rect.bottom, m_backHdc, 0, 0, SRCCOPY);
	}
}