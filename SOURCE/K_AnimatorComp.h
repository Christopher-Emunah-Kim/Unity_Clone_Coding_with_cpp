#pragma once
#include "K_Component.h"
#include "K_Animation.h"

namespace KHS
{
	class AnimatorComp : public Component
	{
	public:
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

	private:
		std::map<std::wstring , Animation*> m_animations;
		Animation* m_activeAnimation;
		bool m_bLoop;
	};
}


