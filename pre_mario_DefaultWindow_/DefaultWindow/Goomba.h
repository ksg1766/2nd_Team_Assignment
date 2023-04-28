#pragma once
#include "Obj.h"
class CGoomba :
	public CObj
{
public:
	CGoomba() = default;
	CGoomba(const CGoomba& rhs);
	virtual ~CGoomba();

	virtual void Initialize(void) override;
	virtual void Fixed_Update(void) override;
	virtual int  Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	CGoomba& clone();

private:
	CComponent* m_pPhysicsComponent;
	CComponent* m_pColliderComponent;
	CComponent* m_pGraphicsComponent;
};

