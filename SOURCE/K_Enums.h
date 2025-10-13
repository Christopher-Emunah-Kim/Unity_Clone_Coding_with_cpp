#pragma once

namespace KHS
{
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