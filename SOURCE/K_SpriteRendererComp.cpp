#include "K_SpriteRendererComp.h"

namespace KHS
{
	SpriteRendererComp::SpriteRendererComp()
	{
	}
	SpriteRendererComp::~SpriteRendererComp()
	{
	}
	void SpriteRendererComp::Initialize()
	{
	}
	void SpriteRendererComp::Update()
	{
	}
	void SpriteRendererComp::LastUpdate()
	{
	}
	void SpriteRendererComp::Render(HDC hdc)
	{
		////�Ķ� �귯�� ����
		//HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		//// �Ķ� �귯�� DC�� ���� �׸��� ��� �귯�� ��ȯ�� ��ȯ
		//HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);
		//HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));

		//HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		//SelectObject(hdc, oldPen);

		//Rectangle(hdc, 100 + m_x, 100 + m_y, 200 + m_x, 200 + m_y);

		//SelectObject(hdc, oldBrush);
		//DeleteObject(blueBrush);
		//DeleteObject(redPen);
	}
}