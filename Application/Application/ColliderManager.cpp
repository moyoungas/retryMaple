#include "ColliderManager.h"
#include "SceneManager.h"
#include "NmyCollider.h"
#include "Actor.h"
#include "NmyScene.h"
#include "NmyComponent.h"

namespace Nmy
{
	WORD ColliderManager::mMatrix[_COLLIDER_LAYER] = {};


	std::map<UINT64, bool> ColliderManager::mCollisionInfo;

	void ColliderManager::Tick()
	{
		Scene* playScene = SceneManager::GetPlayScene();

		for (size_t row = 0; row < _COLLIDER_LAYER; row++)
		{
			for (size_t col = 0; col < _COLLIDER_LAYER; col++)
			{
 				if (mMatrix[row] & (1 << col))
				{
					// �浹 �� �Ǿ����� �ȵǾ������� �˻������ �Ѵ�.
					LayerCollision(playScene, (eColliderLayer)row, (eColliderLayer)col);
				}
			}
		}
	}

	void ColliderManager::SetLayer(eColliderLayer left, eColliderLayer right, bool value)
	{
		// �� ���� ���ڸ� �� �� ū���ڸ� ����
		UINT row = 0;
		UINT col = 0;

		UINT iLeft = (UINT)left;
		UINT iRight = (UINT)right;

		if (iLeft < iRight)
		{
			row = (UINT)left;
			col = (UINT)right;
		}
		else
		{
			row = (UINT)right;
			col = (UINT)left;
		}

		if (value == true)
			mMatrix[row] |= (1 << col);
		else
			mMatrix[row] &= ~(1 << col);
	}

	void ColliderManager::LayerCollision(Scene* scene, eColliderLayer left, eColliderLayer right)
	{
		// ��� left ������Ʈ��� right ���� �����ͼ� ������� �Ѵ�.
		std::vector<Actor*>& lefts = scene->GetActor(left);
		std::vector<Actor*>& rights = scene->GetActor(right);

		for (auto leftObject : lefts)
		{
			Collider* leftCollider = leftObject->GetComponent<Collider>();

			if (leftCollider == nullptr)
				continue;

			for (auto rightObject : rights)
			{
				Collider* rightCollider = rightObject->GetComponent<Collider>();

				if (rightCollider == nullptr)
					continue;

				if (leftCollider == rightCollider)
					continue;

				ColliderCollision(leftCollider, rightCollider);
 			}
		}
	}

	void ColliderManager::ColliderCollision(Collider* left, Collider* right)
	{

		// �� �浹ü�� layer���� Ȯ�����ش�.
		ColliderID id;
		id.left = left->GetId();
		id.right = right->GetId();

		// ã�� ���� ���ٸ� end�� ��ȯ
		std::map<UINT64, bool>::iterator iter
			= mCollisionInfo.find(id.ID);

		// �浹������ ���ٸ� �浹���� ��������
		if (iter == mCollisionInfo.end())
		{
			mCollisionInfo.insert(std::make_pair(id.ID, false));
			iter = mCollisionInfo.find(id.ID);
		}

		if (Intersect(left,right))
		{
			//�浹 ��

			if (iter->second == false)
			{
				//���� �ѹ� �浹
				// �浹�Լ� ȣ��

				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);

				iter->second = true;
			
			}
			else
			{
				//�浹 �� �϶�
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}
		else
		{
			// �浹 x
			if (iter->second)
			{
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);

				iter->second = false;

			}
		}

	}

	bool ColliderManager::Intersect(Collider* left, Collider* right)
	{
		// �޸𸮿��� ��������
		if (left->GetOwner()->IsDeath())
			return false;
		if (right->GetOwner()->IsDeath())
			return false;

		Vector2 leftPos = left->GetPos();
		Vector2 leftScale = left->GetScale();

		Vector2 rightPos = right->GetPos();
		Vector2 rightScale = right->GetScale();


		if (fabs(leftPos.x - rightPos.x) < fabs(leftScale.x / 2.0f + rightScale.x / 2.0f)
			&& fabs(leftPos.y - rightPos.y) < fabs(leftScale.y / 2.0f + rightScale.y / 2.0f))
		{
			return true;
		}

		return false;
	}
}