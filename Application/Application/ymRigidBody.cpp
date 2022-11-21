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

		// �ӵ��� ���ӵ��� ��ŸŸ�� ���� �����ش�.
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
		//�ִ� �ӵ� ����
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


		

		// ������ ����(����� ���� ���� , �ӵ��� 0�� �ƴҶ�)
		if (!(mVelocity == Vector2::Zero))
		{
			// �ӵ��� �ݴ� ����
			Vector2 friction = -mVelocity;
			// �����¿� �ش��ϴ� vector
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

		// �ӵ��� ���� ��ü�� �̵���Ű��
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