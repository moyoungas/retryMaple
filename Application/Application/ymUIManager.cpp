#include "ymUIManager.h"
#include "UIBase.h"
#include "ymHUD.h"
#include "ymButton.h"
#include "ymPanel.h"

namespace Nmy
{

	std::unordered_map<eUIType, UIBase*> UIManager::mUIs;
	std::queue<eUIType> UIManager::mRequestUIQueue;
	std::stack<UIBase*> UIManager::mUIBase;
	UIBase* UIManager::mCurrentData = nullptr;

	void UIManager::Initialize()
	{
		Button* button = new Button(eUIType::HP);
		mUIs.insert(std::make_pair(eUIType::HP, button));
		button->SetPos(Vector2::Zero);
		//newUI->SetSize(Vector2(100.0f, 100.0f));
		button->ImgLoad(L"HPbar", L"..\\Resource\\Image\\HPBAR.bmp");

		HUD* newUI = new HUD(eUIType::MP);
		mUIs.insert(std::make_pair(eUIType::MP, newUI));
		newUI->SetPos(Vector2(0.0f,100.0f));
		newUI->ImgLoad(L"HPbar", L"..\\Resource\\Image\\HPBAR.bmp");


		Panel* panel = new Panel(eUIType::Inventory);
		mUIs.insert(std::make_pair(eUIType::Inventory, panel));
		panel->ImgLoad(L"BackPack", L"..\\Resource\\Image\\BackPack.bmp");
		panel->SetPos(Vector2(100.0f, 500.0f));
		panel->AddChild(button);
		panel->AddChild(newUI);
	}

	void UIManager::Tick()
	{

		std::stack<UIBase*> uiBase = mUIBase;
		while (!uiBase.empty())
		{
			UIBase* uiBases = uiBase.top();

			if (uiBases != nullptr)
			{
				uiBases->Tick();

			}
			uiBase.pop();
		}


		if (mRequestUIQueue.size() > 0)
		{
			eUIType requestUi = mRequestUIQueue.front();
			mRequestUIQueue.pop();
			// ui로드
			OnLoad(requestUi);
		}
	}

	void UIManager::Render(HDC hdc)
	{
		std::stack<UIBase*> uiBases = mUIBase;
		std::stack<UIBase*> tempStack;

		// 뒤집어서 렌더링을 해준다.
		while (!uiBases.empty())
		{
			UIBase* uiBase = uiBases.top();
			tempStack.push(uiBase);
			uiBases.pop();
		}

		while (!tempStack.empty())
		{
			UIBase* uiBase = tempStack.top();
			if (uiBase != nullptr)
			{
				uiBase->Render(hdc);
			}
			tempStack.pop();
		}


	}

	void UIManager::OnLoad(eUIType type)
	{
		std::unordered_map<eUIType, UIBase*>::iterator iter = mUIs.find(type);
		if (iter == mUIs.end())
		{
			OnFail();
			return;
		}
		OnComplete(iter->second);
	}

	void UIManager::OnComplete(UIBase* addUI)
	{
		if (addUI == nullptr)
			return;

		addUI->Initialize();
		addUI->Active();
		addUI->Tick();

		if (addUI->GetIsFullScreen())
		{
			// 스택은 for문 불가 
			// 스택은 한개씩 밖에 할 수 없음
			std::stack<UIBase*> uiBase = mUIBase;
			while (!uiBase.empty())
			{
				UIBase* uiBases = uiBase.top();
				uiBase.pop();

				if (uiBases->GetIsFullScreen())
				{
					uiBases->InActive();

				}
			}
		}

		mUIBase.push(addUI);
	}

	void UIManager::OnFail()
	{
		mCurrentData = nullptr;
	}

	void UIManager::Push(eUIType type)
	{
		mRequestUIQueue.push(type);
	}

	void UIManager::Pop(eUIType type)
	{
		if (mUIBase.size() <= 0)
			return;

		std::stack<UIBase*> tempstack;

		UIBase* uiBase = nullptr;
		while (mUIBase.size() > 0)
		{
			uiBase = mUIBase.top();
			mUIBase.pop();
			// pop하는 ui가 전체화면일 경우
			// 남은 ui중에 전체화면인 가장 상단의 ui를 활성화 해주어야 한다.

			if (uiBase->GetType() == type)
			{
				if (uiBase->GetIsFullScreen())
				{
					std::stack<UIBase*> uiBase = mUIBase;
					while (!uiBase.empty())
					{
						UIBase* uiBases = uiBase.top();
						uiBase.pop();

						if (uiBases->GetIsFullScreen())
						{
							uiBases->Active();
							break;
						}
					}
				}
				uiBase->InActive();
				uiBase->UIclear();
			}

			else
			{
				tempstack.push(uiBase);
			}
		}

		while (tempstack.size())
		{
			uiBase = tempstack.top();
			tempstack.pop();
			mUIBase.push(uiBase);
		}
	}

	void UIManager::Release()
	{
		for (auto ui : mUIs )
		{
			delete ui.second;


		}
	}



}