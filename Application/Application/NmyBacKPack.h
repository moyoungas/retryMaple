#pragma once
#include "NCommon.h"
#include "Actor.h"

namespace Nmy
{

	class image;
	class BackPack : public Actor
	{
	public:
		BackPack();
		~BackPack();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;


		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;


	private:
		float mSpeed;
		image* pImage;
	};



}
