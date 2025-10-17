#include "K_AnimatorComp.h"
#include "K_ResourceTable.h"

namespace KHS
{
	AnimatorComp::AnimatorComp()
		:Component(EComponentType::ANIMATOR), 
		m_animations{} , m_activeAnimation{ nullptr } , m_bLoop{ false } , m_events{}
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

		for ( auto& pair : m_events )
		{
			delete pair.second;
			pair.second = nullptr;
		}
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

			Events* events = FindEvents(m_activeAnimation->GetName());

			if ( m_activeAnimation->IsComplete() == true )
			{
				if (events)
				{
					events->completeEvent();
				}

				if (m_bLoop == true)
				{
					m_activeAnimation->Reset();
				}
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
		anim->SetName(name);
		anim->CreateAnimation(name , spriteSheet , leftTop , size , offset , spriteLength , duration);
		anim->SetAnimator(this);

		Events* events = new Events();

		m_events.insert(std::make_pair(name, events));
		m_animations.insert(std::make_pair(name , anim));
	}

	void AnimatorComp::CreateAnimationByFolder(const std::wstring& name, const std::wstring& folderPath, Vector2D offset, float duration)
	{
		Animation* anim = nullptr;
		anim = FindAnimation(name);
		if (anim != nullptr)
		{
			return;
		}

		//load all images in the folder
		int fileCount = 0;
		std::filesystem::path filesystem(folderPath);
		std::vector<Texture*> images = {};

		for (const std::filesystem::directory_entry& entry : std::filesystem::recursive_directory_iterator(filesystem))
		{
			std::wstring fileName = entry.path().filename().wstring();
			std::wstring fullName = entry.path().wstring();

			Texture* texture = ResourceTable::Load<Texture>(fileName, fullName);
			images.push_back(texture);

			++fileCount;
		}

		//create sprite sheet
		UINT spriteWidth = images[0]->GetWidth() * fileCount;
		UINT spriteHeight = images[0]->GetHeight();
		
		Texture* spriteSheet = Texture::Create(name, spriteWidth, spriteHeight);
		spriteSheet->SetTextureType(images[0]->GetTextureType());

		UINT imageWidth = images[0]->GetWidth();
		UINT imageHeight = images[0]->GetHeight();

		//copy images to sprite sheet
		for (size_t i = 0; i < images.size(); ++i)
		{
			BitBlt(spriteSheet->GetHdc(), i * imageWidth, 0,
				imageWidth, imageHeight,
				images[i]->GetHdc(), 0, 0, SRCCOPY);
		}

		//create animation
		CreateAnimation(name, spriteSheet, Vector2D::Zero,
			Vector2D((float)imageWidth, (float)imageHeight),
			offset, fileCount, duration);
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

	void AnimatorComp::PlayAnimation(const std::wstring& name, bool bLoop)
	{
		Animation* anim = FindAnimation(name);

		if (anim == nullptr)
		{
			return;
		}

		if (m_activeAnimation == anim)
		{
			return;
		}

		if (m_activeAnimation)
		{
			Events* curEvents = FindEvents(m_activeAnimation->GetName());

			if (curEvents)
			{
				curEvents->endEvent();
			}
		}

		Events* nextEvents = FindEvents(anim->GetName());

		if(nextEvents)
		{
			nextEvents->startEvent();
		}

		m_activeAnimation = anim;
		m_activeAnimation->Reset();
		m_bLoop = bLoop;
	}

	AnimatorComp::Events* AnimatorComp::FindEvents(const std::wstring& name)
	{
		auto iter = m_events.find(name);

		if(iter == m_events.end())
		{
			return nullptr;
		}

		return iter->second;
	}

	std::function<void()>& AnimatorComp::GetStartEvent(const std::wstring& name)
	{
		Events* events = FindEvents(name);
		return events->startEvent.event;
	}

	std::function<void()>& AnimatorComp::GetCompleteEvent(const std::wstring& name)
	{
		Events* events = FindEvents(name);
		return events->completeEvent.event;
	}

	std::function<void()>& AnimatorComp::GetEndEvent(const std::wstring& name)
	{
		Events* events = FindEvents(name);
		return events->endEvent.event;
	}
}