#pragma once
#include "../SOURCE/K_Scene.h"

namespace KHS
{
	class PlayScene : public Scene
	{
	public:
		PlayScene() {}
		virtual ~PlayScene() = default;

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

	private:
	};
}
