#pragma once
#include "K_Component.h"

namespace KHS
{

	class ScriptComp : public Component
	{
	public:
		ScriptComp();
		virtual ~ScriptComp();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

	private:

	};

}

