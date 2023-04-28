#include "stdafx.h"
#include "Block.h"
#include "PhysicsComponent.h"
#include "ColliderComponent.h"
#include "GraphicsComponent.h"
#include "Managers.h"
#include "SceneManager.h"
#include "ResourceManager.h"

CBlock::CBlock(const CBlock & rhs) : CBlock()
{
	m_eType = rhs.m_eType;
	m_eState = rhs.m_eState;
	m_tInfo = rhs.m_tInfo;
	m_fSpeedX = rhs.m_fSpeedX;
	m_fSpeedY = rhs.m_fSpeedY;
	m_uMass = rhs.m_uMass;

	m_pCurrentScene = CManagers::instance().Scene()->Get_Current_Scene();

	m_pGraphicsComponent = new CGraphicsComponent(this);

	static_cast<CGraphicsComponent*>(m_pGraphicsComponent)->Initialize();
}


CBlock::~CBlock()
{
}

void CBlock::Initialize(void)
{
	m_eType = TYPE::IMMORTAL;
	m_eState = STATE::DEFAULT;
	m_tInfo = { 400.f, 100.f, 50.f, 50.f };
	m_fSpeedX = 0.f;
	m_fSpeedY = 0.f;
	m_uMass = 20;

	m_pCurrentScene = CManagers::instance().Scene()->Get_Current_Scene();

	m_pGraphicsComponent = new CGraphicsComponent(this);

	static_cast<CGraphicsComponent*>(m_pGraphicsComponent)->Initialize();
}

void CBlock::Fixed_Update(void)
{
	__super::Update_RectX();
}

int CBlock::Update(void)
{
	//__super::Update_RectY();

	return 0;
}

void CBlock::Late_Update(void)
{
	// dynamic_cast<CColliderComponent*>(m_pColliderComponent)->Late_Update();
	__super::Update_RectY();
}

void CBlock::Render(HDC hDC)
{
	//if (50 == m_tInfo.fCX)
	//{
		HDC		hMemDC = CManagers::instance().Resource()->Find_Image(L"Block");
		static_cast<CGraphicsComponent*>(m_pGraphicsComponent)->Render(hDC, hMemDC);
	//}
	//else //(2000 == m_tInfo.fCX)
	//{
	//	HDC hMemDC2 = CManagers::instance().Resource()->Find_Image(L"MGround");
	//	static_cast<CGraphicsComponent*>(m_pGraphicsComponent)->Render(hDC, hMemDC2);
	//}
}

void CBlock::Release(void)
{
	//Safe_Delete(m_pPhysicsComponent);
	//Safe_Delete(m_pColliderComponent);
	Safe_Delete(m_pGraphicsComponent);
}

CBlock* CBlock::clone()
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	CBlock* pBlock = new CBlock(*this);
	return pBlock;
}
