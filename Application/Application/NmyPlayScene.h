#pragma once

#include "NmyScene.h"

namespace Nmy
{

	class PlayScene : public Scene
	{
	public:

		virtual void Initialize();
		virtual void Tick();
		virtual void Render(HDC hdc);


		virtual void Enter();
		virtual void Exit();

		PlayScene();
		~PlayScene();

	private:
	};



}

