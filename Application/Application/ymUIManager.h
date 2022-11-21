#pragma once
#include "NCommon.h"
#include "UIBase.h"

namespace Nmy
{


	class UIManager
	{
		// �÷��̾� ���ۿ� ����x (��ġ , ũ��)
		// ��üȭ�� ui
		// �⺻ ui
		// HUD �̹����� ������ �ִ� ui
		// �������� �����͸� �����Ѵ�.
		// ��ư
		// �� ui �� �ڽı����� �������� �ٸ� ui���� �����ؼ�
		// ���� �����̴� �ϳ��� ū ui�� �� �� �ִ�.

	public:

		static void Initialize();
		static void Tick();
		static void Render(HDC hdc);

		static void OnLoad(eUIType type);
		static void OnComplete(UIBase* addUI);
		static void OnFail();

		static void Push(eUIType type);
		static void Pop(eUIType type);

		static void Release();


		template<typename T>
		static T* GetUiInstant(eUIType type)
		{
			return dynamic_cast<T*>(mUIs[type]);
		}




	private:
		// ���ľ��� map 
		static std::unordered_map<eUIType, UIBase*> mUIs;
		static std::queue<eUIType> mRequestUIQueue;
		static std::stack<UIBase*> mUIBase;
		static UIBase* mCurrentData;
	};


}
