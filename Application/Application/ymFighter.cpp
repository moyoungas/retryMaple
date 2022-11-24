#include "ymFighter.h"
#include "NmyAnimator.h"


namespace Nmy
{




	Fighter::Fighter()
	{
		fSkillnumber1 = new Animator();

		fSkillnumber1->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Fighter\\Skills\\Brandish", L"Brandish");
		fSkillnumber1->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Fighter\\Skills\\Brandishright", L"RightBrandish");

		fSkillnumber1->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Fighter\\Skills\\SpiritBlade", L"SpiritBlade");
	}

	Fighter::~Fighter()
	{
		
	}

	void Fighter::Tick()
	{
	}

	void Fighter::Render(HDC hdc)
	{
	}

	void Fighter::OnCollisionEnter(Collider* other)
	{
	}

	void Fighter::OnCollisionStay(Collider* other)
	{




	}

	void Fighter::OnCollisionExit(Collider* other)
	{
	}

	void Fighter::Brandish()
	{
		fSkillnumber1->Play(L"Brandish", true);
		fSkillnumber1->Play(L"RightBrandish", true);
	}

	void Fighter::SpiritBlade()
	{
		fSkillnumber1->Play(L"SpiritBlade", true);
	}

}