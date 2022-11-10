#include "NmyBackPack.h"
#include "Time.h"
#include "NmyCollider.h"
#include "NmyCamera.h"
#include "MyResources.h"
#include "Nmyimage.h"
#include "NmyAnimator.h"

namespace Nmy
{
	BackPack::BackPack()
		: pImage(nullptr)
	{
		SetPos({ 1600 / 2 ,900 / 2 });
		SetScale({ 3.0f , 3.0f });


		if (pImage == nullptr)
		{

			// 여기서 경로 입력시 이 파일이 있는 경로에 로드를 함
			// 그러므로 ..을 붙여 앞폴더로 나간 뒤 
			pImage = Resources::Load<image>(L"BackPack", L"..\\Resource\\Image\\BackPack.bmp");
		}
	}

	BackPack::~BackPack()
	{
	}

	void BackPack::Tick()
	{
		Actor::Tick();

	}

	void BackPack::Render(HDC hdc)
	{

		Vector2 pos = GetPos();
		Vector2 mScale = GetScale();

		Vector2 finalPos;
		finalPos.x = pos.x - (pImage->GetWidth() * (mScale.x / 2.0f));
		finalPos.y = pos.y - (pImage->GetHeight() * (mScale.x / 2.0f));

		Vector2 rect;
		rect.x = pImage->GetWidth() * mScale.x;
		rect.y = pImage->GetHeight() * mScale.y;

		finalPos = Camera::CalculatePos(finalPos);

		//TransparentBlt(hdc, finalPos.x, finalPos.y
		//	, rect.x, rect.y, pImage->GetDc()
		//	, 0, 0, pImage->GetWidth(), pImage->GetHeight()
		//	, RGB(255, 0, 255));

		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		// 투명도
		func.SourceConstantAlpha = 127;
		

		AlphaBlend(hdc, finalPos.x, finalPos.y
			, rect.x, rect.y, pImage->GetDc()
			, 0, 0, pImage->GetWidth(), pImage->GetHeight(),
			func);

		Actor::Render(hdc);
	}

	void BackPack::OnCollisionEnter(Collider* other)
	{


	}

	void BackPack::OnCollisionStay(Collider* other)
	{
	}

	void BackPack::OnCollisionExit(Collider* other)
	{
	}

}