#pragma once
#include "Obj.h"

class CComponent;
class CTrigger
	:public CObj
{
public:
	CTrigger() = default;
	virtual ~CTrigger();


	// CObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual void Fixed_Update(void) override;
	virtual int  Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	//CComponent* m_pPhysicsComponent;
	CComponent* m_pColliderComponent;
};

