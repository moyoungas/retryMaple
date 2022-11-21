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

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

		void Death() { mDead = true; }
		bool IsDeath() { return mDead; }
		void SetDeathTime(float time) { mDeathTime = time; }
		float GetHp() { return mHp; }


	private:
		float mSpeed;
		float mHp;
		float mDeathTime;
		bool mDead;
		image* mImage;


		Animator* mAnimator;

		
	};


}

