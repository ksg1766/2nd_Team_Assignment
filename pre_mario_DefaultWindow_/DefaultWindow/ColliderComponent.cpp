#include "stdafx.h"
#include "ColliderComponent.h"
#include "Player.h"
#include "Managers.h"
#include "SceneManager.h"
#include "PoolManager.h"
#include "EndScene.h"
#include "Scene1.h"
#include "Goomba.h"

void CColliderComponent::Initialize(CScene* _cScene)
{
	m_pWorld = _cScene;
	m_fOffsetX = 0.f;
	m_fOffsetY = 0.f;
}

void CColliderComponent::Update()
{
}

void CColliderComponent::Late_Update()
{
	for (int i = 1; i < (int)TYPE::END; ++i)
	{
		if ((TYPE)i == m_pHost->Get_Type())
			continue;
		if (TYPE::FRAGILE == m_pHost->Get_Type())// && (TYPE)i == TYPE::IMMORTAL)
			continue;
		if (TYPE::IMMORTAL == m_pHost->Get_Type())// && TYPE::FRAGILE == (TYPE)i)
			continue;
		if (TYPE::TRIGGER == m_pHost->Get_Type())
			continue;

		CheckCollisionByType(static_cast<TYPE>(i));
	}
}

void CColliderComponent::OnCollisionEnter(CObj * _pTarget)
{
	// 상하 충돌
	if (m_fOffsetX > m_fOffsetY)
	{
		// 하 충돌
		if (m_pHost->Get_Info().fY < _pTarget->Get_Info().fY)
		{
			if (TYPE::PLAYER == m_pHost->Get_Type())
			{
				if (static_cast<CPlayer*>(m_pHost)->Get_IsDash())
				{
					m_pHost->Set_SpeedX(0.f);
					static_cast<CPlayer*>(m_pHost)->Set_IsDash(false);
				}
			}
			m_pHost->Set_Target(_pTarget);
			m_pHost->Set_OnCollisionB(true);
			m_pHost->Set_InfoY(m_pHost->Get_Info().fY - m_fOffsetY - 5);
			//m_pHost->Set_IsJump(false);
			
			if (TYPE::PLAYER == m_pHost->Get_Type() && TYPE::MONSTER == _pTarget->Get_Type())
			{
				_pTarget->Set_State(STATE::DEAD);
				m_pHost->Set_SpeedY(5.f);
				//m_pHost->Set_IsJump(true);
				if (static_cast<CPlayer*>(m_pHost)->Get_IsDown())
					static_cast<CPlayer*>(m_pHost)->Set_IsDown(false);
				if (static_cast<CPlayer*>(m_pHost)->Get_OnCollisionB());
					//static_cast<CPlayer*>(m_pHost)->Set_OnCollisionB(false);
			}
			if (TYPE::PLAYER == m_pHost->Get_Type() && TYPE::FRAGILE == _pTarget->Get_Type())
			{
				//if (m_pHost->Get_SpeedY() == -10.f)
				if(static_cast<CPlayer*>(m_pHost)->Get_IsDown())
				{
					if (_pTarget->Get_Mass() <= m_pHost->Get_Mass())
						_pTarget->Set_State(STATE::DEAD);
					static_cast<CPlayer*>(m_pHost)->Set_IsDown(false);
				}
			}
		}
		// 상 충돌
		else if (m_pHost->Get_Info().fY >= _pTarget->Get_Info().fY && m_pHost->Get_SpeedY() >= 0)
		{
			m_pHost->Set_SpeedY(0.f);	// ...
			//m_pHost->Set_OnCollisionT(true);
			m_pHost->Set_InfoY(m_pHost->Get_Info().fY + m_fOffsetY);
			
			if (TYPE::PLAYER == m_pHost->Get_Type() && TYPE::FRAGILE == _pTarget->Get_Type())
			{
				if (_pTarget->Get_Mass() <= m_pHost->Get_Mass())
					_pTarget->Set_State(STATE::DEAD);
			}

		}
	}
	

	// 좌우 충돌
	else if (m_fOffsetX < m_fOffsetY)	
	{
		if (TYPE::PLAYER == m_pHost->Get_Type() && TYPE::MONSTER == _pTarget->Get_Type())
		{
			m_pHost->Set_State(STATE::DEAD);
			return;
		}
		// 좌 충돌
		if (m_pHost->Get_Info().fX > _pTarget->Get_Info().fX)	
		{
			m_pHost->Set_OnCollisionL(true);
			m_pHost->Set_InfoX(m_pHost->Get_Info().fX + m_fOffsetX);
		}
		// 우 충돌
		else
		{
			m_pHost->Set_OnCollisionR(true);
			m_pHost->Set_InfoX(m_pHost->Get_Info().fX - m_fOffsetX);
		}
	}
}

void CColliderComponent::OnCollisionStay(CObj * _pTarget)
{
}

void CColliderComponent::OnCollisionExit(CObj * _pTarget)
{

}

void CColliderComponent::OnTriggerEnter(CObj * _pTarget)
{
	//CObj* pGoomba = new CGoomba;	// CPoolManager->Create_
	//pGoomba->Initialize();
	//pGoomba->Set_InfoX(_pTarget->Get_Info().fX + 150);
	CManagers::instance().Pool()->Create_Monster(m_pHost);
	//CManagers::instance().Scene()->Get_Current_Scene()->Get_ObjList(TYPE::MONSTER).push_back(pGoomba);
	if (m_pHost->Get_Info().fX > 1899)
	{
		for (auto& iter : CManagers::instance().Scene()->Get_Current_Scene()->Get_ObjList(TYPE::MONSTER))
		{
			CManagers::instance().Pool()->Return_Monster(iter);
		}
		CScene* pEndScene = new CEndScene;
		pEndScene->Initialize();
		CManagers::instance().Scene()->Load_Scene(pEndScene);
	}
}

void CColliderComponent::CheckCollisionByType(TYPE _eType)
{
	//list<CObj*>& objList = m_pWorld->Get_ObjList(_eType);
	list<CObj*>& objList = CManagers::instance().Scene()->Get_Current_Scene()->Get_ObjList(_eType);

	for (auto& iter : objList)
	{
		if (Check_Rect(iter))	// 땅에 계속 붙어있을 때도 여기 걸릴 거임.
		{
			if (TYPE::TRIGGER == _eType && TYPE::PLAYER == m_pHost->Get_Type())
				OnTriggerEnter(iter);
			else
	 			OnCollisionEnter(iter);
		}
		else
		{
			/*m_pHost->Set_OnCollisionB(false);
			m_pHost->Set_OnCollisionT(false);
			m_pHost->Set_OnCollisionL(false);
			m_pHost->Set_OnCollisionR(false);*/
			 
		}

	}
}

bool CColliderComponent::Check_Rect(CObj * pSrc)
{
	float	fWidth = fabs(m_pHost->Get_Info().fX - pSrc->Get_Info().fX);
	float	fHeight = fabs(m_pHost->Get_Info().fY - pSrc->Get_Info().fY);

	float	fRadiusX = (m_pHost->Get_Info().fCX + pSrc->Get_Info().fCX) * 0.5f;
	float	fRadiusY = (m_pHost->Get_Info().fCY + pSrc->Get_Info().fCY) * 0.5f;

	if ((fRadiusX >= fWidth) && (fRadiusY >= fHeight))
	{
		m_fOffsetX = fRadiusX - fWidth;
		m_fOffsetY = fRadiusY - fHeight;

		return true;
	}
	return false;
}

CColliderComponent::~CColliderComponent()
{
}