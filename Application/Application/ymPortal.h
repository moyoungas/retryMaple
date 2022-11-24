#pragma once
#include "Actor.h"

namespace Nmy
{
	class Animator;

	class Portal : public Actor
	{

	public:
		Portal();
		~Portal();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

	private:
		Animator* mAnimator;
	};


}

