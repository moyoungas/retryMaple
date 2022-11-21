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

	private:
		image* pImage;
		image* PixelImage;
	};


}

