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
		// cpu ���� ������ (1�ʴ� ���) -> 1�ʿ� 12000
		static LARGE_INTEGER mCpuFrequency;
		static LARGE_INTEGER mPrevFrequency;
		static LARGE_INTEGER mCurFrequency;
		static float mDeltaTime;
		static float mTime;
	};




}