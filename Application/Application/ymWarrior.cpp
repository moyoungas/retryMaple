#include "ymWarrior.h"
#include "NmyAnimator.h"

namespace Nmy
{



	Warrior::Warrior()
	{
		Skillnumber1 = new Animator();
		Skillnumber2 = new Animator();
		Skillnumber3 = new Animator();
		Skillnumber4 = new Animator();

		Skillnumber1->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Warrior\\Skills\\LeafAttack", L"LeftLeafAttack");
		Skillnumber1->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Warrior\\Skills\\LeafAttack\\right", L"RightLeafAttack");

		Skillnumber2->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Warrior\\Skills\\SlashBlust", L"Slashblust");
		Skillnumber2->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Warrior\\Skills\\SlashBlust\\right", L"RightSlashblust");

		Skillnumber3->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Warrior\\Skills\\UpperCharge", L"UpperCharge");
		Skillnumber3->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Warrior\\Skills\\UpperCharge\\right", L"RightUpperCharge");

		Skillnumber4->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Warrior\\Skills\\WarriorLeaf", L"WarriorLeaf");
		Skillnumber4->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Warrior\\Skills\\WarriorLeaf\\right", L"RightWarriorLeaf");
	}

	Warrior::~Warrior()
	{


	}

	void Warrior::Tick()
	{
		Actor::Tick();
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