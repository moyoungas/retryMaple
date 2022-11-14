#include "ToolScene.h"
#include "myNewApplication.h"

namespace Nmy
{

	ToolScene::ToolScene()
	{
		mTilePalette = new TilePalette();

	}

	ToolScene::~ToolScene()
	{
		delete mTilePalette;
	}


	void ToolScene::Initialize()
	{
		
	}

	void ToolScene::Tick()
	{
	
	}

	void ToolScene::Render(HDC hdc)
	{

		Scene::Render(hdc);

		WindowDataA mainWidnow = NewApplication::Getinstance().GetWindowdata();

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(0, 125, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		int maxRow = mainWidnow.height / TILE_SIZE + 1;
		for (size_t i = 0; i < maxRow; i++)
		{
			MoveToEx(hdc, 0, TILE_SIZE * i, nullptr);
			LineTo(hdc, mainWidnow.width, TILE_SIZE * i);
		}

		int maxColumn = mainWidnow.width / TILE_SIZE + 1;
		for (size_t i = 0; i < maxColumn; i++)
		{
			MoveToEx(hdc, TILE_SIZE * i, 0, nullptr);
			LineTo(hdc, TILE_SIZE * i, mainWidnow.height);
		}

		(HPEN)SelectObject(hdc, oldPen);
		DeleteObject(redPen);


	}


	void ToolScene::Enter()
	{

		NewApplication::Getinstance().SetMenuBar(true);
	}

	void ToolScene::Exit()
	{
	}

}