#pragma once

#include "Define.h"
#include "Struct.h"
#include "Enum.h"

class CScene;
class CComponent;
class CObj
{
public:
	CObj();
	virtual ~CObj();


public:
	virtual void	Initialize(void)	PURE;
	virtual void	Fixed_Update(void)	PURE;
	virtual int		Update(void)		PURE;
	virtual void	Late_Update(void)	PURE;
	virtual void	Render(HDC hDC)		PURE;
	virtual void	Release(void)		PURE;

public:
	INFO		Get_Info()						{ return m_tInfo; }
	RECT		Get_Rect()						{ return m_tRect; }
	TYPE		Get_Type()						{ return m_eType; }
	STATE		Get_State()						{ return m_eState; }
	//bool		Get_OnGround()					{ return m_bOnGround; }

	bool		Get_OnCollisionT()				{ return m_bOnCollisionT; }
	bool		Get_OnCollisionB()				{ return m_bOnCollisionB; }
	bool		Get_OnCollisionR()				{ return m_bOnCollisionR; }
	bool		Get_OnCollisionL()				{ return m_bOnCollisionL; }

	//bool		Get_OnCollision() { return m_bOnCollision; }

	bool		Get_IsJump()					{ return m_bIsJump; }

	float		Get_SpeedX()					{ return m_fSpeedX; }
	float		Get_SpeedY()					{ return m_fSpeedY; }
	UINT32		Get_Mass()						{ return m_uMass; }

	CObj*		Get_Target()					{ return m_pTarget; }

	void		Set_InfoX(float _fX)			{ m_tInfo.fX = _fX; }
	void		Set_InfoY(float _fY)			{ m_tInfo.fY = _fY; }
	void		Set_InfoCX(float _fCX)			{ m_tInfo.fCX = _fCX; }
	void		Set_InfoCY(float _fCY)			{ m_tInfo.fCY = _fCY; }
	void		Set_State(STATE _eState)		{ m_eState = _eState; }
	void		Set_Type(TYPE _eType)			{ m_eType = _eType; }
	//void		Set_OnGround(bool _bOnGround)	{ m_bOnGround = _bOnGround;}

	void		Set_OnCollisionT(bool _bOnCollisionT)	{ m_bOnCollisionT = _bOnCollisionT; }
	void		Set_OnCollisionB(bool _bOnCollisionB)	{ m_bOnCollisionB = _bOnCollisionB; }
	void		Set_OnCollisionR(bool _bOnCollisionR)	{ m_bOnCollisionR = _bOnCollisionR; }
	void		Set_OnCollisionL(bool _bOnCollisionL)	{ m_bOnCollisionL = _bOnCollisionL; }

	//void		Set_OnCollision(bool _bOnCollision) { m_bOnCollision = _bOnCollision; }

	void		Set_IsJump(bool _bIsJump)		{ m_bIsJump = _bIsJump; }

	void		Set_SpeedX(float _fSpeedX)		{ m_fSpeedX = _fSpeedX; }
	void		Set_SpeedY(float _fSpeedY)		{ m_fSpeedY = _fSpeedY; }
	void		Set_Mass(UINT32 _uMass)			{ m_uMass = _uMass; }

	void		Set_Target(CObj* _pTarget)		{ m_pTarget = _pTarget; }
	//bool Get_IsGravity() { return m_bGravity; };
	//void Set_IsGravity(bool _bIsGravity) { m_bGravity = _bIsGravity; }

	void		Update_RectX(void);
protected:
	void		Update_RectY(void);

protected:
	TYPE		m_eType;
	UINT32		m_uMass;
	STATE		m_eState;
	//bool		m_bOnGround;

	bool		m_bOnCollisionT;
	bool		m_bOnCollisionB;
	bool		m_bOnCollisionR;
	bool		m_bOnCollisionL;

	//bool		m_bOnCollision;

	bool		m_bIsJump;

	//bool		m_bGravity;

	INFO		m_tInfo;
	RECT		m_tRect;

	float		m_fSpeedX;
	float		m_fSpeedY;

	CScene*		m_pCurrentScene;

	CObj*		m_pTarget;

};

