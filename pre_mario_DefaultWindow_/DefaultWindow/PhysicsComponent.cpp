#include "stdafx.h"
#include "PhysicsComponent.h"
#include "ColliderComponent.h"
#include "Scene.h"
#include "Managers.h"
#include "SceneManager.h"
#include "Player.h"

void CPhysicsComponent::Initialize()
{
	//m_pWorld = _pWorld;
	m_fGravity = 9.8f;
	// m_pHost = _cObj;
}

void CPhysicsComponent::Fixed_Update()
{
	if (TYPE::PLAYER == m_pHost->Get_Type())
	{
		if (static_cast<CPlayer*>(m_pHost)->Get_IsJump() && static_cast<CPlayer*>(m_pHost)->Get_OnCollisionB())
		{
			Get_Impulse(DIRECTION::TOP, 100);
			static_cast<CPlayer*>(m_pHost)->Set_IsJump(false);
		}
		/*if (_cObj->Get_OnCollisionB())
		{
		}*/

		/*if (_cObj->Get_OnCollisionT())
		{
			_cObj->Set_SpeedY(0.f );
		}*/

		/*if (_cObj->Get_OnCollisionL())
		{
		}

		if (_cObj->Get_OnCollisionR())
		{
		}*/

		if (m_pHost->Get_SpeedY() > -10000.f) // 그냥 속도를 가지고 있을 때는 점프 아예 못하게...
			static_cast<CPlayer*>(m_pHost)->Set_IsJump(false);

		m_pHost->Set_SpeedY(m_pHost->Get_SpeedY() - m_fGravity / 100.f);
		if (m_pHost->Get_SpeedY() < -m_fGravity)
		{
			m_pHost->Set_SpeedY(-10.f);
		}
		m_pHost->Set_InfoX(m_pHost->Get_Info().fX + m_pHost->Get_SpeedX());
		m_pHost->Set_InfoY(m_pHost->Get_Info().fY - m_pHost->Get_SpeedY());
	}

	else if (TYPE::MONSTER == m_pHost->Get_Type())
	{
		//if (m_pHost->Get_OnCollisionL())
		//{
		//	//m_pHost->Set_SpeedX(-m_pHost->Get_SpeedX());
		//	m_pHost->Set_OnCollisionL(false);
		//}

		//if (m_pHost->Get_OnCollisionR())
		//{
		//	//m_pHost->Set_SpeedX(-m_pHost->Get_SpeedX());
		//	m_pHost->Set_OnCollisionR(false);
		//}
		if (TYPE::MONSTER == m_pHost->Get_Type())
		{
			m_pHost->Set_SpeedX(m_pHost->Get_SpeedX());
			if (!(CManagers::instance().Scene()->Get_Current_Scene()->Get_WorldTime() % 3000))
			{
				m_pHost->Set_SpeedX(-m_pHost->Get_SpeedX());
			}
		}

		m_pHost->Set_SpeedY(m_pHost->Get_SpeedY() - m_fGravity / 100.f);
		if (m_pHost->Get_SpeedY() < -m_fGravity)
		{
			m_pHost->Set_SpeedY(-m_fGravity / 2);
		}

		m_pHost->Set_InfoX(m_pHost->Get_Info().fX + m_pHost->Get_SpeedX());
		m_pHost->Set_InfoY(m_pHost->Get_Info().fY - m_pHost->Get_SpeedY());
	}

//	else if (TYPE::IMMORTAL == _cObj->Get_Type())
//	{
		/*_cObj->Set_SpeedX(0);
		_cObj->Set_SpeedY(0);
		_cObj->Set_InfoX(_cObj->Get_Info().fX);
		_cObj->Set_InfoY(_cObj->Get_Info().fY);*/
//	}
//	else if (TYPE::FRAGILE == _cObj->Get_Type())
//	{
		/*_cObj->Set_SpeedX(0);
		_cObj->Set_SpeedY(0);
		_cObj->Set_InfoX(_cObj->Get_Info().fX);
		_cObj->Set_InfoY(_cObj->Get_Info().fY);*/
//	}
}

void CPhysicsComponent::Get_Impulse(DIRECTION _eDir, UINT32 _uImpulse)
{
 	float fVelocity = _uImpulse / m_pHost->Get_Mass();
	float fRad = (int)_eDir * 90.f * PI / 180.f;
	float fVFactorX = fVelocity * cos(fRad);
	float fVFactorY = fVelocity * sin(fRad);

	if(DIRECTION::RIGHT == _eDir)
		m_pHost->Set_SpeedX(fVFactorX);
	else if (DIRECTION::TOP == _eDir)
	{
		m_pHost->Set_SpeedX(fVFactorX);
		m_pHost->Set_SpeedY(fVFactorY);
	}
	else if (DIRECTION::LEFT == _eDir)
		m_pHost->Set_SpeedX(fVFactorX);
	else if (DIRECTION::BOTTOM == _eDir)
		m_pHost->Set_SpeedY(fVFactorY);
	/*switch (_eDir)
	{
	case DIRECTION::RIGHT:
		_cObj->Set_SpeedX(fVFactorX);
		break;
	case DIRECTION::TOP:
		_cObj->Set_SpeedY(fVFactorY);
		break;
	case DIRECTION::LEFT:
		_cObj->Set_SpeedX(fVFactorX);
		break;
	case DIRECTION::BOTTOM:
		_cObj->Set_SpeedY(fVFactorY);
		break;

	}*/
}

CPhysicsComponent::~CPhysicsComponent()
{
}