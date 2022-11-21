#include "NmyAnimator.h"
#include "Actor.h"
#include "Nmyimage.h"
#include "NmyCamera.h"
#include "NmyResource.h"
#include "MyResources.h"

namespace Nmy
{




	Animator::Animator()
		: Component(eComponentType::Animator)
		, mPlayAnimation(nullptr)
		, mLoop(false)
	{
		//pimage = Resources::Load<image>(L"Player", L"..\\Resource\\Image\\Player.bmp");

	}

	Animator::~Animator()
	{
		// mAnimations;
		for (auto iter : mAnimations)
		{
			delete iter.second;
		}
		// mEvents;

		for (auto iter : mEvents)
		{
			delete iter.second;
		}
	}

	void Animator::Tick()
	{
		if (mPlayAnimation != nullptr)
		{
			mPlayAnimation->Tick();

			if (mLoop && mPlayAnimation->isComplete())
			{
				Animator::Events* events = FindEvents(mPlayAnimation->GetName());
				if (events != nullptr)
					events->mCompleteEvent();

				mPlayAnimation->Reset();
			}
		}
		
	}


	void Animator::Render(HDC hdc)
	{
		if (mPlayAnimation != nullptr)
		{
			mPlayAnimation->Render(hdc);
		}


		//BLENDFUNCTION func = {};
		//func.BlendOp = AC_SRC_OVER;
		//func.BlendFlags = 0;
		//func.AlphaFormat = AC_SRC_ALPHA;
		//// 투명도
		//func.SourceConstantAlpha = 255;

		//AlphaBlend(hdc
		//	, 0
		//	, 0
		//	, mSPriteSheet->GetWidth()
		//	, mSPriteSheet->GetHeight()
		//	, mSPriteSheet->GetDc()
		//	, 0
		//	, 0
		//	, mSPriteSheet->GetWidth()
		//	, mSPriteSheet->GetHeight()
		//	, func);


	}


	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		std::map<std::wstring, Animation*>::iterator iter = mAnimations.find(name);
		if (iter == mAnimations.end())
			return nullptr;

		return iter->second;
	}

	void Animator::CreateAnimation(const std::wstring& name, image* pimage
		, Vector2 leftTop, Vector2 size, Vector2 offset
		, UINT spriteLength, float duration, bool bAffEctedCamera)
	{
		Animation* animation = FindAnimation(name);

		if (animation != nullptr) {
			MessageBox(nullptr, L"중복 애니메이션 생성", L"애니메이션 생성 실패", MB_OK);
			return;
		}

		animation = new Animation();
		animation->AniCreate(pimage	, leftTop, size,offset
			, spriteLength, duration,bAffEctedCamera);
	
		animation->SetName(name);
		animation->SetAnimator(this);

		mAnimations.insert(std::make_pair(name, animation));

		Events* events = new Events();
		mEvents.insert(std::make_pair(name, events));
	}

	void Animator::CreateAnimations(const std::wstring& path , const std::wstring& name
	, Vector2 offset , float duration)
	{

		UINT width = 200;
		UINT height = 200;
		UINT filecount = 0;
		
		std::filesystem::path mpath(path);
		std::vector<image*> images;
		for (auto& p : std::filesystem::recursive_directory_iterator(path))
		{
			std::wstring filename = p.path().filename();

			std::wstring keyString = CreateAnimationKey(path);
			std::wstring fullName = path  + L"\\" + filename;

			image* reimage = Resources::Load<image>(filename, fullName);
			images.push_back(reimage);

			if (width < reimage->GetWidth())
				width = reimage->GetWidth();

			if (height < reimage->GetHeight())
				height = reimage->GetHeight();

			filecount++;
		}


		mSPriteSheet = image::Create(name, width * filecount , height);
		int index = 0;
		for (image* reimage : images)
		{
			BitBlt(mSPriteSheet->GetDc(), width * index, 0, reimage->GetWidth(), reimage->GetHeight()
				, reimage->GetDc(), 0, 0, SRCCOPY);
			index++;
		}

		CreateAnimation(name, mSPriteSheet, Vector2::Zero, Vector2(width, height)
			, offset, filecount, duration);
	}

	std::wstring Animator::CreateAnimationKey(std::wstring path)
	{

		std::wstring keyString = path;
		// 애니메이션 폴더 이름 추출
		UINT pos = keyString.find_last_of(L"\\");
		std::wstring tail = keyString.substr(pos + 1, keyString.length());
		keyString = keyString.substr(0, pos);


		// 애니메이션 오브젝트이름 추출
		pos = keyString.find_last_of(L"\\");
		std::wstring head = keyString.substr(pos + 1, keyString.length());
		keyString = keyString.substr(0, pos);
		keyString = head + tail;

		return keyString;
	}


	void Animator::Play(const std::wstring& name, bool bLoop)
	{
		Animator::Events*  events = FindEvents(name);
		if (events != nullptr)
			events->mStartEvent();

		Animation* prevAnimation = mPlayAnimation;

		mPlayAnimation = FindAnimation(name);
		mPlayAnimation->Reset();
		mLoop = bLoop;

		if (prevAnimation != mPlayAnimation)
			events->mEndEvent();

	}


	Animator::Events* Animator::FindEvents(const std::wstring key)
	{

		std::map<std::wstring, Events*>::iterator iter = mEvents.find(key);
		if (iter == mEvents.end())
			return nullptr;


		return iter->second;
	}

	std::function<void()>& Animator::GetStartEvents(const std::wstring key)
	{
		Events* events = FindEvents(key);

		return events->mStartEvent.mEvent;
	}

	std::function<void()>& Animator::GetCompleteEvents(const std::wstring key)
	{
		Events* events = FindEvents(key);

		return events->mCompleteEvent.mEvent;

	}

	std::function<void()>& Animator::GetEndEvents(const std::wstring key)
	{

		Events* events = FindEvents(key);

		return events->mEndEvent.mEvent;
	}


}