#pragma once
#include "ymWarrior.h"

namespace Nmy
{
	class image;
	class Animator;

	class Fighter : public Warrior
	{
	public:
		Fighter();
		~Fighter();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;


		virtual void Brandish();
		virtual void SpiritBlade();

		void SetHp(int hp) { mHp = hp; }
		int GetHp() { return mHp; }

	private:

		float mCoff;
		float mSpeed;
		float mDmg;
		image* pImage;
		Animator* mAnimator;
		Vector2 mMissileDir;


		Animator* fSkillnumber1;
		Animator* fSkillnumber2;


		int mHp;
	};
}