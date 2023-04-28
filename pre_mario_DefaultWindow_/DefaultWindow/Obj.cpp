#include "stdafx.h"
#include "Obj.h"


CObj::CObj() : m_fSpeedX(0.f), m_fSpeedY(0.f), m_eState(STATE::DEFAULT)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
}


CObj::~CObj()
{
	
}

void CObj::Update_RectX(void)
{
	m_tRect.left	= LONG(m_tInfo.fX - (m_tInfo.fCX * 0.5f));
	//m_tRect.top		= LONG(m_tInfo.fY - (m_tInfo.fCY * 0.5f));
	m_tRect.right	= LONG(m_tInfo.fX + (m_tInfo.fCX * 0.5f));
	//m_tRect.bottom	= LONG(m_tInfo.fY + (m_tInfo.fCY * 0.5f));
}

void CObj::Update_RectY(void)
{
	//m_tRect.left = LONG(m_tInfo.fX - (m_tInfo.fCX * 0.5f));
	m_tRect.top = LONG(m_tInfo.fY - (m_tInfo.fCY * 0.5f));
	//m_tRect.right = LONG(m_tInfo.fX + (m_tInfo.fCX * 0.5f));
	m_tRect.bottom = LONG(m_tInfo.fY + (m_tInfo.fCY * 0.5f));
}