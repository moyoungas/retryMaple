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

		void CreateTile(UINT index, Vector2 IndexPos);
		// CreateTiles

		// void Save
		// void Load

		image* GetAtlasImage() { return mImage; }



	private:
		image* mImage;
		std::unordered_map<UINT64, Tile*> mTiles;
	};


}