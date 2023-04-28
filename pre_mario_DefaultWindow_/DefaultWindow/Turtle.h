#pragma once
#include "Obj.h"
class CTurtle :
	public CObj
{
public:
	CTurtle();
	virtual ~CTurtle();

	virtual void Initialize(void) override;
	virtual void Fixed_Update(void) override;
	virtual int	 Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	void Set_IsHide(bool _bIsHide)	{ m_bIsHide = _bIsHide; };
	bool Get_IsHide()				{ return m_bIsHide; }

private:
	bool		m_bIsHide;

	CComponent* m_pPhysicsComponent;
	CComponent* m_pColliderComponent;
	CComponent* m_pGraphicsComponent;
};

