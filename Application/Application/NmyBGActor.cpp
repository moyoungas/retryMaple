#include "NmyBGActor.h"
#include "MyResources.h"
#include "Nmyimage.h"
#include "NmyCamera.h"
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
	void BGActor::SetImage(const std::wstring& key, const std::wstring& fileName , std::wstring path)
	{
		if (pImage == nullptr)
		{
			if (path == L"")
			{
				std::wstring mpath = L"..\\Resource\\Image\\";
				mpath += fileName;
				pImage = Resources::Load<image>(key, mpath);
			}
			else
			{
				path += fileName;
				pImage = Resources::Load<image>(key, path);
			}
		}
	}
}