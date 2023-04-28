#pragma once
#include "Obj.h"

class CComponent;
class CPlayer :	public CObj
{
public:
	CPlayer() = default;
	virtual ~CPlayer();

public:
	virtual void Initialize(void)	override;
	virtual void Fixed_Update(void)	override;
	virtual int  Update(void)		override;
	virtual void Late_Update(void)	override;
	virtual void Render(HDC hDC)	override;
	virtual void Release(void)		override;

	bool Get_IsDown() { return m_bIsDown; }
	void Set_IsDown(bool _bIsDown) { m_bIsDown = _bIsDown; }
	
	bool Get_IsDash() { return m_bIsDash; }
	void Set_IsDash(bool _bIsDash) { m_bIsDash = _bIsDash; }

	CComponent*		Get_Physics() { return m_pPhysicsComponent; }
	CComponent*		Get_Collider() { return m_pColliderComponent; }
private:
	//STATE		m_eState;

	void		OffSet();

	bool m_bIsDown;
	bool m_bIsDash;

	CComponent*	m_pInputComponent;
	CComponent*	m_pPhysicsComponent;
	CComponent* m_pColliderComponent;
	CComponent* m_pGraphicsComponent;

};

