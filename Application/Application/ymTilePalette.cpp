#include "ymTilePalette.h"
#include "Nmyimage.h"
#include "MyResources.h"

namespace Nmy
{



	TilePalette::TilePalette()
	{
		mImage = Resources::Load<image>(L"TileAtlas", L"..\\Resource\\Image\\Tile.bmp");
	}	
	TilePalette::~TilePalette()
	{

	}

	void TilePalette::Tick()
	{

	}

	void TilePalette::Render(HDC hdc)
	{

	}


}