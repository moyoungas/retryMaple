#pragma once
#include "NCommon.h"
#include "NmyEntity.h"
#include "NmyComponent.h"

namespace Nmy
{
	class Collider;

	class Actor : public Entity
	{
	public:
		Actor();
		Actor(Vector2 pos);
		virtual ~Actor();


		virtual void Initialize();
		virtual void Tick();
		virtual void Render(HDC hdc);

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);


		void SetPos(Vector2 pos) { mPos = pos; }
		Vector2 GetPos() { return mPos; }
		void SetScale(Vector2 pos) { mScale = pos; }
		Vector2 GetScale() { return mScale; }
		// 스케일에 따라 크기를 다르게 그릴것

		void Death() { mDead = true; }
		bool IsDeath() { return mDead; }
		void SetDeathTime(float time);

		void AddComponent(Component* component);

		template <typename T>
		__forceinline T* GetComponent()
		{
			T* component;
			for (Component* c : mComponents)
			{
				component = dynamic_cast<T*>(c);
				if(component != nullptr)
					return component;
			}
				return nullptr;
		}

		void DeathLoop();

	private:
		std::vector<Component*> mComponents;

		Vector2 mPos;
		Vector2 mScale;

		bool mDead;
		float mDeathTime;
		bool mDeathTimeOn;
	};


}

