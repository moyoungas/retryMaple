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

		eColliderLayer GetColliderLayer() { return eColliderLayer::Player; }
		void WalkComplete();
		void SetHp(int hp) { mHp = hp; }
		int GetHp() { return mHp; }

	private:
		bool isRight;
		bool isJump;
		float mCoff;
		float mSpeed;
		float mDmg;
		image* pImage;
		Animator* mAnimator;
		Vector2 mMissileDir;

		int mHp;
	};



}


