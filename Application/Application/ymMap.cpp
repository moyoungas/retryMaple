#include "ymMap.h"
#include "MyResources.h"
#include "Nmyimage.h"
#include "Player.h"
#include "NmyCamera.h"
#include "ymRigidBody.h"
#include "SceneManager.h"
#include "NmyLogoScene.h"

namespace Nmy
{




	Map::Map()
		: pImage(nullptr)
		, PixelImage(nullptr)
	{
		SetPos(Vector2::Zero);
		SetScale(Vector2::One);

		if (PixelImage == nullptr)
		{
			PixelImage = Resources::Load<image>(L"BackUp", L"..\\Resource\\MapleSprite\\Map\\StartMapPixel.bmp");
		}

		Scene* playScene = SceneManager::GetPlayScene();
		maPlayer = dynamic_cast<LogoScene*>(playScene)->GetPlayer();

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
		//Vector2 playerPos = Player::GetPlayerPos();

		////PixelImage->GetPixel(playerPos);

		PlayerPos = GetPos();
		//PixelImage->GetPixel(PlayerPos.x, PlayerPos.y);



	}

	void Map::Render(HDC hdc)
	{



		Vector2 pos = GetPos();
		Vector2 mScale = GetScale();

		Vector2 finalPos = Camera::CalculatePos(pos);

		Vector2 rect;
		rect.x = pImage->GetWidth() * mScale.x;
		rect.y = pImage->GetHeight() * mScale.y;

		TransparentBlt(hdc, finalPos.x, finalPos.y
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

	Vector2 Map::GetImageWidth()
	{
		Vector2 temp;
		temp.x = pImage->GetWidth();
		temp.y = pImage->GetHeight();


		return temp;
	}

	Vector2 Map::GetImageHeight()
	{
		return Vector2();
	}



}