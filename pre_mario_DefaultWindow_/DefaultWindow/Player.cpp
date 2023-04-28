#include "stdafx.h"
#include "Player.h"
#include "InputComponent.h"
#include "Managers.h"
#include "SceneManager.h"
#include "ScrollManager.h"
#include "ResourceManager.h"
#include "PhysicsComponent.h"
#include "ColliderComponent.h"
#include "GraphicsComponent.h"

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize(void)
{
	CManagers::instance().Resource()->Insert_Bmp(L"../Image/Object/mario.bmp", L"Player");
	m_eType = TYPE::PLAYER;
	m_eState = STATE::DEFAULT;
	m_tInfo = { 300.f, 500.f, 50, 60 };
	m_fSpeedX = 0.f;
	m_fSpeedY = 0.f;
	m_uMass = 20;
	m_pCurrentScene = CManagers::instance().Scene()->Get_Current_Scene();
//	m_bOnGround = false;
	m_bIsJump = false;
	m_bIsDown = false;
	m_bIsDash = false;
//	m_bOnCollision = false;

	m_bOnCollisionT = false;
	m_bOnCollisionB = false;
	m_bOnCollisionR = false;
	m_bOnCollisionL = false;

	m_pTarget = nullptr;


	m_pInputComponent = new CInputComponent(this);
	m_pPhysicsComponent = new CPhysicsComponent(this);
	m_pColliderComponent = new CColliderComponent(this);
	m_pGraphicsComponent = new CGraphicsComponent(this);

	//m_pCurrentScene = CManagers::instance().Scene()->Get_Current_Scene();

	static_cast<CInputComponent*>(m_pInputComponent)->Initialize();
	static_cast<CPhysicsComponent*>(m_pPhysicsComponent)->Initialize();
	static_cast<CColliderComponent*>(m_pColliderComponent)->Initialize(m_pCurrentScene);
	static_cast<CGraphicsComponent*>(m_pGraphicsComponent)->Initialize();
}

void CPlayer::Fixed_Update(void)
{
	static_cast<CPhysicsComponent*>(m_pPhysicsComponent)->Fixed_Update();
	__super::Update_RectX();
	OffSet();
}

int CPlayer::Update(void)
{
	__super::Update_RectX();
	static_cast<CInputComponent*>(m_pInputComponent)->Update();

	//switch (m_eState)
	//{
	//case STATE::DEFAULT:
	//	break;
	//case STATE::DEAD:
	//	break;
	//case STATE::MOVE:
	//	Set_InfoX(m_tInfo.fX + m_fSpeedX);
	//	break;
	//	//dynamic_cast<CPhysicsComponent* >(m_pPhysicsComponent)->Get_Impulse(this, DIRECTION::TOP, 100);
	//	break;
	//case STATE::ONAIR:
	//	break;
	//}


	//Key_Input();




	//__super::Update_Rect();

	return 0;
}

void CPlayer::Late_Update(void)
{
	static_cast<CColliderComponent*>(m_pColliderComponent)->Late_Update();
	//OffSet();
	__super::Update_RectY();
}

void CPlayer::Render(HDC hDC)
{
	HDC		hMemDC = CManagers::instance().Resource()->Find_Image(L"Player");
	static_cast<CGraphicsComponent*>(m_pGraphicsComponent)->Render(hDC, hMemDC);
}

void CPlayer::Release(void)
{
	Safe_Delete(m_pInputComponent);
	Safe_Delete(m_pPhysicsComponent);
	Safe_Delete(m_pColliderComponent);
	Safe_Delete(m_pGraphicsComponent);
}

void CPlayer::OffSet()
{
	float fOffSetminX = 300.f;
	float fOffSetmaxX = 400.f;

	float	fScrollX = CManagers::instance().Scroll()->Get_ScrollX();


	if (fOffSetminX > m_tInfo.fX + fScrollX)	// 플레이어가 왼쪽으로 향하고 있는 경우
	{
		CManagers::instance().Scroll()->Set_ScrollX(-m_fSpeedX);
		Set_InfoX(Get_Info().fX + 10);
	}
	if (fOffSetmaxX < m_tInfo.fX + fScrollX)	// 플레이어가 오른쪽으로 향하고 있는 경우
	{
		CManagers::instance().Scroll()->Set_ScrollX(-m_fSpeedX);
		Set_InfoX(Get_Info().fX - 10);
	}
}

