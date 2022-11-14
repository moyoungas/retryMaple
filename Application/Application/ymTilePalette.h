#pragma once
#include "ymTile.h"

namespace Nmy
{
	class image;

	class TilePalette
	{
	public:
		TilePalette();
		~TilePalette();

		void Tick();
		void Render(HDC hdc);

		// CreateTile
		// CreateTiles

		// void Save
		// void Load

		image* GetAtlasImage() { return mImage; }



	private:
		image* mImage;
	};


}