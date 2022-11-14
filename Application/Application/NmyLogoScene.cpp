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

Nmy::LogoScene::LogoScene()
{
}

Nmy::LogoScene::~LogoScene()
{
}

void Nmy::LogoScene::Initialize()
{

	Nmy::obj::Instantiate<Player>(eColliderLayer::Player);
	mons[0] = Nmy::obj::Instantiate<Monster>(eColliderLayer::Monster);
	mons[1] = Nmy::obj::Instantiate<Monster>(Vector2{ 1600 / 2 + 130, 300 / 2 }, eColliderLayer::Monster);
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


}

void Nmy::LogoScene::Exit()
{
}
