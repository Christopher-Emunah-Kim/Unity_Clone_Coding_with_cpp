#pragma once
#include "K_Resource.h"
#include "K_Texture.h"

namespace KHS
{
	class AnimatorComp;

	class Animation : public Resource
	{
	public:
	
		struct SpriteInfo
		{
			Vector2D leftTop;
			Vector2D size;
			Vector2D offset;
			float duration;

			SpriteInfo()
				:leftTop(Vector2D::Zero) , size(Vector2D::Zero) , 
				offset(Vector2D::Zero) , duration(0.0f)
			{
			}
		};

		Animation();
		virtual ~Animation();

	private:
		void ProcessAlphaBlending(HDC hdc , Vector2D& pos);

	public:
		virtual HRESULT Load(const std::wstring& path) override;

		void Update();
		void Render(HDC hdc);
		void Reset();

		void CreateAnimation(const std::wstring& name, Texture* spriteTexture,
			Vector2D leftTop , Vector2D spriteSize , Vector2D offset , 
			UINT spriteLength , float duration);

		inline bool IsComplete() { return m_bComplete; }
		inline void SetAnimator(AnimatorComp* animator) { m_animator = animator; }

	private:
		AnimatorComp* m_animator;
		Texture* m_spriteTexture;

		std::vector<SpriteInfo> m_animaionSheet;
		int m_currentIndex;
		float m_time;
		bool m_bComplete;

	};

}