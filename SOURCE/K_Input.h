#pragma once
#include "CommonInclude.h"

namespace KHS
{
	enum class EKeyState
	{
		Down,
		Pressed,
		Up,
		None
	};

	enum class EKeyCode
	{
		A, B, C, D, E, F, G,
		H, I, J, K, L, M, N,
		O, P, Q, R, S, T, U,
		V, W, X, Y, Z,
		LeftArrow,
		RightArrow,
		UpArrow,
		DownArrow,
		Space,
		Escape,
		Enter,
		Shift,
		Control,
		Alt,
		Tab,
		CapsLock,
		LButton, 
		MButton,
		RButton,
		Max
	};;


	class Input
	{
	public:
		struct Key
		{
			EKeyCode keyCode;
			EKeyState state;
			bool isPressed;
		};

	private:
		static void CreateKeys();
		static void UpdateKeys();

		static void UpdateKey(Input::Key& key);
		static bool IsKeyDown(EKeyCode code);
		static void UpdateKeyDown(Input::Key& key);
		static void UpdateKeyUp(Input::Key& key);
		static void GetMousePositionByWindow();
		static void ClearKeys();

	public:
		static void Initialize();
		static void Update();

		static bool GetKeyDown(EKeyCode code) { return m_keys[static_cast<size_t>(code)].state == EKeyState::Down; }
		static bool GetKeyUp(EKeyCode code) { return m_keys[static_cast<size_t>(code)].state == EKeyState::Up; }
		static bool GetKey(EKeyCode code) { return m_keys[static_cast<size_t>(code)].state == EKeyState::Pressed; }
		static Vector2D GetMousePosition() { return m_mousePosition; }

	private:
		static std::vector<Key> m_keys;
		static Vector2D m_mousePosition;
	};


}

