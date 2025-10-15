#include "K_AnimatorComp.h"

namespace KHS
{
	AnimatorComp::AnimatorComp()
		:Component(EComponentType::ANIMATOR), 
		m_animations{} , m_activeAnimation{ nullptr } , m_bLoop{ false }
	{
	}

	AnimatorComp::~AnimatorComp()
	{
		for ( auto& pair : m_animations )
		{
			delete pair.second;
			pair.second = nullptr;
		}
		m_animations.clear();
		m_activeAnimation = nullptr;
	}

	void AnimatorComp::Initialize()
	{
		Component::Initialize();
	}

	void AnimatorComp::Update()
	{
		Component::Update();
		
		if ( m_activeAnimation )
		{
			m_activeAnimation->Update();

			if ( m_activeAnimation->IsComplete() == true && m_bLoop == true )
			{
				m_activeAnimation->Reset();
			}
		}
	}

	void AnimatorComp::LateUpdate()
	{
		Component::LateUpdate();
	}

	void AnimatorComp::Render(HDC hdc)
	{
		Component::Render(hdc);

		if ( m_activeAnimation )
		{
			m_activeAnimation->Render(hdc);
		}
	}

	void AnimatorComp::CreateAnimation(const std::wstring& name, Texture* spriteSheet,
		Vector2D leftTop, Vector2D size, Vector2D offset, UINT spriteLength, float duration)
	{
		Animation* anim = nullptr;

		anim = FindAnimation(name);

		if ( anim != nullptr )
		{
			return;
		}

		anim = new Animation();
		anim->CreateAnimation(name , spriteSheet , leftTop , size , offset , spriteLength , duration);
		anim->SetAnimator(this);

		m_animations.insert(std::make_pair(name , anim));
	}

	Animation* AnimatorComp::FindAnimation(const std::wstring& name)
	{
		std::map<std::wstring , Animation*>::iterator iter = m_animations.find(name);

		if ( iter == m_animations.end() )
		{
			return nullptr;
		}

		return iter->second;
	}

	void AnimatorComp::PlayAnmation(const std::wstring& name, bool bLoop)
	{
		Animation* anim = FindAnimation(name);

		if ( anim == nullptr )
		{
			return;
		}

		if ( m_activeAnimation == anim )
		{
			return;
		}

		m_activeAnimation = anim;
		m_activeAnimation->Reset();
		m_bLoop = bLoop;
	}
}