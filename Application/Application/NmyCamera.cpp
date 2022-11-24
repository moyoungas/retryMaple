#include "NmyCamera.h"
#include "myNewApplication.h"
#include "Actor.h"
#include "Player.h"
#include "NmyInput.h"
#include "Time.h"
#include "Nmyimage.h"
#include "ymMap.h"
#include "NmyScene.h"

namespace Nmy
{
	Vector2 Camera::mResolution = Vector2::Zero;
	Vector2 Camera::mLookPosition = Vector2::Zero;
	Vector2 Camera::mDistance = Vector2::Zero;
	Actor* Camera::mTarget = nullptr;
	Vector2 Camera::mCameraLimited = Vector2::Zero;
	Vector2 Camera::mLimitedA = Vector2::Zero;



	CameraEffect Camera::mEffect = CameraEffect::None;
	image* Camera::mCutton = nullptr; // 검정색 이미지
	float Camera::mAlphaTime = 0.0f;
	float Camera::mCuttonAlpha = 0.0f;
	float Camera::mEndTime = 5.0f;
	float Camera::prevY = 0.0f;



	void Camera::Initialize()
	{

		WindowDataA data = NewApplication::Getinstance().GetWindowdata();

		mResolution = Vector2(data.width, data.height);
		mLookPosition = (mResolution / 2.0f);

		//mEffect = CameraEffect::FadeIn;
		mCutton = image::Create(L"CameraCutton", 1600, 900);


	}
	void Camera::Tick()
	{




		if (mTarget != nullptr)
		{
			mLookPosition = mTarget->GetPos();
			mCameraLimited = Scene::GetmLimited() - mTarget->GetPos();
		}
		

		if (mLookPosition.x < 800 || mLookPosition.x > 1460)
		{
			return;
		}
		if (mLookPosition.y > 1350)
			return;

		if (mCameraLimited.x  > 1460.0f || mCameraLimited.x < 800)
		{

				return;

		}
		if (mCameraLimited.y < 470)
		{
			if (true)
			{

			}

			return;
		}


		//if (mLookPosition.y > 1350)
		//{
		//	return;
		//}



		//if (mAlphaTime <= mEndTime)
		//{
		//	mAlphaTime += Time::DeltaTime();
		//	float ratio = (mAlphaTime / mEndTime);

		//	if (CameraEffect::FadeIn == mEffect)
		//	{
		//		mCuttonAlpha = 1.0f - ratio;
		//	}
		//	else if (CameraEffect::FadeOut == mEffect)
		//	{
		//		mCuttonAlpha = ratio;
		//	}
		//}

		//if (KEY_PRESSED(eKeyCode::UP))
		//{
		//	mLookPosition.y -= 600.0f * Time::DeltaTime();
		//}
		//if (KEY_PRESSED(eKeyCode::DOWN))
		//{
		//	mLookPosition.y += 600.0f * Time::DeltaTime();
		//}
		//if (KEY_PRESSED(eKeyCode::LEFT))
		//{
		//	mLookPosition.x -= 600.0f * Time::DeltaTime();
		//}
		//if (KEY_PRESSED(eKeyCode::RIGHT))
		//{
		//	mLookPosition.x += 600.0f * Time::DeltaTime();
		//}


		mDistance = mLookPosition - (mResolution / 2.0f);
		prevY = mLookPosition.y;

	}

	void Camera::Render(HDC hdc)
	{
		//if (mCuttonAlpha <= 0.0f)
		//	return;
		//HBRUSH gray = NewApplication::Getinstance().GetBrush(eBrushColor::Transparent);
		//Brush brush(hdc, gray);

		//HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		//HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//HPEN oldpen = NULL;

		//Pen pen(hdc);

		//Vector2 mPos = Camera::CalculatePos(mTarget->GetPos());

		//// 스케일을 길이로 써버림
		//Rectangle(hdc, mPos.x
		//	, mPos.y
		//	, mDistance.x
		//	, mDistance.y);

		//SelectObject(hdc, oldpen);
		//DeleteObject(redPen);
		//DeleteObject(greenPen);

	}

}
