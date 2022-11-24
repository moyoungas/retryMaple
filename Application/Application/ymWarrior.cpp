#include "ymWarrior.h"
#include "NmyAnimator.h"
#include "NmyInput.h"
#include "Time.h"

namespace Nmy
{



	Warrior::Warrior()
	{
		Skillnumber1 = new Animator();
		Skillnumber2 = new Animator();
		Skillnumber3 = new Animator();
		Skillnumber4 = new Animator();

		Skillnumber1->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Warrior\\Skills\\LeafAttack", L"LeftLeafAttack");
		Skillnumber1->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Warrior\\Skills\\LeafAttackright", L"RightLeafAttack");

		Skillnumber2->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Warrior\\Skills\\SlashBlust", L"Slashblust");
		Skillnumber2->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Warrior\\Skills\\SlashBlustright", L"RightSlashblust");

		Skillnumber3->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Warrior\\Skills\\UpperCharge", L"UpperCharge");
		Skillnumber3->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Warrior\\Skills\\UpperChargeright", L"RightUpperCharge");

		Skillnumber4->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Warrior\\Skills\\WarriorLeaf", L"WarriorLeaf");
		Skillnumber4->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Warrior\\Skills\\WarriorLeafright", L"RightWarriorLeaf");
	}

	Warrior::~Warrior()
	{


	}

	void Warrior::Tick()
	{
		Actor::Tick();


		Vector2 pos = GetPos();

		if (KEY_PRESSED(eKeyCode::W))
		{
			pos.y -= 200.0f * Time::DeltaTime();
			//GetComponent<RigidBody>()->AddForce(Vector2(0.0f, -1000.0f));
		}
		if (KEY_PRESSED(eKeyCode::S))
		{
			pos.y += 200.0f * Time::DeltaTime();
			//GetComponent<RigidBody>()->AddForce(Vector2(0.0f, 1000.0f));
		}
		if (KEY_PRESSED(eKeyCode::A))
		{
			pos.x -= 200.0f * Time::DeltaTime();
			//GetComponent<RigidBody>()->AddForce(Vector2(-1000.0f, 0.0f));
		}
		if (KEY_PRESSED(eKeyCode::D))
		{
			pos.x += 200.0f * Time::DeltaTime();
			// 돌진 계산
			//GetComponent<RigidBody>()->AddForce(Vector2(3000.0f, 0.0f));
			//GetComponent<RigidBody>()->AddForce(Vector2(1000.0f, 0.0f));
		}

	}

	void Warrior::Render(HDC hdc)
	{

		Actor::Render(hdc);
	}

	void Warrior::OnCollisionEnter(Collider* other)
	{
	}

	void Warrior::OnCollisionStay(Collider* other)
	{
	}

	void Warrior::OnCollisionExit(Collider* other)
	{
	}

	void Warrior::SlashBlust()
	{
	}

	void Warrior::LeafAttack()
	{
	}

	void Warrior::WarriorLeaf()
	{
	}

	void Warrior::UpperCharge()
	{
	}

}