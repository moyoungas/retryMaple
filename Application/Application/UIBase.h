#pragma once
#include "NmyEntity.h"

namespace Nmy
{
	class image;

	class UIBase : public Entity
	{


	public:

		struct Event
		{

			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}

			void operator()()
			{
				if (mEvent)
					mEvent();
			}

			std::function<void()> mEvent;
		};




		UIBase(eUIType type);
		virtual ~UIBase();

		// 처음 로드
		void Initialize(); // 메모리에 올라왔을 때

		// UI 켜질 때 마다 활성
		void Active();
		// UI가 비활성될 때 마다 
		void InActive();

		void Tick();
		void Render(HDC hdc);
		
		// UI를 메모리에서 삭제할 때
		void UIclear();

		void ImgLoad(const std::wstring& key, const std::wstring& path);
		void AddChild(UIBase* base);
		
		eUIType GetType() { return mType; }
		bool GetIsFullScreen() { return mbFullScreen; }
		void SetIsFullScreen(bool enable) { mbFullScreen = enable; }
		void SetParent(UIBase* base) { mParent = base; }

		void SetPos(Vector2 pos) { mPos = pos; }
		Vector2 GetPos() { return mPos; }

		void SetSize(Vector2 pos) { mSize = pos; }
		Vector2 GetSize() { return mSize; }

	protected:
		UIBase* mParent;
		image* mImage;
		Vector2 mPos;
		Vector2 mScreenPos;
		Vector2 mSize;

	private:

		virtual void OnInit() {}
		virtual void OnActive() {}
		virtual void OnInActive() {}
		virtual void OnTick() {}
		virtual void OnRender(HDC hdc) {}
		virtual void OnClear() {}

	private:
		eUIType mType;
		bool mbFullScreen;
		bool mbEnable;

		// 벡터가 메모리 친화적이기때문에 
		// 속도가 더 빨라서 벡터를 사용하였음
		std::vector<UIBase*> mChilds;


	};


}

