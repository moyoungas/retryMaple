#include "ymTile.h"
#include "NmyCamera.h"
#include "Nmyimage.h"

namespace Nmy
{



    Tile::Tile(Vector2 pos)
        : Actor(pos)
        , mAtlas(nullptr)
        , mY(-1)
        , mX(-1)
    {
    }



    Tile::~Tile()
    {
    }

    void Tile::Initialize(image* atlas, int index)
    {
        mIndex = index;
        if (mAtlas == nullptr || index < 0)
            return;

        mAtlas = atlas;

        int maxColumn = mAtlas->GetWidth() / (TILE_SIZE * TILE_SCALE);
        int maxRow = mAtlas->GetHeight() / (TILE_SIZE * TILE_SCALE);


        mY = index / maxColumn;
        mX = index % maxColumn;
    }

    void Tile::Tick()
    {
    }

    void Tile::Render(HDC hdc)
    {
        if (mAtlas == nullptr)
            return;

        Vector2 renderPos = Camera::CalculatePos(GetPos());

        int tileImgY = mY * TILE_SIZE;
        int tileImgX = mX * TILE_SIZE;

        TransparentBlt(hdc, renderPos.x, renderPos.y
            , TILE_SIZE * TILE_SCALE, TILE_SIZE * TILE_SCALE
            , mAtlas->GetDc()
            , tileImgX, tileImgY
            , TILE_SIZE, TILE_SIZE
            , RGB(255, 0, 255));
    }

    void Tile::SetIndex(UINT index)
    {
        mIndex = index;

        int maxColumn = mAtlas->GetWidth() / TILE_SIZE;
        int maxRow = mAtlas->GetHeight() / TILE_SIZE;


        mY = index / maxColumn;
        mX = index % maxColumn;

    }

}