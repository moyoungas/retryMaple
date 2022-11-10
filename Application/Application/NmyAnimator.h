#pragma once
#include "NmyComponent.h"
#include "NmyAnimation.h"

namespace Nmy
{

	class image;

	class Animator : public Component
	{
	public:
		struct Event
		{

			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}

			void operator()()
			{
				if (mEvent)
					mEvent();
			}

			std::function<void()> mEvent;
		};

		struct Events
		{
			Event mStartEvent;
			Event mCompleteEvent;
			Event mEndEvent;

		};


		Animator();
		~Animator();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		Animation* FindAnimation(const std::wstring& name);
		void CreateAnimation(const std::wstring& name, image* pimage
			, Vector2 leftTop, Vector2 size, Vector2 offset
			,  UINT spriteLength , float duration , bool bAffEctedCamera = true );
		void CreateAnimations(const std::wstring& path);


		void Play(const std::wstring& name, bool bLoop = false);


		Events* FindEvents(const std::wstring key);

		std::function<void()>& GetStartEvents(const std::wstring key);
		std::function<void()>& GetCompleteEvents(const std::wstring key);
		std::function<void()>& GetEndEvents(const std::wstring key);

	public:
		//Event mStartEvent;
		//Event mCompleteEvent;
		//Event mEndEvent;

	private:
		std::map<std::wstring, Animation*> mAnimations;
		std::map<std::wstring, Events*> mEvents;

		Animation* mPlayAnimation;
		bool mLoop;

		image* mSPriteSheet;
	};


}


