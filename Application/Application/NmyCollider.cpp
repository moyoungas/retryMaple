#include "NmyCollider.h"
#include "Actor.h"
#include "myNewApplication.h"
#include "NmyCamera.h"

namespace Nmy
{



	Collider::Collider()
		: Component(eComponentType::Collider)
		, mOffset(Vector2::Zero)
		, mPos(Vector2::Zero)
		, mScale(Vector2::One)
		, mCollisionCount(0)
	{
		mScale = Vector2(100.0f, 100.0f);
	}

	Collider::~Collider()
	{
	}

	void Collider::Tick()
	{
		Actor* owner = GetOwner();

		// 보통 오프셋은 센터이지만 거리로 설정하였음
		mPos = owner->GetPos() + mOffset;

	}

	void Collider::Render(HDC hdc)
	{
		HBRUSH gray = NewApplication::Getinstance().GetBrush(eBrushColor::Transparent);
		Brush brush(hdc, gray);

		HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldpen = NULL;

		Pen pen(hdc);

		if (mCollisionCount > 0)
		{
			oldpen = (HPEN)SelectObject(hdc, redPen);
		}
		else
		{
			oldpen = (HPEN)SelectObject(hdc, greenPen);
		}

		mPos = Camera::CalculatePos(mPos);

		// 스케일을 길이로 써버림
		Rectangle(hdc, mPos.x - (mScale.x / 2.0f)
			, mPos.y - (mScale.y / 2.0f)
			, mPos.x + (mScale.x / 2.0f)
			, mPos.y + (mScale.y / 2.0f));

		SelectObject(hdc, oldpen);
		DeleteObject(redPen);
		DeleteObject(greenPen);


	}

	void Collider::OnCollisionEnter(Collider* other)
	{
		mCollisionCount++;
		GetOwner()->OnCollisionEnter(other);

	}

	void Collider::OnCollisionStay(Collider* other)
	{
		GetOwner()->OnCollisionStay(other);
	}

	void Collider::OnCollisionExit(Collider* other)
	{
		mCollisionCount--;
		GetOwner()->OnCollisionExit(other);
	}

}