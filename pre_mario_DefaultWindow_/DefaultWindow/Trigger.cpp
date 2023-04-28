#include "stdafx.h"
#include "Trigger.h"
#include "Managers.h"
#include "SceneManager.h"
//#include "Scene1.h"
#include "ColliderComponent.h"
#include "ScrollManager.h"//

CTrigger::~CTrigger()
{
}

void CTrigger::Initialize(void)
{
	m_eType = TYPE::TRIGGER;
	m_eState = STATE::DEFAULT;
	m_tInfo = { 400.f, 250.f, 100, 100 };
	m_fSpeedX = 0.f;
	m_fSpeedY = 0.f;
	m_uMass = 0;
	m_pCurrentScene = CManagers::instance().Scene()->Get_Current_Scene();
	//	m_bOnGround = false;
	m_bIsJump = false;

	//	m_bOnCollision = false;

	m_bOnCollisionT = false;
	m_bOnCollisionB = false;
	m_bOnCollisionR = false;
	m_bOnCollisionL = false;

	m_pTarget = nullptr;

	//m_pPhysicsComponent = new CPhysicsComponent;
	m_pColliderComponent = new CColliderComponent(this);
}

void CTrigger::Fixed_Update(void)
{
	__super::Update_RectX();
}

int CTrigger::Update(void)
{
	return 0;
}

void CTrigger::Late_Update(void)
{
	static_cast<CColliderComponent*>(m_pColliderComponent)->Late_Update();
	__super::Update_RectY();
}

void CTrigger::Render(HDC hDC)
{
	//float	fScrollX = CManagers::instance().Scroll()->Get_ScrollX();

	//Rectangle(hDC,
	//	Get_Rect().left + (int)fScrollX,
	//	Get_Rect().top,
	//	Get_Rect().right + (int)fScrollX,
	//	Get_Rect().bottom);
}

void CTrigger::Release(void)
{
}
