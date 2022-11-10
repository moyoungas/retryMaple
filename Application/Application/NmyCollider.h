#pragma once
#include "NmyComponent.h"

namespace Nmy
{

	class Collider : public Component
	{
	public:

		Collider();
		~Collider();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);


		void SetScale(Vector2 scale) { mScale = scale; }
		void SetPos(Vector2 pos) { mPos = pos; }
		void SetOffset(Vector2 offset) { mOffset = offset; }

		// Collider
		//- 콜리더가 겹치거나 부딪힐때 대미지를 입힌다
		//- 콜리더를 쓸 경우 연산이 많아진다.

		Vector2 GetPos() { return mPos; }
		Vector2 GetOffset() { return mOffset; }
		Vector2 GetScale() { return mScale; }




	private:

		Vector2 mOffset;
		Vector2 mPos;
		Vector2 mScale;

		UINT mCollisionCount;

	};


}
