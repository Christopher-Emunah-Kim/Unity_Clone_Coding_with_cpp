#include "K_Time.h"

namespace KHS
{
	float Time::m_deltaTime = 0.0f;
	TimePoint Time::m_prevTimePoint{};

	void Time::Initialize()
	{
		m_prevTimePoint = std::chrono::steady_clock::now();

		////CPU 고유진동수
		//QueryPerformanceFrequency(&m_CPUFrequency);
		////프로그램 시작시점 진동수
		//QueryPerformanceCounter(&m_prevFreuquency);
	}

	bool Time::CanUpdate()
	{
		TimePoint current = std::chrono::steady_clock::now();

		std::chrono::duration<float> deltaTime = current - m_prevTimePoint;

		if (TICK_INTERVAL_MS * 0.001f > deltaTime.count()) // 틱 간격보다 짧으면 업데이트 안함.
		{
			return false;
		}
		
		m_prevTimePoint = current;

		m_deltaTime = deltaTime.count();

		return true;

		///*QueryPerformanceCounter(&m_curFreuquency);

		//const LONGLONG differenceFrequency = m_curFreuquency.QuadPart - m_prevFreuquency.QuadPart;

		//m_deltaTime = dt; 

		//m_prevFreuquency = m_curFreuquency;*/
	}

	void Time::Render(HDC hdc)
	{
		static double time = 0.0f;

		time += m_deltaTime;


		const double fps = (m_deltaTime > 0.0) ? (1.0 / m_deltaTime) : 0.0;;

		auto to_short = [](double v) {
			std::wstring s = std::to_wstring(v);
			if (s.size() > 5) s.resize(5);
			return s;
			};

		std::wstring str = L"Time : " + to_short(time);
		str += L" FPS : " + to_short(static_cast<int>(fps));

		TextOut(hdc, 10, 10, str.c_str(), static_cast<int>(str.size()));
	}
	float Time::GetDeltaTime()
	{
		return std::chrono::duration<float>(m_deltaTime).count(); 
	}
}