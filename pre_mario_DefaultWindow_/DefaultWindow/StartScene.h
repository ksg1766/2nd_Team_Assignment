#pragma once
#include "Scene.h"
class CStartScene :
	public CScene
{
public:
	CStartScene();
	virtual ~CStartScene();

	// CScene��(��) ���� ��ӵ�
	virtual void Initialize(void)	override;
	virtual void Fixed_Update(void)	override;
	virtual void Update(void)		override;
	virtual void Late_Update(void)	override;
	virtual void Render(HDC m_DC)	override;
	virtual void Release(void)		override;
};

