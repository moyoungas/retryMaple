#pragma once
#include "NmyScene.h"
#include "Actor.h"
#include "SceneManager.h"

namespace Nmy
{

	namespace obj
	{

		template <typename T>
		static __forceinline T* Instantiate(eColliderLayer type)
		{
			T* actor = new T();
			Scene* scene = SceneManager::GetPlayScene();
			scene->AddGameActor(dynamic_cast<Actor*>(actor), type);

			return actor;
		}

		template <typename T>
		static __forceinline T* Instantiate(Vector2 pos,eColliderLayer type)
		{
			T* actor = new T(pos);
			Scene* scene = SceneManager::GetPlayScene();
			scene->AddGameActor(dynamic_cast<Actor*>(actor), type);

			return actor;
		}




		static __forceinline void Destory(Actor* actor)
		{
			actor->Death();
		}
		// 시간 측정해서 지우기
		static __forceinline void Destory(Actor* actor , float time)
		{
			actor->SetDeathTime(time);
		}

		static __forceinline void Release()
		{

			Scene* scene = SceneManager::GetPlayScene();
			std::vector<std::vector<Actor*>> mobj = scene->GetActorObjects();

			for (size_t y = 0; y < _COLLIDER_LAYER; y++)
			{
				for (std::vector<Actor*>::iterator iter = mobj[y].begin(); iter != mobj[y].end();)
				{

					if ((*iter)->IsDeath() == true)
					{
						iter = mobj[y].erase(iter);
						continue;
					}
					++iter;
				}
			}
		}






	}








}