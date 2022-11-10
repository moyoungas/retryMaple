#pragma once
#include "NCommon.h"
#include "NmyScene.h"
#include "myNewApplication.h"

namespace Nmy
{
	class image;

	class TitleScene : public Scene
	{
	public:

		virtual void Initialize();
		virtual void Tick();
		virtual void Render(HDC hdc);

		TitleScene();
		~TitleScene();

		virtual void Enter();
		virtual void Exit();

	private:
		image* mimage;
	};




}