#pragma once
#include "NCommon.h"
#include "NmyScene.h"
#include "Drop.h"
#include <queue>


namespace Nmy
{
	class Scene;

	class DropManager
	{
	public:
		DropManager();
		~DropManager();

		static DropManager* GetDropManager() { return &dropmanager; }

		static void Initialize();
		static void Tick();
		static void Render(HDC hdc);
		static void Release();


	private:
		static DropManager dropmanager;
		static std::vector<Drop*> falldrop;
	};
}