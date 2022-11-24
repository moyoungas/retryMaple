#pragma once
#include "ymFighter.h"

namespace Nmy
{
	class image;
	class Animator;

	class Crusader : public Fighter
	{
	public:
		Crusader();
		~Crusader();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;


		void Rush();
		void BraveSlash();
		void ScaringSword();

	private:

		float mCoff;
		float mSpeed;
		float mDmg;
		image* pImage;
		Animator* mAnimator;


		Animator* cSkillnumber1;


		int mHp;
	};
}