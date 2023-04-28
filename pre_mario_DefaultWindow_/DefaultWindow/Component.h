#pragma once
#include "Define.h"

class CObj;
class CComponent
{
public:
	CComponent() = default;
	CComponent(CObj* _pHost) :m_pHost(_pHost) {}

	virtual ~CComponent();

protected:
	CObj*	m_pHost;
};

