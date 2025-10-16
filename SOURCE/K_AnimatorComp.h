#pragma once
#include "K_Component.h"
#include "K_Animation.h"

namespace KHS
{
	class AnimatorComp : public Component
	{
	public:
		struct Event
		{
			void operator=(std::function<void()> func)
			{
				event = func;
			}

			void operator()()
			{
				if (event)
					event();
			}

			std::function<void()> event;
		};

		struct Events
		{
			Event start;
			Event complete;
			Event end;
		};

		AnimatorComp();
		virtual ~AnimatorComp();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

		void CreateAnimation(const std::wstring& name , Texture* spriteSheet , 
			Vector2D leftTop , Vector2D size , Vector2D offset , UINT spriteLength , float duration);

		void PlayAnmation(const std::wstring& name , bool bLoop = true);
		Animation* FindAnimation(const std::wstring& name);

		inline bool IsComplete() { return m_activeAnimation->IsComplete(); }

	private:
		std::map<std::wstring , Animation*> m_animations;
		Animation* m_activeAnimation;
		bool m_bLoop;

		//Event
		std::map<std::wstring , Events*> m_events;
	};
}


