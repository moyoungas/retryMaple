#pragma once
#include "NmyScene.h"


namespace Nmy
{
	class Monster;
	class Map;

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

		static Vector2 GetmLimited() { return mLimited; }



	private:
		static Vector2 mLimited;
		Monster* mons[2];
	};

}

