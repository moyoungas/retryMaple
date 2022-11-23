#pragma once
#include "NmyResource.h"

namespace Nmy
{
	class image : public Resource
	{
	public:
		static image* Create(const std::wstring& key, UINT width, UINT height);


		image();
		~image();

		virtual HRESULT Load(const std::wstring& path) override;

		HDC GetDc() { return mhdc; }
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mheight; }

		Pixel GetPixelImage(int x, int y);
		void SetPixel(int x, int y, Pixel pixel);

	private:
		HBITMAP	mBitmap;
		HDC mhdc;
		UINT mWidth;
		UINT mheight;
	};



}