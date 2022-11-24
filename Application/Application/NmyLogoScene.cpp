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
#include "Time.h"
#include "ymWarrior.h"
#include "ymPortal.h"


namespace Nmy
{


}

Nmy::LogoScene::LogoScene()
	:maTime(0.0f)
{
}

Nmy::LogoScene::~LogoScene()
{
}

void Nmy::LogoScene::Initialize()
{

	BGActor* bg = new BGActor();
	bg->SetImage(L"Logoimage", L"Logoimage.bmp");
	bg->Initialize();
	AddGameActor(bg, eColliderLayer::BackGround);


	//UIManager::Push(eUIType::Inventory);
	////Button* hp = UIManager::GetUiInstant<Button>(eUIType::HP);
	//HUD* hp = UIManager::GetUiInstant<HUD>(eUIType::MP);
	//hp->SetTarget(aplayer);
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


	ColliderManager::SetLayer(eColliderLayer::Mob, eColliderLayer::Player, true);
	ColliderManager::SetLayer(eColliderLayer::Mob, eColliderLayer::Player_Projecttile, true);


}

void Nmy::LogoScene::Exit()
{
}
