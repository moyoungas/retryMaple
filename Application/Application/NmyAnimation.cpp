#include "NmyAnimation.h"
#include "Nmyimage.h"
#include "NmyAnimator.h"
#include "NmyCamera.h"
#include "Actor.h"
#include "Time.h"

namespace Nmy
{




	Animation::Animation()
	{
	}

	Animation::~Animation()
	{




	}

	void Animation::Tick()
	{
		if (mbComplete)
			return;

		mTime += Time::DeltaTime();
		if (mSpriteSheet[mSpriteIndex].duration < mTime)
		{
			mTime = 0.0f;
			if (mSpriteSheet.size() <= mSpriteIndex + 1)
				mbComplete = true;
			else
				mSpriteIndex++;
		}
	


	}

	void Animation::Render(HDC hdc)
	{
		Actor* actorobj = mAnimator->GetOwner();
		Vector2 pos = actorobj->GetPos();

		if (mAffectedCamera)
			pos = Camera::CalculatePos(pos);


		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		// Åõ¸íµµ
		func.SourceConstantAlpha = 255;

		pos += mSpriteSheet[mSpriteIndex].offset;


		AlphaBlend(hdc
			,int(pos.x - mSpriteSheet[mSpriteIndex].size.x / 2.0f)
			,int(pos.y - mSpriteSheet[mSpriteIndex].size.y / 2.0f)
			,int(mSpriteSheet[mSpriteIndex].size.x)
			,int(mSpriteSheet[mSpriteIndex].size.y)
			, pimage->GetDc() 
			,int(mSpriteSheet[mSpriteIndex].leftTop.x)
			,int(mSpriteSheet[mSpriteIndex].leftTop.y)
			,int(mSpriteSheet[mSpriteIndex].size.x)
			,int(mSpriteSheet[mSpriteIndex].size.y),
			func);


	}

	void Animation::AniCreate(image* aimage, Vector2 leftTop, Vector2 size, Vector2 offset
		, UINT spriteLength, float duration, bool bAffEctedCamera)
	{

		pimage = aimage;
		mAffectedCamera = bAffEctedCamera;
		for (size_t i = 0; i < spriteLength; i++)
		{
			Sprite sprite;
			sprite.leftTop.x = leftTop.x + (size.x * (float)i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			mSpriteSheet.push_back(sprite);
		}
	}

	void Animation::Reset()
	{
		mSpriteIndex = 0;
		mTime = 0.0f;
		mbComplete = false;
	}

}