#include "K_Input.h"

namespace KHS
{
	std::vector<Input::Key> Input::m_keys = { };

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
		VK_CAPITAL
	};

	void Input::Initialize()
	{
		m_keys.resize(static_cast<size_t>(EKeyCode::Max));

		for (size_t i = 0; i < static_cast<size_t>(EKeyCode::Max); ++i)
		{
			Key key;
			key.state = EKeyState::None;
			key.isPressed = false;
			key.keyCode = static_cast<EKeyCode>(i);

			m_keys.push_back(key);
		}
	}

	void Input::Update()
	{
		for (size_t i = 0; i < static_cast<size_t>(EKeyCode::Max); ++i)
		{
			if (GetAsyncKeyState(ASCII[i]) & 0x8000) //현재 프레임에 눌려있음
			{
				if (m_keys[i].isPressed == true) //이전 프레임에도 눌려있었음
				{
					m_keys[i].state = EKeyState::Pressed;
				}
				else
				{
					m_keys[i].state = EKeyState::Down;
				}

				m_keys[i].isPressed = true;
			}
			else //현재 프레임에 눌려있지 않음
			{
				if (m_keys[i].isPressed == true) //이전 프레임에는 눌려있었음
				{
					m_keys[i].state = EKeyState::Up;
				}
				else
				{
					m_keys[i].state = EKeyState::None;
				}

				m_keys[i].isPressed = false;
			}
		}
	}


}