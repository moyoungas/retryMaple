#pragma once
#include "NCommon.h"
#include "Actor.h"

namespace Nmy
{
	class image;

	class Missile : public Actor
	{
	public:
		Missile();
		~Missile();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;


		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;


	private:
		float mSpeed;
		float mAliveTime;

		image* pimage;
	public:
		Vector2  mDir;
		Vector2 mDestPos;
	};



}

