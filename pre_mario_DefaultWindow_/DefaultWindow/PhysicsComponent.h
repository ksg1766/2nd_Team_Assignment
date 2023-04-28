#pragma once
#include "Component.h"
#include "ENum.h"

class CScene;
class CPhysicsComponent :
	public CComponent
{
public:
	CPhysicsComponent() = default;
	CPhysicsComponent(CObj* _pHost) :CComponent(_pHost) {}

	void Initialize();
	void Fixed_Update();
	void Get_Impulse(DIRECTION _eDir, UINT32 _uImpulse);
	
	int Get_Gravity() { return m_fGravity; }
	void Set_Gravity(float _fGravity) {	m_fGravity = _fGravity;	}

	virtual ~CPhysicsComponent();

private:
	//CScene*		m_pWorld;
	float		m_fGravity;
};

