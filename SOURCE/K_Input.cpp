#include "K_Input.h"
#include "K_Application.h"

extern KHS::Application app;

namespace KHS
{
	std::vector<Input::Key> Input::m_keys = { };
	Vector2D Input::m_mousePosition = Vector2D::Zero;

	int ASCII[static_cast<int>(EKeyCode::Max)] =
	{
		'A', 'B', 'C', 'D', 'E', 'F', 'G',
		'H', 'I', 'J', 'K', 'L', 'M', 'N',
		'O', 'P', 'Q', 'R', 'S', 'T', 'U',
		'V', 'W', 'X', 'Y', 'Z',
		VK_LEFT,
		VK_RIGHT,
		VK_UP,
		VK_DOWN,
		VK_SPACE,
		VK_ESCAPE,
		VK_RETURN,
		VK_SHIFT,
		VK_CONTROL,
		VK_MENU,
		VK_TAB,
		VK_CAPITAL,
		VK_LBUTTON,
		VK_MBUTTON,
		VK_RBUTTON
	};

	void Input::Initialize()
	{
		CreateKeys();
	}


	void Input::Update()
	{
		UpdateKeys();
	}


	void Input::CreateKeys()
	{
		m_keys.clear();
		m_keys.reserve(static_cast<size_t>(EKeyCode::Max));

		for (size_t i = 0; i < static_cast<size_t>(EKeyCode::Max); ++i)
		{
			Key key;
			key.state = EKeyState::None;
			key.isPressed = false;
			key.keyCode = static_cast<EKeyCode>(i);

			m_keys.push_back(key);
		}
	}

	void Input::UpdateKeys()
	{
		for (size_t i = 0; i < static_cast<size_t>(EKeyCode::Max); ++i)
		{
			UpdateKey(m_keys[i]);
		}
	}

	void Input::UpdateKey(Input::Key& key)
	{
		if ( GetFocus() )
		{
			if ( IsKeyDown(key.keyCode) )
			{
				UpdateKeyDown(key);
			}
			else
			{
				UpdateKeyUp(key);
			}

			GetMousePositionByWindow();
		}
		else
		{
			ClearKeys();
		}
	}

	bool Input::IsKeyDown(EKeyCode code)
	{
		return GetAsyncKeyState(ASCII[static_cast<int>(code)]) & 0x8000;
	}

	void Input::UpdateKeyDown(Input::Key& key)
	{
		if (key.isPressed == true) //이전 프레임에도 눌려있었음
		{	
			key.state = EKeyState::Pressed;
		}
		else
		{
			key.state = EKeyState::Down;
		}

		key.isPressed = true;
	}

	void Input::UpdateKeyUp(Input::Key& key)
	{
		if (key.isPressed == true) //이전 프레임에는 눌려있었음
		{
			key.state = EKeyState::Up;
		}
		else
		{
			key.state = EKeyState::None;
		}

		key.isPressed = false;
	}

	void Input::GetMousePositionByWindow()
	{
		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(app.GetHwnd() , &mousePos);

		m_mousePosition.x = static_cast< float >( mousePos.x );
		m_mousePosition.y = static_cast< float >( mousePos.y );
	}

	void Input::ClearKeys()
	{
		for(Key& key : m_keys)
		{
			if(key.state == EKeyState::Pressed || key.state == EKeyState::Down)
			{
				key.state = EKeyState::Up;
			}
			else if ( key.state == EKeyState::Up )
			{
				key.state = EKeyState::None;
			}

			key.isPressed = false;
		}
	}
}