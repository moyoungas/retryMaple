#pragma once
#include "Actor.h"


namespace Nmy
{
	class image;
	class Map : public Actor
	{
	public:
		Map();
		~Map();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void SetImage(const std::wstring& key, const std::wstring& fileName, std::wstring path = L"");

		Vector2 GetImageWidth();
		Vector2 GetImageHeight();

	private:
		Vector2 PlayerPos;
		Player* maPlayer;
		Pixel* Imagepixel;
		image* pImage;
		image* PixelImage;
	};


}

