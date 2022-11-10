#include "DropManager.h"
#include "Drop.h"
#include "SceneManager.h"
#include <time.h>

namespace Nmy
{
	std::vector<Drop*> DropManager::falldrop;
	DropManager DropManager::dropmanager;

	DropManager::DropManager()
	{
		srand((unsigned int)time(NULL));
	}
	DropManager::~DropManager()
	{


	}
	void DropManager::Initialize()
	{
		//Drop* mdrop = new Drop();
		//mdrop->SetPos({ (float)(rand() % 1921) , -1 });
		//Scene* playScene = SceneManager::GetPlayScene();
		//playScene->AddGameActor(mdrop);
		//falldrop.push_back(mdrop);
	}

	void DropManager::Tick()
	{
		for (Drop* mDrop : falldrop)
		{
			mDrop->Tick();
		}

	}

	void DropManager::Render(HDC hdc)
	{
		for (Drop* mDrop : falldrop)
		{
			mDrop->Render(hdc);
		}
	}

	void DropManager::Release()
	{


	}

}