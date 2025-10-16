#include "K_Application.h"
#include "K_Input.h"
#include "K_Time.h"
#include "K_SceneManager.h"
#include "K_ResourceTable.h"
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
		MyAdjustWindowRect(hwnd, width, height);
		CreateBuffer(width, height);
		InitializeSubsystems();
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

		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();
	}

	void Application::Render() //Double Buffering
	{
		RECT rect;
		ClearBuffer(rect);

		//Rendering Code
		Time::Render(m_backHdc);
		SceneManager::Render(m_backHdc);

		CopyBuffer(rect);
	}

	void Application::Release()
	{
		SceneManager::Release();
		ResourceTable::Release();
	}

	void Application::MyAdjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		m_hwnd = hwnd;
		m_hdc = GetDC(m_hwnd);

		//AdjustWindowRect함수 : 윈도우 스타일에 맞게 클라이언트 영역 크기를 조정
		//myRect : 조정할 RECT 구조체 포인터
		RECT myRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT }; //클라이언트 영역 크기 설정
		AdjustWindowRectEx(&myRect, WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX & ~WS_THICKFRAME, FALSE, 0); 
		//클라이언트 영역 크기 조정 -> 윈도우 스타일 (최대화 버튼 제거 연산, 테두리 크기 변경 제거 비트 연산) 
	}

	void Application::CreateBuffer(UINT width, UINT height)
	{
		m_backHdc = CreateCompatibleDC(m_hdc);
		m_backBuffer = CreateCompatibleBitmap(m_hdc, width, height);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(m_backHdc, m_backBuffer);
		DeleteObject(oldBitmap);
	}

	void Application::InitializeSubsystems()
	{
		Input::Initialize();
		Time::Initialize();
		SceneManager::Initialize();
	}

	void Application::ClearBuffer(RECT& rc)
	{
		GetClientRect(m_hwnd, &rc);
		PatBlt(m_backHdc, -1, -1, rc.right +1, rc.bottom +1, WHITENESS);
	}

	void Application::CopyBuffer(RECT& rc)
	{
		//BackBuffer -> FrontBuffer
		BitBlt(m_hdc, 0, 0, rc.right, rc.bottom, m_backHdc, 0, 0, SRCCOPY);
	}
}