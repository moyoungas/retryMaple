#include "NmyCamera.h"
#include "myNewApplication.h"
#include "Actor.h"
#include "Player.h"
#include "NmyInput.h"
#include "Time.h"
#include "Nmyimage.h"

namespace Nmy
{
	 Vector2 Camera::mResolution = Vector2::Zero; 
	 Vector2 Camera::mLookPosition = Vector2::Zero;
	 Vector2 Camera::mDistance = Vector2::Zero; 
	 Actor* Camera::mTarget = nullptr;


	CameraEffect Camera::mEffect = CameraEffect::None;
	image*Camera::mCutton = nullptr; // 검정색 이미지
	float Camera::mAlphaTime = 0.0f;
	float Camera::mCuttonAlpha = 0.0f;
	float Camera::mEndTime = 5.0f;

	void Camera::Initialize()
	{
		WindowDataA data = NewApplication::Getinstance().GetWindowdata();

		mResolution = Vector2(data.width, data.height);
		mLookPosition = (mResolution / 2.0f);

		//mEffect = CameraEffect::FadeIn;
		mCutton = image::Create(L"CameraCutton", 1600 , 900);
	}
	void Camera::Tick()
	{
		if (mAlphaTime <= mEndTime)
		{
			mAlphaTime += Time::DeltaTime();
			float ratio = (mAlphaTime / mEndTime);

			if (CameraEffect::FadeIn == mEffect)
			{
				mCuttonAlpha = 1.0f - ratio;
			}
			else if (CameraEffect::FadeOut == mEffect)
			{
				mCuttonAlpha = ratio;
			}
		}

		if (KEY_PRESSED(eKeyCode::UP))
		{
			mLookPosition.y -= 600.0f * Time::DeltaTime();
		}
		if (KEY_PRESSED(eKeyCode::DOWN))
		{
			mLookPosition.y += 600.0f * Time::DeltaTime();
		}
		if (KEY_PRESSED(eKeyCode::LEFT))
		{
			mLookPosition.x -= 600.0f * Time::DeltaTime();
		}
		if (KEY_PRESSED(eKeyCode::RIGHT))
		{
			mLookPosition.x += 600.0f * Time::DeltaTime();
		}

		if (mTarget != nullptr)
			mLookPosition = mTarget->GetPos();
		
		mDistance = mLookPosition - (mResolution / 2.0f);

	}

	void Camera::Render(HDC hdc)
	{
		if (mCuttonAlpha <= 0.0f)
			return;

		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = 0;
		// 투명도
		func.SourceConstantAlpha = (BYTE)(255.0f * mCuttonAlpha);

		AlphaBlend(hdc, 0, 0
			, mCutton->GetWidth(), mCutton->GetHeight()
			, mCutton->GetDc(), 0, 0
			, mCutton->GetWidth(), mCutton->GetHeight()
			, func);

	}

}
