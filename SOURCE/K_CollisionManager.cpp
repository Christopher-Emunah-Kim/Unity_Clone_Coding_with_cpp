#include "K_CollisionManager.h"
#include "K_Scene.h"
#include "K_SceneManager.h"
#include "K_TransformComp.h"

namespace KHS
{
	std::bitset<( UINT ) ELayerType::MAX> CollisionManager::m_collisionMatrix[ ( UINT ) ELayerType::MAX ] = {};
	std::unordered_map<UINT64 , bool> CollisionManager::m_collisionMap = {};

	void CollisionManager::Initialize()
	{
	}

	void CollisionManager::Update()
	{
		Scene* currentScene = SceneManager::GetActiveScene();

		//Check Collision between Layers
		for(UINT row = 0; row < ( UINT ) ELayerType::MAX; ++row)
		{
			for(UINT col = row; col < ( UINT ) ELayerType::MAX; ++col)
			{
				if(m_collisionMatrix[row][col])
				{
					LayerCollision(currentScene , ( ELayerType ) row , ( ELayerType ) col);
				}
			}
		}
	}

	void CollisionManager::LateUpdate()
	{
	}

	void CollisionManager::Render(HDC hdc)
	{
	}


	void CollisionManager::CollisionLayerCheck(ELayerType left , ELayerType right , bool enable)
	{
		int row = 0;
		int col = 0;

		if ( left <= right )
		{
			row = ( UINT ) left;
			col = ( UINT ) right;
		}
		else
		{
			row = ( UINT ) right;
			col = ( UINT ) left;
		}

		m_collisionMatrix[ row ][ col ] = enable;
	}
	void CollisionManager::LayerCollision(Scene* scene , ELayerType left , ELayerType right)
	{
		const std::vector<GameObject*> leftObjects = scene->GetLayer(left)->GetGameObjects();
		const std::vector<GameObject*> rightObjects = scene->GetLayer(right)->GetGameObjects();

		for ( GameObject* left : leftObjects )
		{
			if ( left->IsActive() == false )
			{
				continue;
			}

			ColliderComp* leftCollider = left->GetComponent<ColliderComp>();
			if( leftCollider == nullptr )
			{
				continue;
			}

			for ( GameObject* right : rightObjects )
			{
				if ( right->IsActive() == false )
				{
					continue;
				}

				ColliderComp* rightCollider = right->GetComponent<ColliderComp>();
				if( rightCollider == nullptr )
				{
					continue;
				}

				ColliderCollisionCheck(leftCollider , rightCollider);
			}
		}

	}
	void CollisionManager::ColliderCollisionCheck(ColliderComp* left , ColliderComp* right)
	{
		//Generate Unique Collision ID
		CollisionID collisionID = {};
		collisionID.left = left->GetColliderID();
		collisionID.right = right->GetColliderID();

		//Check Existed Collision Info.
		auto iter = m_collisionMap.find(collisionID.id);
		if ( iter == m_collisionMap.end() )
		{
			m_collisionMap.insert(std::make_pair(collisionID.id , false));
			iter = m_collisionMap.find(collisionID.id);
		}

		//Collision Check
		if ( IntersectAABB(left , right) )
		{
			if ( iter->second == false ) // First Collision
			{
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);
				iter->second = true;
			}
			else // Continuing Collision
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}
		else
		{
			//No Collsion
			if(iter->second == true) // Collision Ended
			{
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);
				iter->second = false;
			}
		}
		
	}
	bool CollisionManager::IntersectAABB(ColliderComp* left , ColliderComp* right)
	{
		TransformComp* leftTr = left->GetOwner()->GetComponent<TransformComp>();
		TransformComp* rightTr = right->GetOwner()->GetComponent<TransformComp>();

		Vector2D leftPos = leftTr->GetPosition() + left->GetOffset();
		Vector2D rightPos = rightTr->GetPosition() + right->GetOffset();

		//size 1일때 100픽셀 크기
		Vector2D leftSize = left->GetSize() * 100.0f;
		Vector2D rightSize = right->GetSize() * 100.0f;

		//AABB Collision Check
		//Check X axis and Y axis overlap
		if(fabs(leftPos.x - rightPos.x) <= ( leftSize.x * 0.5f + rightSize.x * 0.5f ) &&
		   fabs(leftPos.y - rightPos.y) <= ( leftSize.y * 0.5f + rightSize.y * 0.5f ))
		{
			return true;
		}

		return false;
	}
}