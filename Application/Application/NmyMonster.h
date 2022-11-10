#pragma once
#include "Actor.h"

namespace Nmy
{
	class image;

	class Monster : public Actor
	{
	public:
		Monster();
		Monster(Vector2 pos);
		~Monster();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;


		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

	private:
		image* pImage;
		float mTime;
	};



}
