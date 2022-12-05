#include "ymPortal.h"
#include "NmyAnimator.h"
#include "Player.h"
#include "NmyCollider.h"
#include "NmyCollider.h"

namespace Nmy
{

	Portal::Portal()
	{
		SetName(L"Portal");
		SetPos({ 800 , 450 });
		SetScale({ 1.0f, 1.0f });
		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resource\\MapleSprite\\Portal", L"Portal");
		mAnimator->Play(L"Portal", true);
		Collider* collider = new Collider();


		AddComponent(mAnimator);
		AddComponent(collider);
	}

	Portal::~Portal()
	{
	}

	void Portal::Tick()
	{
		Actor::Tick();
	}

	void Portal::Render(HDC hdc)
	{
		Actor::Render(hdc);
	}

	void Portal::OnCollisionEnter(Collider* other)
	{



	}

	void Portal::OnCollisionStay(Collider* other)
	{
	}

	void Portal::OnCollisionExit(Collider* other)
	{
	}

}