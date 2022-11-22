#include "NmyLogoScene.h"
#include "Player.h"
#include "NmyInput.h"
#include "SceneManager.h"
#include "NmyBGActor.h"
#include "NmyMonster.h"
#include "ColliderManager.h"
#include "NmyBacKPack.h"
#include "NmyObject.h"
#include "myNewApplication.h"
#include "NmyMob.h"
#include "ymMap.h"
#include "ymRigidBody.h"
#include "ymGround.h"
#include "ymUIManager.h"
#include "ymHUD.h"
#include "NmyCamera.h"
#include "ymButton.h"


namespace Nmy
{
	Vector2 LogoScene::mLimited;


}

Nmy::LogoScene::LogoScene()
{
}

Nmy::LogoScene::~LogoScene()
{
}

void Nmy::LogoScene::Initialize()
{
	BGActor* bg = new BGActor();
	bg->SetImage(L"backimg", L"backGroundimg.bmp", L"..\\Resource\\MapleSprite\\back\\");
	bg->Initialize();
	AddGameActor(bg, eColliderLayer::BackGround);


	Map* mMap = new Map();
	mMap->SetImage(L"mapimg", L"StartMap.bmp", L"..\\Resource\\MapleSprite\\Map\\");
	mMap->Initialize();
	AddGameActor(mMap, eColliderLayer::Map);

	Vector2 mSaveMap = mMap->GetImageWidth();
	mLimited = mSaveMap;

	Player* mplayer = Nmy::obj::Instantiate<Player>(eColliderLayer::Player);
	Mob* mMob = Nmy::obj::Instantiate<Mob>(eColliderLayer::Mob);

	Ground* ground = Nmy::obj::Instantiate<Ground>(eColliderLayer::Ground);
	Ground* ground2 = Nmy::obj::Instantiate<Ground>(eColliderLayer::Ground);
	ground->SetPos(Vector2(1100.0f, 1100.0f));
	ground2->SetPos(Vector2(1000.0f, 1550.0f));


	UIManager::Push(eUIType::Inventory);
	//Button* hp = UIManager::GetUiInstant<Button>(eUIType::HP);
	HUD* hp = UIManager::GetUiInstant<HUD>(eUIType::MP);
	hp->SetTarget(mplayer);
}

void Nmy::LogoScene::Tick()
{
	// 오브젝트 tick을 호출
	// 부모것을 호출하고 자기것을 작업하자
	// 유니티에선 막아둠
	Scene::Tick();


	if (KEY_DOWN(eKeyCode::N))
	{
		SceneManager::ChangeScene(eSceneType::Title);
	}

	//Nmy::obj::Destory(mons[0], 3.0f);

}

void Nmy::LogoScene::Render(HDC hdc)
{
	Scene::Render(hdc);

}

void Nmy::LogoScene::Enter()
{


	ColliderManager::SetLayer(eColliderLayer::Monster, eColliderLayer::Player, true);
	ColliderManager::SetLayer(eColliderLayer::Monster, eColliderLayer::Player_Projecttile, true);
	ColliderManager::SetLayer(eColliderLayer::Ground, eColliderLayer::Player, true);
	ColliderManager::SetLayer(eColliderLayer::Ground, eColliderLayer::Mob, true);


}

void Nmy::LogoScene::Exit()
{
}
