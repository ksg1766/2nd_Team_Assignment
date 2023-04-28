#include "stdafx.h"
#include "GraphicsComponent.h"
#include "Obj.h"
#include "Managers.h"
#include "ScrollManager.h"

void CGraphicsComponent::Initialize()
{
	// m_pHost = _pObj;
}

void CGraphicsComponent::Render(HDC hDC, HDC hMemDC)
{
	// 상태에 따라 다르게 출력
	float	fScrollX = CManagers::instance().Scroll()->Get_ScrollX();

	GdiTransparentBlt(hDC,
		m_pHost->Get_Rect().left + (int)fScrollX, // 복사받을 x위치의 좌표
		m_pHost->Get_Rect().top, // 복사 받을 y위치의 좌표)
		(int)m_pHost->Get_Info().fCX, // 복사 받을 가로 길이
		(int)m_pHost->Get_Info().fCY, // 복사 받을 세로 길이
		hMemDC,	// 복사할 비트맵 이미지 dc
		0,		// 비트맵을 출력할 시작 x좌표
		0,		// 비트맵을 출력할 시작 y좌표
		(int)m_pHost->Get_Info().fCX, // 복사할 비트맵의 가로 사이즈
		(int)m_pHost->Get_Info().fCY,// 복사할 비트맵의 세로 사이즈
		RGB(255, 255, 255)); //제거하고자 하는 색상

	//Rectangle(hDC,
	//	m_pHost->Get_Rect().left + (int)fScrollX,
	//	m_pHost->Get_Rect().top,
	//	m_pHost->Get_Rect().right + (int)fScrollX,
	//	m_pHost->Get_Rect().bottom);
}

CGraphicsComponent::~CGraphicsComponent()
{
}
