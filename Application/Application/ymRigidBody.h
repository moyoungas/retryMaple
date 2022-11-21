#pragma once
#include "NmyComponent.h"


namespace Nmy
{


	class RigidBody : public Component
	{
		public:
			RigidBody();
			~RigidBody();

			virtual void Tick() override;
			virtual void Render(HDC hdc) override;

			void AddForce(Vector2 force);
			void SetMass(float mass) { mMass = mass; }


			bool GetGround() { return mbGround; }
			void SetGround(bool isGround) { mbGround = isGround; }

			Vector2 GetVelocity() { return mVelocity; }
			void SetVelocity(Vector2 value) { mVelocity = value; }

		private:
			float mMass;		// 질량
			float mFriction;      // 마찰력
			Vector2 mForce;		// 미는 힘
			Vector2 mVelocity;
			Vector2 mAccelation;	// 가속도


			// 중력을 이용한 점프
			Vector2 mGravity;
			bool mbGround;
			Vector2 mLimitVelocity;
	};
}

