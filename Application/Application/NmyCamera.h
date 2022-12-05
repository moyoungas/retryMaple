#pragma once
#include "NCommon.h"

namespace Nmy
{
	class Actor;
	class image;

	class Camera
	{
	public:
		static void Initialize();
		static void Tick();
		static void Render(HDC hdc);
		

		static Vector2 CalculatePos(Vector2 pos)
		{ return pos - mDistance; }
		static void SetTarget(Actor* actor) { mTarget = actor; }


	private:
		Camera() = default;
		~Camera() = default;
	private:
		static Vector2 mResolution; // 화면 해상도
		static Vector2 mLookPosition; // 카메라가 볼 좌표
		static Vector2 mDistance; // 해상도 중심 좌표와 현재 카메라의 간격 차
		static Actor* mTarget;
		static Vector2 mCameraLimited;

		static Vector2 mLimitedA;

		static float prevY;


		static CameraEffect mEffect;
		static image* mCutton;		// 검정색 이미지
		static float mAlphaTime;	// 시간 값
		static float mCuttonAlpha;	// 이미지 알파 농도
		static float mEndTime;		// 페이드 끝나는 시간

	};

}