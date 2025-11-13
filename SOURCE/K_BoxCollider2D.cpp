#include "K_BoxCollider2D.h"
#include "K_TransformComp.h"
#include "K_GameObject.h"
#include <K_MainCamera.h>


namespace KHS
{
	BoxCollider2D::BoxCollider2D()
		:ColliderComp()
	{
	}

	BoxCollider2D::~BoxCollider2D()
	{
	}

	void BoxCollider2D::Initialize()
	{
		ColliderComp::Initialize();
	}

	void BoxCollider2D::Update()
	{
		ColliderComp::Update();
	}

	void BoxCollider2D::LateUpdate()
	{
		ColliderComp::LateUpdate();
	}

	void BoxCollider2D::Render(HDC hdc)
	{
		ColliderComp::Render(hdc);

		TransformComp* tr = GetOwner()->GetComponent<TransformComp>();
		Vector2D pos = tr->GetPosition();
		if ( mainCamera )
		{
			pos = mainCamera->CalculatePosition(pos);
		}

		Vector2D offset = GetOffset();

		HBRUSH transparentBrush = ( HBRUSH ) GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = ( HBRUSH ) SelectObject(hdc , transparentBrush);

		HPEN greenPen = CreatePen(PS_SOLID , 2 , RGB(0 , 255 , 0));
		HPEN oldPen = ( HPEN ) SelectObject(hdc , greenPen);

		Rectangle(hdc ,
			static_cast< int >( pos.x - ( GetSize().x * 0.5f ) + offset.x ) ,
			static_cast< int >( pos.y - ( GetSize().y * 0.5f ) + offset.y ) ,
			static_cast< int >( pos.x + ( GetSize().x * 0.5f ) + offset.x ) ,
			static_cast< int >( pos.y + ( GetSize().y * 0.5f ) + offset.y ));

		SelectObject(hdc , oldBrush);
		SelectObject(hdc , oldPen);

		DeleteObject(greenPen);
	}
}