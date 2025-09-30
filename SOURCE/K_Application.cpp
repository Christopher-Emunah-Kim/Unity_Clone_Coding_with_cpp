#include "K_Application.h"

namespace KHS
{
	Application::Application()
		:m_hwnd(nullptr), m_hdc(nullptr), m_speed(0.0f), m_x(0.0f), m_y(0.0f)
	{
	}

	Application::~Application()
	{
		ReleaseDC(m_hwnd, m_hdc);
	}

	void Application::Initialize(HWND hwnd)
	{
		m_hwnd = hwnd;
		m_hdc = GetDC(m_hwnd); 
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		m_speed += 0.01f;

		if(GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			m_x -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			m_x += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			m_y -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			m_y += 0.01f;
		}
	}

	void Application::LateUpdate()
	{
		//���ø����̼� ����Ʈ ������Ʈ �ڵ� �ۼ�
	}

	void Application::Render()
	{
		//�Ķ� �귯�� ����
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		// �Ķ� �귯�� DC�� ���� �׸��� ��� �귯�� ��ȯ�� ��ȯ
		HBRUSH oldBrush = (HBRUSH)SelectObject(m_hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(m_hdc, redPen);
		SelectObject(m_hdc, oldPen);

		Rectangle(m_hdc, 100 + m_x, 100 + m_y, 200 + m_x, 200 + m_y);

		SelectObject(m_hdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}