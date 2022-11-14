#pragma once
#include "NCommon.h"
#include "Actor.h"
#include "NmyAnimator.h"

namespace Nmy
{
	class image;

	class Mob : public Actor
	{

	public:
		Mob();
		~Mob();

		virtual void Initialize();
		virtual void Tick();
		virtual void Render(HDC hdc);

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		void Death() { mDead = true; }
		bool IsDeath() { return mDead; }
		void SetDeathTime(float time);
		float GetHp() { return mHp; }


	private:
		float mSpeed;
		float mHp;
		bool mDead;
		image* mImage;


		Animator* mAnimator;
		std::wstring mMobPath[5];
		std::wstring Amotion[5];
		std::wstring mMobSelect;

		
	};


}

