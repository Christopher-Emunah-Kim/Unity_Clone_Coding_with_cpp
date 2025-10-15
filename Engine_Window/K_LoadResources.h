#pragma once
#include "../SOURCE/K_ResourceTable.h"
#include "../SOURCE/K_Texture.h"

namespace KHS
{
	void LoadResources()
	{
		ResourceTable::Load<Texture>(L"Map", L"img\\CloudOcean.png");
		ResourceTable::Load<Texture>(L"PackMan", L"img\\PackMan_R1.png");
	}
}