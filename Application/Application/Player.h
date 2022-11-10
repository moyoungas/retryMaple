#pragma once
#include "Actor.h"

namespace Nmy
{
	class image;
	class Animator;

	class Player : public Actor
	{
	public:
		Player();
		~Player();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

		void WalkComplete();

	private:
		float mCoff;
		float mSpeed;
		image* pImage;
		Animator* mAnimator;
		Vector2 mMissileDir;
	};



}

