#pragma once
#include "Scene.h"
class CScene1 :
	public CScene
{
public:
	CScene1();

	virtual ~CScene1();

	// CScene을(를) 통해 상속됨
	virtual void Initialize(void)	override;
	virtual void Fixed_Update(void)	override;
	virtual void Update(void)		override;
	virtual void Late_Update(void)	override;
	virtual void Render(HDC hDC)	override;
	virtual void Release(void)		override;

//private:
//	list<CObj*> m_cObjList[int(TYPE::END)];
//
//	float		m_fGravity;
};

