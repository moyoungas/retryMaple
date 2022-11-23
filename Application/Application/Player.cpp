#include "Player.h"
#include "Time.h"
#include "NmyInput.h"
#include "SceneManager.h"
#include "Missile.h"
#include "NmyScene.h"
#include "Nmyimage.h"
#include "MyResources.h"
#include "NmyAnimator.h"
#include "NmyCollider.h"
#include "NmyCamera.h"
#include "NmyBacKPack.h"
#include "ymUIManager.h"
#include "ymRigidBody.h"

Nmy::Player::Player() 
	: mSpeed(1.0f)
	, mHp(100)
	, isJump(false)
{
	SetPos({ 900.0f, 100.0f });
	SetPlayerPos({ 900.0f, 100.0f });
	SetScale({ 1.0f, 1.0f });
	mCoff = 0.1f;

	if (pImage == nullptr)
	{
		
		// ���⼭ ��� �Է½� �� ������ �ִ� ��ο� �ε带 ��
		// �׷��Ƿ� ..�� �ٿ� �������� ���� �� 
		pImage = Resources::Load<image>(L"Player", L"..\\Resource\\Image\\link.bmp");
	}

	mAnimator = new Animator();
	//mAnimator->CreateAnimations(L"..\\Resource\\Animation\\Player\\Idle"
	//	, L"PlaneIdle");

	mAnimator->CreateAnimation(L"Idle", pImage
		, Vector2(0.0f, 0.0f), Vector2(120.0f, 130.0f)
		, Vector2(5.0f, -20.0f), 3, 0.1f);


	mAnimator->CreateAnimation(L"MoveDown", pImage
		, Vector2(0.0f, 520.0f), Vector2(120.0f, 130.0f)
		, Vector2(5.0f, -20.0f), 10, 0.1f);


	mAnimator->CreateAnimation(L"MoveLeft", pImage
		, Vector2(0.0f, 650.0f), Vector2(120.0f, 130.0f)
		, Vector2(5.0f, -20.0f), 10, 0.1f);

	mAnimator->CreateAnimation(L"MoveUP", pImage
		, Vector2(0.0f, 780.0f), Vector2(120.0f, 130.0f)
		, Vector2(5.0f, -20.0f), 10, 0.1f);


	mAnimator->CreateAnimation(L"MoveRight", pImage
		, Vector2(0.0f, 910.0f), Vector2(120.0f, 130.0f)
		, Vector2(5.0f, -20.0f), 10, 0.1f);

	mAnimator->Play(L"Idle", true);/*
	mAnimator->FindEvents(L"MoveRight")->mCompleteEvent = std::bind(&Player::WalkComplete, this);*/
	mAnimator->GetCompleteEvents(L"MoveRight") = std::bind(&Player::WalkComplete, this);

	AddComponent(mAnimator);

	Collider* coliider = new Collider();
	AddComponent(coliider);

	coliider->SetOffset(Vector2(0.0f, 50.0f));
	coliider->SetScale(Vector2(10.0f, 10.0f));

	Collider* coliider2 = new Collider();
	AddComponent(coliider2);

	coliider2->SetOffset(Vector2(50.0f, 0.0f));
	coliider2->SetScale(Vector2(10.0f, 10.0f));

	Collider* coliider3 = new Collider();
	AddComponent(coliider3);

	coliider3->SetOffset(Vector2(-20.0f, 0.0f));
	coliider3->SetScale(Vector2(10.0f, 10.0f));

	AddComponent<RigidBody>();
	Camera::SetTarget(this);

	mCoff = 0.1f;
	mMissileDir = Vector2::One;

}

Nmy::Player::~Player()
{
}


