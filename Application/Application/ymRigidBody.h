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
			float mMass;		// ����
			float mFriction;      // ������
			Vector2 mForce;		// �̴� ��
			Vector2 mVelocity;
			Vector2 mAccelation;	// ���ӵ�


			// �߷��� �̿��� ����
			Vector2 mGravity;
			bool mbGround;
			Vector2 mLimitVelocity;
	};
}

