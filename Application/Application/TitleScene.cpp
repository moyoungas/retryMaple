#include "TitleScene.h"
#include "MyResources.h"
#include "NmyInput.h"
#include "SceneManager.h"
#include "NmyBGActor.h"

namespace Nmy
{

	TitleScene::TitleScene()
	{
		


	}

	TitleScene::~TitleScene()
	{


	}

	void TitleScene::Enter()
	{
	}

	void TitleScene::Exit()
	{
	}


	void TitleScene::Initialize()
	{
		BGActor* bg = new BGActor();
		bg->SetImage(L"Logoimage", L"Logoimage.bmp");
		bg->Initialize();

		AddGameActor(bg,eColliderLayer::BackGround);

	}

	void TitleScene::Tick()
	{
		Scene::Tick();

		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeScene(eSceneType::Play);
		}

	}

	void TitleScene::Render(HDC hdc)
	{

		Scene::Render(hdc);
		wchar_t szFloat[50] = {};
		swprintf_s(szFloat, 50, L"Title");
		int strlen = wcsnlen_s(szFloat, 50);
		TextOut(hdc, 10, 30, szFloat, strlen);


	}
}


