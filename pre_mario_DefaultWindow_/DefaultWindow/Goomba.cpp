#include "stdafx.h"
#include "Goomba.h"
#include "Managers.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "ColliderComponent.h"
#include "GraphicsComponent.h"
#include "PhysicsComponent.h"

CGoomba::CGoomba(const CGoomba & rhs): CGoomba()
{
	Initialize();
}

CGoomba::~CGoomba()
{
}

void CGoomba::Initialize(void)
{
	m_eType = TYPE::MONSTER;
	m_eState = STATE::DEAD;
	m_tInfo = { 500.f, 500.f, 50, 50 };
	m_fSpeedX = 1.5f;
	m_fSpeedY = 0.f;
	m_uMass = 20;
	m_pCurrentScene = nullptr;// CManagers::instance().Scene()->Get_Current_Scene();
	//	m_bOnGround = false;
	m_bIsJump = false;

	//	m_bOnCollision = false;

	m_bOnCollisionT = false;
	m_bOnCollisionB = false;
	m_bOnCollisionR = false;
	m_bOnCollisionL = false;

	m_pTarget = nullptr;

	m_pPhysicsComponent = new CPhysicsComponent(this);
	m_pColliderComponent = new CColliderComponent(this);
	m_pGraphicsComponent = new CGraphicsComponent(this);

	//m_pCurrentScene = CManagers::instance().Scene()->Get_Current_Scene();

	static_cast<CPhysicsComponent*>(m_pPhysicsComponent)->Initialize();
	static_cast<CColliderComponent*>(m_pColliderComponent)->Initialize(m_pCurrentScene);
	static_cast<CGraphicsComponent*>(m_pGraphicsComponent)->Initialize();
}

void CGoomba::Fixed_Update(void)
{
	static_cast<CPhysicsComponent*>(m_pPhysicsComponent)->Fixed_Update();
	__super::Update_RectX();
}

int CGoomba::Update(void)
{
	return 0;
}

void CGoomba::Late_Update(void)
{
	static_cast<CColliderComponent*>(m_pColliderComponent)->Late_Update();
	//OffSet();
	__super::Update_RectY();
}

void CGoomba::Render(HDC hDC)
{
	HDC		hMemDC = CManagers::instance().Resource()->Find_Image(L"Goomba");
	static_cast<CGraphicsComponent*>(m_pGraphicsComponent)->Render(hDC, hMemDC);
}

void CGoomba::Release(void)
{
	Safe_Delete(m_pPhysicsComponent);
	Safe_Delete(m_pColliderComponent);
	Safe_Delete(m_pGraphicsComponent);
}

CGoomba& CGoomba::clone()
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	CGoomba* pBlock = new CGoomba(*this);
	return *pBlock;
}
