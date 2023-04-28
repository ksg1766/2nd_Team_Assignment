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
	// ���¿� ���� �ٸ��� ���
	float	fScrollX = CManagers::instance().Scroll()->Get_ScrollX();

	GdiTransparentBlt(hDC,
		m_pHost->Get_Rect().left + (int)fScrollX, // ������� x��ġ�� ��ǥ
		m_pHost->Get_Rect().top, // ���� ���� y��ġ�� ��ǥ)
		(int)m_pHost->Get_Info().fCX, // ���� ���� ���� ����
		(int)m_pHost->Get_Info().fCY, // ���� ���� ���� ����
		hMemDC,	// ������ ��Ʈ�� �̹��� dc
		0,		// ��Ʈ���� ����� ���� x��ǥ
		0,		// ��Ʈ���� ����� ���� y��ǥ
		(int)m_pHost->Get_Info().fCX, // ������ ��Ʈ���� ���� ������
		(int)m_pHost->Get_Info().fCY,// ������ ��Ʈ���� ���� ������
		RGB(255, 255, 255)); //�����ϰ��� �ϴ� ����

	//Rectangle(hDC,
	//	m_pHost->Get_Rect().left + (int)fScrollX,
	//	m_pHost->Get_Rect().top,
	//	m_pHost->Get_Rect().right + (int)fScrollX,
	//	m_pHost->Get_Rect().bottom);
}

CGraphicsComponent::~CGraphicsComponent()
{
}
