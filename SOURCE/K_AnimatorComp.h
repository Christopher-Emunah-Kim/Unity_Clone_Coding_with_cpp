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
			Event startEvent;
			Event completeEvent;
			Event endEvent;
		};

		AnimatorComp();
		virtual ~AnimatorComp();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

		void CreateAnimation(const std::wstring& name , Texture* spriteSheet , 
			Vector2D leftTop , Vector2D size , Vector2D offset , UINT spriteLength , float duration);

		void CreateAnimationByFolder(const std::wstring& name , const std::wstring& folderPath ,
			Vector2D offset , float duration);

		Animation* FindAnimation(const std::wstring& name);
		void PlayAnimation(const std::wstring& name , bool bLoop = true);

		Events* FindEvents(const std::wstring& name);
		std::function<void()>& GetStartEvent(const std::wstring& name);
		std::function<void()>& GetCompleteEvent(const std::wstring& name);
		std::function<void()>& GetEndEvent(const std::wstring& name);

		inline bool IsComplete() { return m_activeAnimation->IsComplete(); }

	private:
		std::map<std::wstring , Animation*> m_animations;
		Animation* m_activeAnimation;
		bool m_bLoop;

		//Event
		std::map<std::wstring , Events*> m_events;
	};
}


