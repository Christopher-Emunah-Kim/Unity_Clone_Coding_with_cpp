#pragma once

namespace KHS
{
	enum class EComponentType : __int8
	{
		TRANSFORM,
		SPRITERENDERER,
		SCRIPT,
		CAMERA,
		COLLIDER2D,
		RIGIDBODY2D,
		AUDIO,
		END
	};

	enum class ELayerType : __int8
	{
		NONE,
		BACKGROUND,
		//TREE,
		//CHARACTER,
		//MONSTER,
		PLAYER,
		MAX = 16,
	};

	enum class EResourceType : __int8
	{
		TEXTURE,
		AUDIO,
		PREFAB,
		END,
	};
}