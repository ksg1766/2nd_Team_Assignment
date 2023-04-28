#pragma once
#include "Component.h"
#include "Enum.h"

class CScene;
class CColliderComponent :
	public CComponent
{
public:
	CColliderComponent() = default;
	CColliderComponent(CObj* _pHost) :CComponent(_pHost) {}

	void Initialize(CScene* _pWorld);
	void Update();
	void Late_Update();


	void OnCollisionEnter(CObj* _pTarget);
	void OnCollisionStay(CObj* _pTarget);
	void OnCollisionExit(CObj* _pTarget);

	void OnTriggerEnter(CObj* _pTarget);
	bool OnTriggerStay(CObj* _pTarget);
	bool OnTriggerExit(CObj* _pTarget);

	float Get_OffsetX() { return m_fOffsetX; }
	float Get_OffsetY() { return m_fOffsetY; }

	//void CheckCollision(CObj* _cObj);
	void CheckCollisionByType(TYPE _eType);
	bool Check_Rect(CObj * pSrc);

	virtual ~CColliderComponent();

private:
	CScene*	m_pWorld;

	float	m_fOffsetX;
	float	m_fOffsetY;
};

