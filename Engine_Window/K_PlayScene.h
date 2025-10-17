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

	private:
		void InitializeMainCamera();
		void InitializePlayer();
		void InitializeEnemy();
		void InitializeMushroom();
		void InitializeBackground();

	public:
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		Player* m_player;
	};
}
