#pragma once
#include "../SOURCE/K_GameObject.h"

namespace KHS
{
	class Enemy : public GameObject
	{
	public:
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LastUpdate() override;
		virtual void Render(HDC hdc) override;

	private:

	};
}