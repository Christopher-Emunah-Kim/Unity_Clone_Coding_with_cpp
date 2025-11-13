#include "K_CollisionManager.h"
#include "K_Scene.h"
#include "K_SceneManager.h"

namespace KHS
{
	std::bitset<( UINT ) ELayerType::MAX> CollisionManager::m_collisionMatrix[ ( UINT ) ELayerType::MAX ] = {};

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
		//Collision Check Logic
	}
}