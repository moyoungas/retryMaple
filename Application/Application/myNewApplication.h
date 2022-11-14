#pragma once

#include "NCommon.h"
#include "NmyScene.h"
#include "Nmyimage.h"

namespace Nmy
{

	// 메인 프로그램이 될 녀석
	class NewApplication
	{
	public:
		static NewApplication& Getinstance()
		{

			static NewApplication mInstance;
			return mInstance;
		}

		void Initialize(WindowDataA data);
		void initializeAtalsWindow(WindowDataA data);
		void Tick();
		void SetMenuBar(bool power);

		WindowDataA GetWindowdata() { return mWindowdata; }
		WindowDataA GetAtlasWindowdata() { return mAtlasWindowdata; }
		HDC GetHDC() { return mWindowdata.hdc; }
		HPEN GetPen(ePenColor color) { return mPen[(UINT)color]; }
		HBRUSH GetBrush(eBrushColor color) { return mBrush[(UINT)color]; }


	private:
		NewApplication();
		~NewApplication();

		void initializeWindow(WindowDataA data);

	private:
		WindowDataA mWindowdata;
		WindowDataA mAtlasWindowdata;
		HPEN mPen[(UINT)ePenColor::END];
		HBRUSH mBrush[(UINT)eBrushColor::END];

		HMENU mMenu;
	};

}


