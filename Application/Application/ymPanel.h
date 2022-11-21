#pragma once
#include "UIBase.h"


namespace Nmy
{


	class Panel : public UIBase
	{


	public:
		Panel(eUIType type);
		~Panel();


		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear()  override;

		void AddUIbase(UIBase* base);

	private:
		// 벡터가 메모리 친화적이기때문에 
		// 속도가 더 빨라서 벡터를 사용하였음
		std::vector<UIBase*> mChilds;



	};



}

