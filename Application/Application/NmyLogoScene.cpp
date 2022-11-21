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
#include "ymButton.h"

Nmy::LogoScene::LogoScene()
{
}

Nmy::LogoScene::~LogoScene()
{
}

void Nmy::LogoScene::Initialize()
{
	//BGActor* bg = new BGActor();
	//bg->SetImage(L"backimg", L"backGroundimg.bmp", L"..\\Resource\\MapleSprite\\back\\");
	//bg->Initialize();
	//AddGameActor(bg, eColliderLayer::BackGround);


	//Map* map = new Map();
	//map->SetImage(L"mapimg", L"PMAP1.bmp", L"..\\Resource\\MapleSprite\\Map\\");
	//map->Initialize();
	//AddGameActor(map, eColliderLayer::Map);



	Player* mplayer = Nmy::obj::Instantiate<Player>(eColliderLayer::Player);
	Mob* mMob = Nmy::obj::Instantiate<Mob>(eColliderLayer::Mob);
	Ground* ground = Nmy::obj::Instantiate<Ground>(eColliderLayer::Ground);
	ground->SetPos(Vector2(700.0f, 700.0f));




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
