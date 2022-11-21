#include "NmyMob.h"
#include "Nmyimage.h"
#include "MyResources.h"
#include "NmyCollider.h"
#include "Player.h"
#include "Time.h"
#include "NmyCamera.h"
#include "ymRigidBody.h"
#include "ymGround.h"

namespace Nmy
{
	Mob::Mob() 
		: mHp(100.0f)
		, mSpeed(1.0f)
		, aTime(0.0f)
	{
		SetName(L"Mush");
		SetPos({800 , 450});
		SetScale({ 1.0f, 1.0f });

		mAnimator = new Animator();
		mAnimator->CreateAnimations(L"..\\Resource\\MapleSprite\\Mob\\1210102\\Idle"
			, L"MushIdle");
		mAnimator->Play(L"MushIdle", true);

		AddComponent(mAnimator);

		Collider* collider = new Collider();
		collider->SetOffset(Vector2(-70.0f,-70.0f));
		Vector2 Scale = collider->GetScale() - Vector2(50.0f,50.0f);
		collider->SetScale(Scale);

		AddComponent(collider);
		//AddComponent<RigidBody>();

	}
	Mob::~Mob()
	{

			

	}

	void Mob::Tick()
	{
		Actor::Tick();




	}

	void Mob::Render(HDC hdc)
	{
		Actor::Render(hdc);
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

}