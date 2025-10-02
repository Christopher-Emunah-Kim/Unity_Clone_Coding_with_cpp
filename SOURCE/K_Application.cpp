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
		//Ŭ���̾�Ʈ ���� ũ�� ����
	    //������ ��Ÿ�� (�ִ�ȭ ��ư ���� ����, �׵θ� ũ�� ���� ���� ��Ʈ ����) 
	    //AdjustWindowRect�Լ� : ������ ��Ÿ�Ͽ� �°� Ŭ���̾�Ʈ ���� ũ�⸦ ����
	    //myRect : ������ RECT ����ü ������
		RECT myRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT }; //Ŭ���̾�Ʈ ���� ũ�� ����
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
		//���ø����̼� ����Ʈ ������Ʈ �ڵ� �ۼ�
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