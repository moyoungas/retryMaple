#pragma once

#include "NmyScene.h"

namespace Nmy
{

	class PlayScene : public Scene
	{
	public:

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;


		virtual void Enter();
		virtual void Exit();

		PlayScene();
		~PlayScene();

	private:
	};



}

