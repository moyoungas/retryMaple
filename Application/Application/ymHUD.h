#pragma once
#include "UIBase.h"


namespace Nmy
{
	class Actor;
	class HUD : public UIBase
	{
	public:
		HUD(eUIType type);
		~HUD();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear()  override;

		void SetTarget(Actor* target) { mTarget = target; }



	private:
	
		Actor* mTarget;
	};



}