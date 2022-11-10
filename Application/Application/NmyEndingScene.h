#pragma once
#include "NmyScene.h"


namespace Nmy
{

	class EndScene : public Scene
	{
	public:
		EndScene();
		~EndScene();


		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void Enter();
		virtual void Exit();

	private:


	};

}
