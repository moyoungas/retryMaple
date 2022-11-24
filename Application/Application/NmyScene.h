#pragma once
#include "NCommon.h"
#include "NmyEntity.h"



namespace Nmy
{
	class Actor;
	class Player;

	class Scene : public Entity 
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Tick();
		virtual void Render(HDC hdc);

		virtual void Enter();
		virtual void Exit();
		void AddGameActor(Actor* actor, eColliderLayer type);
		std::vector<std::vector<Actor*>>& GetActorObjects() { return mActor; }

		std::vector<Actor*>& GetActor(eColliderLayer type) { return mActor[(UINT)type]; }

		static Vector2 GetmLimited() { return mLimited; }

		static Player* aplayer;
	protected:
		static Vector2 mLimited;

	private:
		std::vector<std::vector<Actor*>> mActor;

	};
}

