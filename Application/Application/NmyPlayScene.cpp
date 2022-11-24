#include "NmyPlayScene.h"
#include "Player.h"
#include "NmyInput.h"
#include "SceneManager.h"
#include "NmyBGActor.h"

#include "NmyMob.h"
#include "ymMap.h"
#include "ymRigidBody.h"
#include "NmyObject.h"
#include "ColliderManager.h"


namespace Nmy
{

	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		BGActor* bg = new BGActor();
		bg->SetImage(L"backimg", L"backGroundimg.bmp", L"..\\Resource\\MapleSprite\\back\\");
		bg->Initialize();
		AddGameActor(bg, eColliderLayer::BackGround);

		Scene::aplayer = Nmy::obj::Instantiate<Player>(eColliderLayer::Player);


		Mob* mMob = Nmy::obj::Instantiate<Mob>(eColliderLayer::Mob);

		Map* mMap = new Map();
		//mMap->SetImage(L"mapimg", L"StartMap.bmp", L"..\\Resource\\MapleSprite\\Map\\");
		mMap->SetImage(L"StartMap1", L"StartMap.bmp", L"..\\Resource\\MapleSprite\\Map\\");
		mMap->SetPixelImage(L"pixel", L"StartMapTest.bmp", L"..\\Resource\\MapleSprite\\Map\\");
		mMap->SetPlayer(aplayer);
		mMap->SetMob(mMob);
		AddGameActor(mMap, eColliderLayer::Map);


		Vector2 mSaveMap = mMap->GetImageVolume();
		Scene::mLimited = mSaveMap;

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

		Scene::Render(hdc);
	}
	void PlayScene::Enter()
	{


		ColliderManager::SetLayer(eColliderLayer::Mob, eColliderLayer::Player, true);
		ColliderManager::SetLayer(eColliderLayer::Mob, eColliderLayer::Player_Projecttile, true);



	}
	void PlayScene::Exit()
	{
	}

}