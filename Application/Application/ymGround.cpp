#include "ymGround.h"
#include "Player.h"
#include "NmyCollider.h"
#include "ymRigidBody.h"
#include "NmyMob.h"

#include "ymUIManager.h"

namespace Nmy
{



	Ground::Ground()
	{
		Collider* collider = AddComponent<Collider>();
		collider->SetScale(Vector2(600.0f, 10.0f));

	}

	Ground::~Ground()
	{
	}

	void Ground::Tick()
	{
		Actor::Tick();
	}

	void Ground::Render(HDC hdc)
	{
		Actor::Render(hdc);
	}

	void Ground::OnCollisionEnter(Collider* other)
	{


		Mob* mobObj = dynamic_cast<Mob*>(other->GetOwner());
		mobObj->GetComponent<RigidBody>()->SetGround(true);

		float fLen2 = fabs(other->GetPos().y - GetComponent<Collider>()->GetPos().y);
		float fScale2 = other->GetScale().y / 2.0f + GetComponent<Collider>()->GetScale().y / 2.0f;

		if (fLen2 < fScale2)
		{
			Vector2 playerPos = mobObj->GetPos();
			playerPos.y -= (fScale2 - fLen2) - 1.0f;
			mobObj->SetPos(playerPos);
		}


		//Player* playerObj = dynamic_cast<Player*>(other->GetOwner());
		//Collider* playerCollider = playerObj->GetComponent<Collider>();

		//if (other == playerCollider)
		//{
		//	playerObj->GetComponent<RigidBody>()->SetGround(true);

		//	int hp = playerObj->GetHp();
		//	hp -= 10;
		//	playerObj->SetHp(hp);

		//	float fLen = fabs(other->GetPos().y - GetComponent<Collider>()->GetPos().y);
		//	float fScale = other->GetScale().y / 2.0f + GetComponent<Collider>()->GetScale().y / 2.0f;

		//	if (fLen < fScale)
		//	{
		//		Vector2 playerPos = playerObj->GetPos();
		//		playerPos.y -= (fScale - fLen) - 1.0f;
		//		playerObj->SetPos(playerPos);
		//	}

		//}

	}

	void Ground::OnCollisionStay(Collider* other)
	{
	}

	void Ground::OnCollisionExit(Collider* other)
	{
		Actor* playerObj = other->GetOwner();
		playerObj->GetComponent<RigidBody>()->SetGround(false);
	}

}