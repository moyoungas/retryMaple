#include "ymTilePalette.h"
#include "Nmyimage.h"
#include "MyResources.h"
#include "NmyObject.h"
#include "ToolScene.h"
#include "NmyInput.h"

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
			if (KEY_PRESSED(eKeyCode::LBTN))
			{
				if (GetFocus())
				{
					Nmy::Vector2 mousePos = Nmy::Input::GetMousePos();

					int y = mousePos.y / (TILE_SIZE * TILE_SCALE);
					int x = mousePos.x / (TILE_SIZE * TILE_SCALE);

					Nmy::Scene* scene = Nmy::SceneManager::GetPlayScene();
					Nmy::ToolScene* toolScene = dynamic_cast<Nmy::ToolScene*>(scene);
					UINT index = toolScene->GetTileIndex();

					CreateTile(index, Vector2(x, y));
				}
			}

	}

	void TilePalette::Render(HDC hdc)
	{

	}

	void TilePalette::CreateTile(UINT index, Vector2 IndexPos)
	{
		TileID key;
		key.left = IndexPos.x;
		key.right = IndexPos.y;

		std::unordered_map<UINT64, Tile*>::iterator iter = mTiles.find(key.ID);
		if (iter != mTiles.end())
		{
			iter->second->SetIndex(index);
		}

		Vector2 objectPos = IndexPos * (TILE_SIZE * TILE_SCALE);

		Tile* tile = obj::Instantiate<Tile>(objectPos,eColliderLayer::Tile);
		tile->Initialize(mImage, index);

		mTiles.insert(std::make_pair(key.ID, tile));

	}


}