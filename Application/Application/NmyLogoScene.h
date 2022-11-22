#pragma once
#include "NmyScene.h"


namespace Nmy
{
	class Monster;
	class Map;
	class Player;

	class LogoScene : public Scene
	{
	public:
		LogoScene();
		~LogoScene();


		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;


		virtual void Enter();
		virtual void Exit();

		Player* GetPlayer() { return maPlayer; }

		static Vector2 GetmLimited() { return mLimited; }



	private:
		static Vector2 mLimited;
		Player* maPlayer;
		Monster* mons[2];
	};

}

