#pragma once
#include "../SOURCE/K_Scene.h"

namespace KHS
{
	class Player;

	class PlayScene : public Scene
	{
	public:
		PlayScene();
		virtual ~PlayScene() = default;

		virtual void Initialize() override;
		void InitializeBackground();
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		Player* m_player;
	};
}
