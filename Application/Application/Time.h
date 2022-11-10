#pragma once
#include "NCommon.h"

namespace Nmy
{

	class Time
	{
	public:
		static void Initialize();
		static void Tick();
		static void Render(HDC hdc);
		static float DeltaTime() { return mDeltaTime; }



	private:
		// cpu 고유 진동수 (1초당 몇번) -> 1초에 12000
		static LARGE_INTEGER mCpuFrequency;
		static LARGE_INTEGER mPrevFrequency;
		static LARGE_INTEGER mCurFrequency;
		static float mDeltaTime;
		static float mTime;
	};




}