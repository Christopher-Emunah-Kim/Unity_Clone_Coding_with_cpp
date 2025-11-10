#pragma once

namespace KHS
{
	enum class EComponentType : __int8
	{
		TRANSFORM,
		SCRIPT,
		COLLIDER,
		SPRITERENDERER,
		ANIMATOR,
		CAMERA,
		AUDIO,
		END
	};

	enum class ELayerType : __int8
	{
		NONE,
		BACKGROUND,
		//TREE,
		//CHARACTER,
		ENEMY,
		PLAYER,
		PARTICLE,
		MAX = 16,
	};

	enum class EResourceType : __int8
	{
		TEXTURE,
		AUDIO,
		ANIMATION,
		PREFAB,
		END,
	};
}