#include "Missile.h"
#include "Time.h"
#include "NmyCollider.h"
#include "NmyAnimator.h"
#include "NmyCamera.h"
#include "MyResources.h"
#include "Nmyimage.h"
#include "NmyInput.h"

namespace Nmy
{
	Missile::Missile()
		:mSpeed(1.0f)
		,mAliveTime(3.0f)
	{
		SetPos({ 100.0f ,100.0f });
		SetScale({ 20.0f ,20.0f });

		Collider* col = new Collider();
		col->SetScale(Vector2(20.0f, 20.0f));
		AddComponent(col);

		if (pimage == nullptr)
		{
			pimage = Resources::Load<image>(L"msiile" , L"..\\Resource\\Image\\msiile.bmp");
		}
		mDir = Vector2(0.0f, -1.0f);

	}

	Missile::~Missile()
	{
	}

	void Missile::Tick()
	{
		Actor::Tick();

		mAliveTime -= Time::DeltaTime();
		if (mAliveTime <= 0.0f)
		{
			this->Death();
		}


		float radian = math::DegreeToRadian(90.0f);
		float degree = math::RadianToDegree(2  * PI);

		// 삼각함수를 이용
		float speed = 300.0f;
		Vector2 pos = GetPos();

		//mDir = PI / 2.0f;
		//pos.x += speed * cosf(mDir) * Time::DeltaTime();
		//pos.y -= speed * sinf(mDir) * Time::DeltaTime();

		//Vector2 mousPos = Input::GetMousePos();
		//mDir = mousPos - pos;

		mDir.Normalize();

		// 벡터를 이용한 회전
		pos.y += mDir.y * speed * Time::DeltaTime();
		pos.x += mDir.x * speed * Time::DeltaTime();
		SetPos(pos);

	}

	void Missile::Render(HDC hdc)
	{

		Vector2 pos = GetPos();
		Vector2 mScale = GetScale();

		pos = Camera::CalculatePos(pos);

		Vector2 rect;
		rect.x = pimage->GetWidth();
		rect.y = pimage->GetHeight();

		TransparentBlt(hdc, pos.x, pos.y
			, rect.x, rect.y, pimage->GetDc()
			, 0, 0, pimage->GetWidth(), pimage->GetHeight()
			, RGB(255, 0, 255));


		Actor::Render(hdc);
	}

	void Missile::OnCollisionEnter(Collider* other)
	{
		Actor* actorObj = other->GetOwner();
		actorObj->Death();
		this->Death();

	}

	void Missile::OnCollisionStay(Collider* other)
	{
	}

	void Missile::OnCollisionExit(Collider* other)
	{
	}

}
