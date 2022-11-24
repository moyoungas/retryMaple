#pragma once
#include "NmyScene.h"


namespace Nmy
{
	class Mob;
	class Map;
	class Player;

	class Play2Scene : public Scene
	{
	public:
		Play2Scene();
		~Play2Scene();


		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void Enter();
		virtual void Exit();

	private:
		Mob* mMob;
		Map* restMap;
		Player* mPlayer;

	};

}
