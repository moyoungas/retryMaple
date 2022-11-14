#include "NmyPlayScene.h"
#include "Player.h"
#include "NmyInput.h"
#include "SceneManager.h"
#include "NmyBGActor.h"

namespace Nmy
{
	void PlayScene::Initialize()
	{

		BGActor* bg = new BGActor();
		bg->SetImage(L"backGroundMap", L"backGroundMap.bmp");
		bg->Initialize();

		AddGameActor(bg, eColliderLayer::BackGround);
	}
	void PlayScene::Tick()
	{
		Scene::Tick();

		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeScene(eSceneType::End);
		}


	}
	void PlayScene::Render(HDC hdc)
	{

		wchar_t szFloat[50] = {};
		swprintf_s(szFloat, 50, L"PlayScene");
		int strlen = wcsnlen_s(szFloat, 50);
		TextOut(hdc, 10, 30, szFloat, strlen);
		Scene::Render(hdc);
	}
	void PlayScene::Enter()
	{



	}
	void PlayScene::Exit()
	{
	}
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
}