void Nmy::Player::Tick()
{

	Actor::Tick();

	Vector2 pos = GetPos();

	if (KEY_PRESSED(eKeyCode::W))
	{
		pos.y -= 200.0f * Time::DeltaTime();
		//GetComponent<RigidBody>()->AddForce(Vector2(0.0f, -1000.0f));
	}
	if (KEY_PRESSED(eKeyCode::S))
	{
		pos.y += 200.0f * Time::DeltaTime();
		//GetComponent<RigidBody>()->AddForce(Vector2(0.0f, 1000.0f));
	}
	if (KEY_PRESSED(eKeyCode::A))
	{
		pos.x -= 200.0f * Time::DeltaTime();
		//GetComponent<RigidBody>()->AddForce(Vector2(-1000.0f, 0.0f));
	}
	if (KEY_PRESSED(eKeyCode::D))
	{
		pos.x += 200.0f * Time::DeltaTime();
		// ���� ���
		//GetComponent<RigidBody>()->AddForce(Vector2(3000.0f, 0.0f));
		//GetComponent<RigidBody>()->AddForce(Vector2(1000.0f, 0.0f));
	}

	if (KEY_DOWN(eKeyCode::W))
	{
		mAnimator->Play(L"MoveUP", true);
	}
	if (KEY_DOWN(eKeyCode::S))
	{
		mAnimator->Play(L"MoveDown", true);
	}
	if (KEY_DOWN(eKeyCode::A))
	{
		mAnimator->Play(L"MoveLeft", true);
	}
	if (KEY_DOWN(eKeyCode::D))
	{
		mAnimator->Play(L"MoveRight", true);
	}

	if (KEY_UP(eKeyCode::W))
	{
		mAnimator->Play(L"Idle", true);
	}
	if (KEY_UP(eKeyCode::S))
	{
		mAnimator->Play(L"Idle", true);
	}
	if (KEY_UP(eKeyCode::A))
	{
		mAnimator->Play(L"Idle", true);
	}
	if (KEY_UP(eKeyCode::D))
	{
		mAnimator->Play(L"Idle", true);
	}


	if (KEY_DOWN(eKeyCode::SPACE))
	{

		RigidBody* rigidy = GetComponent<RigidBody>();
		Vector2 velocity = rigidy->GetVelocity();
		
		if (rigidy->GetGround())
		{
			velocity.y = -500.0f;
			rigidy->SetVelocity(velocity);
			rigidy->SetGround(false);
		}

	}

	if (KEY_PRESSED(eKeyCode::LBTN))
	{

		if (true)
		{

			Missile* missile = new Missile();
			Scene* playScene = SceneManager::GetPlayScene();

			playScene->AddGameActor(missile, eColliderLayer::Player_Projecttile);

			Vector2 playerPos = GetPos();
			Vector2 playerScale = GetScale() / 2.0f;

			missile->SetPos(playerPos);
			missile->mDestPos = Vector2::One;
			//missile->mDir = missile->mDestPos - pos;

			mMissileDir = math::Rotate(mMissileDir, 5.0f);
			missile->mDir = mMissileDir;
		}



	}

	if (KEY_DOWN(eKeyCode::K))
	{

	}

	if (KEY_DOWN(eKeyCode::I))
	{
		BackPack* backpack = new BackPack();
		Scene* playScene = SceneManager::GetPlayScene();
		playScene->AddGameActor(backpack, eColliderLayer::BACKPACK);
	}
	SetPos(pos);
}

void Nmy::Player::Render(HDC hdc)
{




	Actor::Render(hdc);
}

void Nmy::Player::OnCollisionEnter(Collider* other)
{

}

void Nmy::Player::OnCollisionStay(Collider* other)
{
}

void Nmy::Player::OnCollisionExit(Collider* other)
{

}
void Nmy::Player::WalkComplete()
{
	Missile* missile = new Missile();
	Scene* playScene = SceneManager::GetPlayScene();

	playScene->AddGameActor(missile, eColliderLayer::Player_Projecttile);

	Vector2 playerPos = GetPos();
	Vector2 playerScale = GetScale() / 2.0f;
	Vector2 missileScale = missile->GetScale();

	missile->SetPos((playerPos + playerScale) - (missileScale / 2.0f));
}