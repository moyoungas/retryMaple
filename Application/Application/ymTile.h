#pragma once
#include "Actor.h"



namespace Nmy
{
	class image;

	class Tile : public Actor
	{
	public:
		Tile(Vector2 pos);
		~Tile();

		void Initialize(image* atlas, int index);
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void SetIndex(UINT index);
		UINT GetIndex() { return mIndex; }

	private:
		image* mAtlas;
		UINT mIndex;
		UINT mX;
		UINT mY;



	};


}