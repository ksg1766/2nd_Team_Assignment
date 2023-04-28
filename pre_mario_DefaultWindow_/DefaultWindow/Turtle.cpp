#include "stdafx.h"
#include "Turtle.h"
#include "Managers.h"
#include "SceneManager.h"
#include "ColliderComponent.h"
#include "GraphicsComponent.h"
#include "PhysicsComponent.h"

CTurtle::CTurtle()
{
}


CTurtle::~CTurtle()
{
}

void CTurtle::Initialize(void)
{
	m_eType = TYPE::MONSTER;
	m_eState = STATE::DEFAULT;
	m_tInfo = { 500.f, 500.f, 50, 50 };
	m_fSpeedX = 1.5f;
	m_fSpeedY = 0.f;
	m_uMass = 20;
	m_pCurrentScene = CManagers::instance().Scene()->Get_Current_Scene();
	//	m_bOnGround = false;
	m_bIsJump = false;

	//	m_bOnCollision = false;

	m_bOnCollisionT = false;
	m_bOnCollisionB = false;
	m_bOnCollisionR = false;
	m_bOnCollisionL = false;

	m_pTarget = nullptr;

	m_pPhysicsComponent = new CPhysicsComponent;
	m_pColliderComponent = new CColliderComponent;
	m_pGraphicsComponent = new CGraphicsComponent;

	//m_pCurrentScene = CManagers::instance().Scene()->Get_Current_Scene();

	static_cast<CPhysicsComponent*>(m_pPhysicsComponent)->Initialize();
	static_cast<CColliderComponent*>(m_pColliderComponent)->Initialize(m_pCurrentScene);
	static_cast<CGraphicsComponent*>(m_pGraphicsComponent)->Initialize();
}

void CTurtle::Fixed_Update(void)
{
	static_cast<CPhysicsComponent*>(m_pPhysicsComponent)->Fixed_Update();
	__super::Update_RectX();
}

int CTurtle::Update(void)
{
	return 0;
}

void CTurtle::Late_Update(void)
{
	static_cast<CColliderComponent*>(m_pColliderComponent)->Late_Update();
	//OffSet();
	__super::Update_RectY();
}

void CTurtle::Render(HDC hDC)
{
//	dynamic_cast<CGraphicsComponent*>(m_pGraphicsComponent)->Render(hDC);
}

void CTurtle::Release(void)
{
	Safe_Delete(m_pPhysicsComponent);
	Safe_Delete(m_pColliderComponent);
	Safe_Delete(m_pGraphicsComponent);
}
