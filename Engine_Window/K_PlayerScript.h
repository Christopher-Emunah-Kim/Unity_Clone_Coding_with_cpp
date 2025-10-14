#pragma once
#include "../SOURCE/K_ScriptComp.h"

namespace KHS
{
	class PlayerScript : public ScriptComp
	{
	public:
		PlayerScript();
		virtual ~PlayerScript();

	private:
		void UpdatePlayerPosition();

	public:
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

	private:

	};
}


