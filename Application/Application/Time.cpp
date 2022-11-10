#include "Time.h"
#include "myNewApplication.h"

namespace Nmy
{
	LARGE_INTEGER Time::mCpuFrequency;
	LARGE_INTEGER Time::mPrevFrequency;
	LARGE_INTEGER Time::mCurFrequency;
	float Time::mDeltaTime = 0.0f;
	float Time::mTime = 0.0f;

	void Time::Initialize()
	{
		// cpu 초당 반복되는 진동수를 얻어오는 함수
		QueryPerformanceFrequency(&mCpuFrequency);
		// 프로그램 시작했을 때 cpu의 클럭 수
		QueryPerformanceCounter(&mPrevFrequency);

	}

	void Time::Tick()
	{
		QueryPerformanceCounter(&mCurFrequency);


		// 시작부터 현재까지의 진동수 
		// 시작 -> 틱 -> 렌더 -> 다시오는 시간
		float differenceFrequency
			= static_cast<float>(mCurFrequency.QuadPart - mPrevFrequency.QuadPart);

		mDeltaTime = differenceFrequency / static_cast<float>(mCpuFrequency.QuadPart);
		// prev값을 새로 받아옴
		mPrevFrequency.QuadPart = mCurFrequency.QuadPart;
	}

	void Time::Render(HDC hdc)
	{

		mTime += Time::DeltaTime();
		if (mTime > 1.0f)
		{

			wchar_t szFloat[50] = {};
			// 프레임
			//- 한 프레임이 도는 동안 총 걸린 시간
			//- 디버깅에서 30프레임 미만이 나올경우 최적화 작업할 것
			float fps = 1.0f / mDeltaTime;

			swprintf_s(szFloat, 50, L"Fps : %f", fps);
			int strlen = wcsnlen_s(szFloat, 50);

			TextOut(hdc, 10, 10, szFloat, strlen);

			HWND hWnd = NewApplication::Getinstance().GetWindowdata().hWnd;

			SetWindowText(hWnd, szFloat);
			mTime = 0.0f;

		}
	}

}