#include "stdafx.h"
//#include "Managers.h"
//#include "SceneManager.h"
//#include "Scene.h"
#include "InputComponent.h"
#include "PhysicsComponent.h"
#include "Player.h"

CInputComponent::~CInputComponent()
{
}

void CInputComponent::Initialize()
{
	ZeroMemory(m_bKeyState, sizeof(m_bKeyState));
}

void CInputComponent::Update()
{
	if (Key_Pressing(VK_RIGHT))
	{
		m_pHost->Set_SpeedX(10.f);
	}
	if (Key_Up(VK_RIGHT))
	{
		m_pHost->Set_SpeedX(0.f);
	}

	if (Key_Pressing(VK_LEFT))
	{
		m_pHost->Set_SpeedX(-10.f);
	}
	if (Key_Up(VK_LEFT))
	{
		m_pHost->Set_SpeedX(0.f);
	}

	if (Key_Down(VK_DOWN))
	{
		if (m_pHost->Get_OnCollisionB() || m_pHost->Get_IsJump())//..?이게 왜 되지
		{
			static_cast<CPhysicsComponent*>(static_cast<CPlayer*>(m_pHost)->Get_Physics())->Get_Impulse(DIRECTION::BOTTOM, 200);
			//m_pHost->Set_SpeedY(-10.f);
			static_cast<CPlayer*>(m_pHost)->Set_IsDown(true);
		}
	}

	if (Key_Down(VK_SPACE))
	{

		if (!m_pHost->Get_IsJump())
		{
			m_pHost->Set_OnCollisionB(false);
			m_pHost->Set_IsJump(true);
		}
		if (m_pHost->Get_OnCollisionL())
		{
			m_pHost->Set_OnCollisionL(false);
			static_cast<CPlayer*>(m_pHost)->Set_IsDash(true);
			static_cast<CPhysicsComponent*>(static_cast<CPlayer*>(m_pHost)->Get_Physics())->Get_Impulse(DIRECTION::RIGHT, 200);
		}
		if (m_pHost->Get_OnCollisionR())
		{
			m_pHost->Set_OnCollisionR(false);
			static_cast<CPlayer*>(m_pHost)->Set_IsDash(true);
			static_cast<CPhysicsComponent*>(static_cast<CPlayer*>(m_pHost)->Get_Physics())->Get_Impulse(DIRECTION::LEFT, 200);
		}

	}

	/*if (TYPE::MONSTER == m_pHost->Get_Type())
	{
		if ((CManagers::instance().Scene()->Get_Current_Scene()->Get_WorldTime() / 5000))
			m_pHost->Set_SpeedX(-m_pHost->Get_SpeedX());
	}*/
	//if (m_pHost->Get_IsJump())
	//{
	//	if (Key_Pressing(VK_SHIFT) && Key_Down(VK_RIGHT))
	//		static_cast<CPhysicsComponent*>(m_pHost->Get_Physics())->Get_Impulse(m_pHost, DIRECTION::RIGHT, 100);

	//	else if (Key_Pressing(VK_SHIFT) && Key_Down(VK_LEFT))
	//		static_cast<CPhysicsComponent*>(m_pHost->Get_Physics())->Get_Impulse(m_pHost, DIRECTION::LEFT, 100);

	//	else if (Key_Pressing(VK_SHIFT) && Key_Down(VK_SPACE))
	//	{
	//		static_cast<CPhysicsComponent*>(m_pHost->Get_Physics())->Get_Impulse(m_pHost, DIRECTION::TOP, 100);
	//	}
	//}
}

bool CInputComponent::Key_Pressing(int _iKey)
{
	if (GetAsyncKeyState(_iKey) & 0x8000)
		return true;

	return false;
}

bool CInputComponent::Key_Down(int _iKey)
{
	if (!m_bKeyState[_iKey] && (GetAsyncKeyState(_iKey) & 0x8000))
	{
		m_bKeyState[_iKey] = !m_bKeyState[_iKey];
		return true;
	}

	for (int i = 0; i < VK_MAX; ++i)
	{
		if (m_bKeyState[i] && !(GetAsyncKeyState(i) & 0x8000))
			m_bKeyState[i] = !m_bKeyState[i];
	}
	return false;
}

bool CInputComponent::Key_Up(int _iKey)
{
	if (m_bKeyState[_iKey] && !(GetAsyncKeyState(_iKey) & 0x8000))
	{
		m_bKeyState[_iKey] = !m_bKeyState[_iKey];
		return true;
	}

	for (int i = 0; i < VK_MAX; ++i)
	{
		if (!m_bKeyState[_iKey] && (GetAsyncKeyState(_iKey) & 0x8000))
			m_bKeyState[i] = !m_bKeyState[i];
	}
	return false;
}
