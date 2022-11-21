#include "ymMap.h"
#include "MyResources.h"
#include "Nmyimage.h"
#include "Player.h"
#include "ymRigidBody.h"


namespace Nmy
{




	Map::Map()
		: pImage(nullptr)
	{
	}

	Map::~Map()
	{
	}

	void Map::Initialize()
	{
	}

	void Map::Tick()
	{
		Actor::Tick();

		Vector2 playerPos = Player::GetPlayerPos();

		//PixelImage->GetPixel(playerPos);




	}

	void Map::Render(HDC hdc)
	{



		Vector2 pos = GetPos();
		Vector2 mScale = GetScale();

		Vector2 finalPos = pos;

		Vector2 rect;
		rect.x = pImage->GetWidth() * mScale.x;
		rect.y = pImage->GetHeight() * mScale.y;

		TransparentBlt(hdc,0, 0
			, rect.x, rect.y, pImage->GetDc()
			, 0, 0, pImage->GetWidth(), pImage->GetHeight()
			, RGB(255, 0, 255));


		Actor::Render(hdc);
	}

	void Map::SetImage(const std::wstring& key, const std::wstring& fileName, std::wstring path)
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