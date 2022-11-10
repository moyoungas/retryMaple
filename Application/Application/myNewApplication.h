#pragma once

#include "NCommon.h"
#include "NmyScene.h"
#include "Nmyimage.h"

namespace Nmy
{

	// ���� ���α׷��� �� �༮
	class NewApplication
	{
	public:
		static NewApplication& Getinstance()
		{

			static NewApplication mInstance;
			return mInstance;
		}

		void Initialize(WindowDataA data);
		void Tick();

		WindowDataA GetWindowdata() { return mWindowdata; }
		HDC GetHDC() { return mWindowdata.hdc; }
		HPEN GetPen(ePenColor color) { return mPen[(UINT)color]; }
		HBRUSH GetBrush(eBrushColor color) { return mBrush[(UINT)color]; }


	private:
		NewApplication();
		~NewApplication();

		void initializeWindow(WindowDataA data);

	private:
		WindowDataA mWindowdata;
		HPEN mPen[(UINT)ePenColor::END];
		HBRUSH mBrush[(UINT)eBrushColor::END];
	};

}


