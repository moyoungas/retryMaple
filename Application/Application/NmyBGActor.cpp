#include "NmyBGActor.h"
#include "MyResources.h"
#include "Nmyimage.h"

namespace Nmy
{
	BGActor::BGActor()
		: pImage(nullptr)
	{
		SetPos(Vector2::Zero);
		SetScale(Vector2::One);
	}
	BGActor::~BGActor()
	{
	}
	void BGActor::Initialize()
	{


	}
	void BGActor::Tick()
	{	
		Actor::Tick();
	}
	void BGActor::Render(HDC hdc)
	{

		Vector2 pos = GetPos();
		Vector2 mScale = GetScale();

		Vector2 finalPos = pos;

		Vector2 rect;
		rect.x = pImage->GetWidth() * mScale.x;
		rect.y = pImage->GetHeight() * mScale.y;

		TransparentBlt(hdc, finalPos.x, finalPos.y
			, rect.x, rect.y, pImage->GetDc()
			, 0, 0, pImage->GetWidth(), pImage->GetHeight()
			, RGB(255, 0, 255));



		Actor::Render(hdc);
	}
	void BGActor::SetImage(const std::wstring& key, const std::wstring& imageName)
	{

		if (pImage == nullptr)
		{
			std::wstring path = L"..\\Resource\\Image\\";
			path += imageName;

			pImage = Resources::Load<image>(key, path);
		}
	}
}