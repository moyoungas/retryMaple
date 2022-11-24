#include "ymMap.h"
#include "MyResources.h"
#include "Nmyimage.h"
#include "Player.h"
#include "NmyCamera.h"
#include "ymRigidBody.h"
#include "SceneManager.h"
#include "NmyLogoScene.h"
#include "ymRigidBody.h"
#include "NmyInput.h"
#include "NmyMob.h"
#include "ymPortal.h"


namespace Nmy
{




	Map::Map()
		: pImage(nullptr)
		, PixelImage(nullptr)
	{
		SetPos(Vector2::Zero);
		SetScale(Vector2::One);


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

		if (maPlayer == nullptr)
		{
			return;
		}



		PlayerPos = maPlayer->GetPos();
		Pixel pixel = PixelImage->GetPixelImage(PlayerPos.x, PlayerPos.y + 50.0f);

		if (pixel.R == 0 && pixel.G == 0 && pixel.B == 255)
		{
			if (KEY_DOWN(eKeyCode::SPACE) && KEY_DOWN(eKeyCode::DOWN))
			{
				if (pixel.R == 0 && pixel.G == 0 && pixel.B == 255)
					maPlayer->GetComponent<RigidBody>()->SetGround(false);
			}

			maPlayer->GetComponent<RigidBody>()->SetGround(true);

			Vector2 playerPos = maPlayer->GetPos();
			playerPos.y -= 1.0f;
			maPlayer->SetPos(playerPos);

		}
		else if (pixel.R == 255 && pixel.G == 0 && pixel.B == 255)
		{
			maPlayer->GetComponent<RigidBody>()->SetGround(true);
			Vector2 playerPos = maPlayer->GetPos();
			playerPos.y -= 1.0f;
			maPlayer->SetPos(playerPos);
		}
		else if (pixel.R == 255 && pixel.G == 0 && pixel.B == 0)
		{
			Vector2 playerPos = maPlayer->GetPos();
			playerPos.x += 10.0f;
			maPlayer->SetPos(playerPos);
		}
		else
		{
			maPlayer->GetComponent<RigidBody>()->SetGround(false);
		}

		if (mMapMob == nullptr)
		{
			return;
		}

		mMobPos = mMapMob->GetPos();
		Pixel Mobpixel = PixelImage->GetPixelImage(mMobPos.x, mMobPos.y + 35);

		if (Mobpixel.R == 0 && Mobpixel.G == 0 && Mobpixel.B == 255)
		{

			mMapMob->GetComponent<RigidBody>()->SetGround(true);

			Vector2 playerPos = mMapMob->GetPos();
			playerPos.y -= 1.0f;
			mMapMob->SetPos(playerPos);

		}
		else if (Mobpixel.R == 255 && Mobpixel.G == 0 && Mobpixel.B == 255)
		{
			mMapMob->GetComponent<RigidBody>()->SetGround(true);
			Vector2 playerPos = mMapMob->GetPos();
			playerPos.y -= 1.0f;
			mMapMob->SetPos(playerPos);
		}
		else if (Mobpixel.R == 255 && Mobpixel.G == 0 && Mobpixel.B == 0)
		{
			Vector2 playerPos = mMapMob->GetPos();
			playerPos.x += 10.0f;
			mMapMob->SetPos(playerPos);
		}
		else
		{
			mMapMob->GetComponent<RigidBody>()->SetGround(false);
		}



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

	void Map::SetPixelImage(const std::wstring& key, const std::wstring& fileName, std::wstring path)
	{

		if (PixelImage == nullptr)
		{
			if (path == L"")
			{
				std::wstring mpath = L"..\\Resource\\Image\\";
				mpath += fileName;
				PixelImage = Resources::Load<image>(key, mpath);
			}
			else
			{
				path += fileName;
				PixelImage = Resources::Load<image>(key, path);
			}
		}

	}

	Vector2 Map::GetImageVolume()
	{
		Vector2 temp;
		temp.x = pImage->GetWidth();
		temp.y = pImage->GetHeight();


		return temp;
	}


}