#pragma once
#include "../SOURCE/K_ResourceTable.h"
#include "../SOURCE/K_Texture.h"

namespace KHS
{
	void LoadResources()
	{
		ResourceTable::Load<Texture>(L"BG", L"CloudOcean.png");
	}
}