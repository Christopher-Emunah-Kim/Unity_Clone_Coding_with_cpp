#pragma once
#include "CommonInclude.h"

namespace KHS
{
	using TimePoint = std::chrono::steady_clock::time_point;

	static constexpr int FPS = 60;
	static constexpr float TICK_INTERVAL_MS = 1000.0f / (float)FPS - 0.1f;

	class Time
	{
	public:
		static void Initialize();
		static bool CanUpdate();
		static void Render(HDC hdc);

		static float GetDeltaTime();

	private:
		static float m_deltaTime;
		static TimePoint m_prevTimePoint;
	};
}