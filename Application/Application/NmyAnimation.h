#pragma once
#include "NCommon.h"
#include "NmyEntity.h"

namespace Nmy
{
	class Animator;
	class image;

	class Animation : public Entity
	{

	public:

		struct Sprite
		{
			Vector2 leftTop;  //���� ��� ����ǥ
			Vector2 size;     //����������κ��� �߶� ���� ���� ����
			Vector2 offset;
			float duration;	  //�ش������� ���� �ð�

			Sprite()
				: leftTop(0.0f , 0.0f)
				, size(0.0f , 0.0f)
				, offset(0.0f , 0.0f)
				, duration(0.0f)
			{

			}


		};

		Animation();
		~Animation();

		void Tick();
		void Render(HDC hdc);

		void AniCreate(image* pimage , Vector2 leftTop, Vector2 size, Vector2 offset
			, UINT spriteLength, float duration, bool bAffEctedCamera = true);
		void Reset();
		void SetAnimator(Animator* anim) { mAnimator = anim; }

		bool isComplete() { return mbComplete; }

	private:
		Animator* mAnimator;
		image* pimage;
		std::vector<Sprite> mSpriteSheet;
		UINT mSpriteIndex;
		float mTime;

		bool mStart;
		bool mbComplete;
		bool mEnd;
		bool mAffectedCamera;




	};


}