#include "ymCrusader.h"
#include "NmyAnimator.h"
#include "NmyCollider.h"


namespace Nmy
{



	Crusader::Crusader()
	{
		cSkillnumber1 = new Animator();
		cSkillnumber2 = new Animator();
		cSkillnumber3 = new Animator();


		cSkillnumber1->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Crusader\\Skills\\Rush", L"Rush");
		cSkillnumber1->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Crusader\\Skills\\Rushright", L"RightRush");

		cSkillnumber2->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Crusader\\Skills\\BraveSlash", L"BraveSlash");
		cSkillnumber2->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Crusader\\Skills\\BraveSlashright", L"RightBraveSlash");

		cSkillnumber3->CreateAnimations(L"..\\Resource\\MapleSprite\\Character\\Skill\\Crusader\\Skills\\ScaringSword", L"ScaringSword");
	}

	Crusader::~Crusader()
	{
	}

	void Crusader::Tick()
	{
	}

	void Crusader::Render(HDC hdc)
	{
	}

	void Crusader::OnCollisionEnter(Collider* other)
	{
	}

	void Crusader::OnCollisionStay(Collider* other)
	{
	}

	void Crusader::OnCollisionExit(Collider* other)
	{
	}

	void Crusader::Rush()
	{


	}

	void Crusader::BraveSlash()
	{
	}

	void Crusader::ScaringSword()
	{
	}

}