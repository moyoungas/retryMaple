#include "NmyPlay2Scene.h"
#include "NmyBGActor.h"

#include "NmyPlayScene.h"
#include "NmyMob.h"
#include "ymMap.h"
#include "ymRigidBody.h"
#include "NmyObject.h"
#include "ColliderManager.h"
#include "Player.h"


namespace Nmy
{
	Play2Scene::Play2Scene()
	{
	}
	Play2Scene::~Play2Scene()
	{
	}
	void Play2Scene::Initialize()
	{
		mPlayer = aplayer;
		AddGameActor(mPlayer, eColliderLayer::Player);

		BGActor* bg = new BGActor();
		bg->SetImage(L"backimg2", L"backGroundimg.bmp", L"..\\Resource\\MapleSprite\\back\\");
		bg->Initialize();
		AddGameActor(bg, eColliderLayer::BackGround);

		Map* mMap = new Map();
		////mMap->SetImage(L"mapimg", L"StartMap.bmp", L"..\\Resource\\MapleSprite\\Map\\");
		mMap->SetImage(L"StartMap2", L"StartMap2.bmp", L"..\\Resource\\MapleSprite\\Map\\");
		mMap->SetPixelImage(L"pixel2", L"StartMapSecondPixel.bmp", L"..\\Resource\\MapleSprite\\Map\\");
		mMap->SetMob(mMob);
		mMap->SetPlayer(aplayer);
		AddGameActor(mMap, eColliderLayer::Map);
		restMap = mMap;



	}
	void Play2Scene::Tick()
	{
		Scene::Tick();
	}
	void Play2Scene::Render(HDC hdc)
	{
		Scene::Render(hdc);

	}
	void Play2Scene::Enter()
	{
		memset(&mLimited,0,sizeof(mLimited));
		Vector2 mSaveMap = restMap->GetImageVolume();
		Scene::mLimited = mSaveMap;

		mPlayer->SetPos(Vector2(200,600));
	


		ColliderManager::SetLayer(eColliderLayer::Portal, eColliderLayer::Player, true);

	}
	void Play2Scene::Exit()
	{

	}
}