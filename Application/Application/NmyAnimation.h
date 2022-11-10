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
			Vector2 leftTop;  //좌측 상단 시작표
			Vector2 size;     //좌측상단으로부터 잘라낼 가로 세로 길이
			Vector2 offset;
			float duration;	  //해당프레임 유지 시간

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