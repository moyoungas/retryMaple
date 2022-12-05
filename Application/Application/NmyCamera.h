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
		static Vector2 mResolution; // ȭ�� �ػ�
		static Vector2 mLookPosition; // ī�޶� �� ��ǥ
		static Vector2 mDistance; // �ػ� �߽� ��ǥ�� ���� ī�޶��� ���� ��
		static Actor* mTarget;
		static Vector2 mCameraLimited;

		static Vector2 mLimitedA;

		static float prevY;


		static CameraEffect mEffect;
		static image* mCutton;		// ������ �̹���
		static float mAlphaTime;	// �ð� ��
		static float mCuttonAlpha;	// �̹��� ���� ��
		static float mEndTime;		// ���̵� ������ �ð�

	};

}