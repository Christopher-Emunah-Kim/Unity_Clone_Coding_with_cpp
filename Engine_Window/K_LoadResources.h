#pragma once
#include "../SOURCE/K_ResourceTable.h"
#include "../SOURCE/K_Texture.h"

namespace KHS
{
	void LoadResources()
	{
		ResourceTable::Load<Texture>(L"CloudOcean", L"img\\CloudOcean.png");
		ResourceTable::Load<Texture>(L"Chicken", L"img\\chicken.bmp");
		ResourceTable::Load<Texture>(L"Cat", L"img\\ChickenAlpha.bmp");
		ResourceTable::Load<Texture>(L"MapleEffect", L"img\\ezgif.com-gif-maker.png");
		ResourceTable::Load<Texture>(L"Player", L"img\\Player.bmp");
	}
}