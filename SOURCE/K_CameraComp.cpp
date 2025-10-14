#include "K_CameraComp.h"
#include "K_Application.h"
#include "K_TransformComp.h"
#include "CommonInclude.h"

extern KHS::Application app;

namespace KHS
{
	CameraComp::CameraComp()
		:Component(EComponentType::CAMERA) , m_target(nullptr) , m_distance(Vector2D::Zero), 
		m_resolution(Vector2D(1600, 900)), m_lookPosition(Vector2D::Zero)
	{
	}
	
	CameraComp::~CameraComp()
	{
	}

	void CameraComp::Initialize()
	{
		m_resolution.x = app.GetWidth();
		m_resolution.y = app.GetHeight();
	}
	void CameraComp::Update()
	{
		if (m_target != nullptr)
		{
			TransformComp* tr = m_target->GetComponent<TransformComp>();
			m_lookPosition = tr->GetPosition();
		}
		else
		{
			TransformComp* cameraTr = GetOwner()->GetComponent<TransformComp>();
			m_lookPosition = cameraTr->GetPosition();
		}

		//월드 좌표계 -> 뷰 좌표계
		m_distance = m_lookPosition - ( m_resolution / 2.0f );
	}
	void CameraComp::LateUpdate()
	{
	}
	void CameraComp::Render(HDC hdc)
	{
	}
	Vector2D CameraComp::CalculatePosition(Vector2D pos)
	{
		return pos - m_distance;
	}
}