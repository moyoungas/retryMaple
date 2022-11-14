#pragma once
#include "SceneManager.h"
#include "ymTilePalette.h"

namespace Nmy
{
	class image;

	class ToolScene : public Scene
	{
	public:

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		ToolScene();
		~ToolScene();

		virtual void Enter();
		virtual void Exit();

		image* GetAtlasimage() { return mTilePalette->GetAtlasImage(); }

	private:
		TilePalette* mTilePalette;
	};




}

