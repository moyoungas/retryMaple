#include "SceneManager.h"
#include "NmyLogoScene.h"
#include "TitleScene.h"
#include "NmyPlayScene.h"
#include "NmyEndingScene.h"
#include "NmyObject.h"
#include "ToolScene.h"

namespace Nmy
{
	Scene* SceneManager::mScene[(UINT)eSceneType::MAX] = {};
	Scene* SceneManager::mPlayScene = nullptr;
	eSceneType SceneManager::mType = eSceneType::MAX;

	void SceneManager::Initialize()
	{
		mScene[(UINT)eSceneType::Tool] = new ToolScene;
		mScene[(UINT)eSceneType::Tool]->Initialize();
		// ��� ������ �ʱ�ȭ
		mScene[(UINT)eSceneType::Logo] = new LogoScene;
		mScene[(UINT)eSceneType::Logo]->Initialize();

		mScene[(UINT)eSceneType::Title] = new TitleScene;
		mScene[(UINT)eSceneType::Title]->Initialize();


		mScene[(UINT)eSceneType::Play] = new PlayScene;
		mScene[(UINT)eSceneType::Play]->Initialize();


		mScene[(UINT)eSceneType::End] = new EndScene;
		mScene[(UINT)eSceneType::End]->Initialize();


		ChangeScene(eSceneType::Logo);
		// �ڽ��� �θ�� ��ĳ����
		// �θ� �ڽ��� �ٿ�ĳ����
		//Scene* t = new LogoScene();
		//t->Initialize();
	}

	void SceneManager::Tick()
	{
		// ���� ���� ������Ʈ
		mPlayScene->Tick();
	}

	void SceneManager::Render(HDC hdc)
	{
		// ������� ������
		mPlayScene->Render(hdc);

	}

	void SceneManager::Release()
	{

		// ���α׷��� ����� �� �ѹ��� ȣ��
		for (Scene* scene : mScene)
		{
			if (scene == nullptr)
			{
				continue;
			}

			delete scene;
			scene = nullptr;
		}

	}

	void SceneManager::DestroyActor()
	{
		Nmy::obj::Release();
	}

	void SceneManager::ChangeScene(eSceneType aType)
	{
		if (mScene[(UINT)aType] == nullptr)
			return;
		mType = aType;

		mPlayScene->Exit();
		mPlayScene = mScene[(UINT)aType];
		mPlayScene->Enter();
	}

}


