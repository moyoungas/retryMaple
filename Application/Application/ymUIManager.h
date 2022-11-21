#pragma once
#include "NCommon.h"
#include "UIBase.h"

namespace Nmy
{


	class UIManager
	{
		// 플레이어 조작에 영향x (위치 , 크기)
		// 전체화면 ui
		// 기본 ui
		// HUD 이미지와 정보만 있는 ui
		// 스택으로 데이터를 관리한다.
		// 버튼
		// 내 ui 내 자식구조로 여러가지 다른 ui들을 구성해서
		// 같이 움직이는 하나의 큰 ui도 될 수 있다.

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
		// 정렬없는 map 
		static std::unordered_map<eUIType, UIBase*> mUIs;
		static std::queue<eUIType> mRequestUIQueue;
		static std::stack<UIBase*> mUIBase;
		static UIBase* mCurrentData;
	};


}
