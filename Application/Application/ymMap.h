#pragma once
#include "Actor.h"


namespace Nmy
{
	class image;
	class Player;
	class Mob;

	class Map : public Actor
	{
	public:
		Map();
		~Map();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void SetImage(const std::wstring& key, const std::wstring& fileName, std::wstring path = L"");
		void SetPixelImage(const std::wstring& key, const std::wstring& fileName, std::wstring path = L"");

		Vector2 GetImageVolume();
		void SetPlayer(Player* player) { maPlayer = player; }
		void SetMob(Mob* mob) { mMapMob = mob; }


	private:
		Vector2 PlayerPos;
		Player* maPlayer;
		Mob* mMapMob;
		Vector2 mMobPos;
		image* pImage;
		image* PixelImage;
	};


}

