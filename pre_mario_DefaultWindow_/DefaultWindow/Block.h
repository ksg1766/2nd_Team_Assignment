#pragma once
#include "Obj.h"
class CBlock :
	public CObj
{
public:
	CBlock() = default;
	CBlock(const CBlock& rhs);
	virtual ~CBlock();

	virtual void Initialize(void)	override;
	virtual void Fixed_Update(void)	override;
	virtual int  Update(void)		override;
	virtual void Late_Update(void)	override;
	virtual void Render(HDC hDC)	override;
	virtual void Release(void)		override;
	CBlock* clone();

private:
	//CComponent* m_pPhysicsComponent;
	//CComponent* m_pColliderComponent;
	CComponent* m_pGraphicsComponent;
};

