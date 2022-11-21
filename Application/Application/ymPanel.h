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
		// ���Ͱ� �޸� ģȭ���̱⶧���� 
		// �ӵ��� �� ���� ���͸� ����Ͽ���
		std::vector<UIBase*> mChilds;



	};



}

