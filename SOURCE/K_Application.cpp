#include "K_Application.h"
#include "K_Input.h"

namespace KHS
{
	Application::Application()
		:m_hwnd(nullptr), m_hdc(nullptr)
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

		m_player.SetPosition(0.0f, 0.0f);

		Input::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
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
		m_player.Render(m_hdc);
	}
}