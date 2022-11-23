#pragma once
#include "Player.h"

namespace Nmy
{
	class image;
	class Animator;

	class Warrior : public Player
	{
	public:
		Warrior();
		~Warrior();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;


		virtual void SlashBlust();
		virtual void LeafAttack();
		virtual void WarriorLeaf();
		virtual void UpperCharge();



		void SetHp(int hp) { mHp = hp; }
		int GetHp() { return mHp; }

	private:
		bool isJump;
		float mCoff;
		float mSpeed;
		float mDmg;
		image* pImage;
		Animator* mAnimator;
		Vector2 mMissileDir;


		Animator* Skillnumber1;
		Animator* Skillnumber2;
		Animator* Skillnumber3;
		Animator* Skillnumber4;


		int mHp;
	};
}
