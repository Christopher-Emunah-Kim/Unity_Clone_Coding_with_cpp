#include "K_CameraComp.h"
#include "K_Application.h"
#include "K_TransformComp.h"
#include "CommonInclude.h"

extern KHS::Application app;

namespace KHS
{
	CameraComp::CameraComp()
		:Component(EComponentType::CAMERA) , m_target(nullptr) , m_distance(Vector2D::Zero), 
		m_resolution(Vector2D(1600 , 900)) , m_lookPosition(Vector2D::Zero) , m_bUseCustomResolution(false)
	{
	}
	
	CameraComp::~CameraComp()
	{
	}

	void CameraComp::Initialize()
	{
		if ( m_bUseCustomResolution == false )
		{
			m_resolution.x = app.GetWidth();
			m_resolution.y = app.GetHeight();
		}
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
		Vector2D viewPos =  pos - m_distance;

		Vector2D scale = CalculateScale();

		viewPos.x *= scale.x;
		viewPos.y *= scale.y;

		return viewPos;
	}
	Vector2D CameraComp::CalculateScale()
	{
		Vector2D scale = Vector2D::One;

		if ( m_resolution.x != 0.0f && m_resolution.y != 0.0f )
		{
			scale.x = static_cast< float >( app.GetWidth() ) / m_resolution.x;
			scale.y = static_cast< float >( app.GetHeight() ) / m_resolution.y;
		}
		return scale;
	}
	void CameraComp::SetResolution(const Vector2D& resolution)
	{
		m_resolution = resolution;
		m_bUseCustomResolution = true;
	}
}