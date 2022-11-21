#include "ymRigidBody.h"
#include "NmyComponent.h"
#include "Time.h"
#include "Actor.h"
namespace Nmy
{



	RigidBody::RigidBody()
		: Component(eComponentType::RigidBody)
		, mMass(1.0f)
		, mForce(Vector2::Zero)
		, mVelocity(Vector2::Zero)
		, mAccelation(Vector2::Zero)
		, mFriction(100.0f)
		, mGravity(Vector2(0.0f,800.0f))
		, mbGround(false)
		,mLimitVelocity(Vector2(200.0f,1000.0f))
	{

	}

	RigidBody::~RigidBody()
	{
	}

	void RigidBody::Tick()
	{
		// F = M x A 
		// A = F / M
		mAccelation = mForce / mMass;

		// 속도에 가속도를 델타타임 마다 더해준다.
		mVelocity += (mAccelation * Time::DeltaTime());



		if (mbGround == true)
		{
			Vector2 gravity = mGravity;
			gravity.Normalize();
			float dot = math::Dot(mVelocity, gravity);
			mVelocity -= gravity * dot;
		}
		else
		{
			mVelocity += mGravity * Time::DeltaTime();
		}
		//최대 속도 제한
		Vector2 gravity = mGravity;
		gravity.Normalize();
		float dot = math::Dot(mVelocity, gravity);
		gravity = gravity * dot;

		Vector2 sideVelocity = mVelocity - gravity;
		if (mLimitVelocity.y < gravity.Length())
		{
			gravity *= mLimitVelocity.y;
		}

		if (mLimitVelocity.x < sideVelocity.Length())
		{
			sideVelocity.Normalize(); sideVelocity *= mLimitVelocity.x;
		}


		

		// 마찰력 조건(적용된 힘이 없고 , 속도가 0이 아닐때)
		if (!(mVelocity == Vector2::Zero))
		{
			// 속도에 반대 방향
			Vector2 friction = -mVelocity;
			// 마찰력에 해당하는 vector
			friction = friction.Normalize() * mFriction * mMass * Time::DeltaTime();
			

			if (mVelocity.Length() < friction.Length())
			{
				mVelocity = Vector2::Zero;
			}
			else
			{
				mVelocity += friction;
			}
		}

		// 속도에 맞춰 물체를 이동시키기
		Vector2 pos = GetOwner()->GetPos();
		pos = pos + mVelocity * Time::DeltaTime();

		GetOwner()->SetPos(pos);
		mForce.Clear();
		
	}

	void RigidBody::Render(HDC hdc)
	{
	}

	void RigidBody::AddForce(Vector2 force)
	{
		mForce += force;
	}

}