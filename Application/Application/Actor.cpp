#include "Actor.h"
#include "NmyComponent.h"
#include "Time.h"

namespace Nmy
{
	Actor::Actor()
		: mPos{ 0.0f , 0.0f }
		, mScale{ 1.0f , 1.0f }
		, mDead(false)
		, mDeathTime(-10.0f)
		, mDeathTimeOn(false)
	{
	}
	Actor::Actor(Vector2 pos)
		: mPos(pos)
		, mScale{ 1.0f , 1.0f }
		, mDead(false)
		, mDeathTime(-10.0f)
		, mDeathTimeOn(false)
	{



	}

	Actor::~Actor()
	{
		for (Component* component : mComponents)
		{
			if (component == nullptr)
				continue;
			delete component;
			component = nullptr;
		}

	}


	void Actor::Initialize()
	{
	}

	void Actor::Tick()
	{

		DeathLoop();
		// 모든 컴포넌트 tick을 호출
		for (Component* component : mComponents)
		{
			if (component == nullptr)
				continue;

			component->Tick();
		}

	}

	void Actor::Render(HDC hdc)
	{
		// 모든 컴포넌트 Render를 호출

		for (Component* component : mComponents)
		{
			if (component == nullptr)
				continue;

			component->Render(hdc);

		}
	}

	void Actor::OnCollisionEnter(Collider* other)
	{
	}

	void Actor::OnCollisionStay(Collider* other)
	{
	}

	void Actor::OnCollisionExit(Collider* other)
	{
	}

	void Actor::SetDeathTime(float time)
	{

		if (mDeathTime <= 0.0f)
		{
			mDeathTime = time;
			mDeathTimeOn = true;
		}

	}

	void Actor::AddComponent(Component* component)
	{
		if (component == nullptr)
			return;

		mComponents.push_back(component);

		component->mOwner = this;


	}

	void Actor::DeathLoop()
	{

		if (mDeathTimeOn == true)
		{
			mDeathTime -= Time::DeltaTime();

			if (mDeathTime <= 0.0f)
			{
				Death();

			}
		}

	}





}


