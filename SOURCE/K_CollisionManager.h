#pragma once
#include "CommonInclude.h"
#include "K_ColliderComp.h"

namespace KHS
{
	enum class ELayerType : __int8;

	union CollisionID
	{
		struct
		{
			UINT32 left;
			UINT32 right;
		};

		UINT64 id;
	};

	class CollisionManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

		static void CollisionLayerCheck(ELayerType left , ELayerType right , bool enable);
		static void LayerCollision(class Scene* scene , ELayerType left , ELayerType right);
		static void ColliderCollisionCheck(ColliderComp* left , ColliderComp* right);

		static bool IntersectAABB(ColliderComp* left , ColliderComp* right);

	private:
		//bitset[LayerCount] X LayerCount = Collision Matrix
		static std::bitset<( UINT ) ELayerType::MAX> m_collisionMatrix[ ( UINT ) ELayerType::MAX ];
		static std::unordered_map<UINT64 , bool> m_collisionMap;
	};
}

