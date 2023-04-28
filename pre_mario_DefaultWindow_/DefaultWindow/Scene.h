#pragma once
#include "Define.h"
#include "Enum.h"

class CObj;
class CScene
{
public:
	CScene();

	virtual void		Initialize(void)	PURE;
	virtual void		Fixed_Update(void)	PURE;
	virtual void		Update(void)		PURE;
	virtual void		Late_Update(void)	PURE;
	virtual void		Render(HDC m_DC)	PURE;
	//virtual void		Release(void)		PURE;
	virtual void		Release(void);

	float				Get_Gravity() { return m_fGravity; };
	list<CObj*>&		Get_ObjList(TYPE _eType) { return m_cObjList[(int)_eType]; };
	void				Set_WorldTime(UINT _WorldTime) { m_WorldTime = _WorldTime; }
	UINT				Get_WorldTime() { return m_WorldTime; }


	virtual ~CScene();

protected:
	list<CObj*> m_cObjList[int(TYPE::END)];

	DWORD		m_WorldTime;
	float		m_fGravity;
};

