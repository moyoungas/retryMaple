#include "Drop.h"
#include "Time.h"

namespace Nmy
{

	Drop::Drop()
		: mSpeed(1.0f)
	{
		SetPos({ (float)(rand() % 1921) , 10.0f });
		SetScale({ 50.0f,50.0f });
	}

	Drop::~Drop()
	{

	}


	void Drop::Tick()
	{
		Vector2 pos = GetPos();
		pos.y += 520 * Time::DeltaTime();
		SetPos(pos);
	}

	void Drop::Render(HDC hdc)
	{
		HPEN colorPen = CreatePen(PS_SOLID, 2, RGB(rand() % 256, rand() % 256, rand() % 256));
		Pen pen(hdc, colorPen);

		HBRUSH blackBrush = CreateSolidBrush(RGB(0, 0, 0));
		Brush brush(hdc, blackBrush);

		Vector2 pos = GetPos();
		Vector2 mScale = GetScale();

		Ellipse(hdc, pos.x, pos.y, pos.x + mScale.x, pos.y + mScale.y);
	}

}

