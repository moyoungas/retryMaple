#include "NmyMob.h"
#include "Nmyimage.h"
#include "MyResources.h"
#include "NmyCollider.h"

namespace Nmy
{
	Mob::Mob() 
		: mHp(100.0f)
		, mSpeed(1.0f)
	{

		Amotion[0] = L"Idle";
		Amotion[1] = L"hit";
		Amotion[2] = L"Jump";
		Amotion[3] = L"Move";
		Amotion[4] = L"die";

		for (size_t i = 0; i < 5; i++)
		{
			mMobPath[i] = L"..\\Resource\\MapleSprite\\Mob\\1210102\\" + Amotion[i];
		}

	}
	Mob::~Mob()
	{



	}
	void Mob::Initialize()
	{
		SetPos({800 , 450});

		mAnimator->CreateAnimations(mMobPath[0], L"MushIdle");
		mAnimator->Play(L"MushIdle");

		AddComponent(new Collider());
	}

	void Mob::Tick()
	{

	}

	void Mob::Render(HDC hdc)
	{
	}

	void Mob::OnCollisionEnter(Collider* other)
	{
	}

	void Mob::OnCollisionStay(Collider* other)
	{
	}

	void Mob::OnCollisionExit(Collider* other)
	{
	}

	void Mob::SetDeathTime(float time)
	{
	}

}