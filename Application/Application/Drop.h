#pragma once
#pragma once
#include "NCommon.h"
#include "Actor.h"

namespace Nmy
{

	class Drop : public Actor
	{
	public:
		Drop();
		~Drop();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;



	private:
		float mSpeed;

	};



}
