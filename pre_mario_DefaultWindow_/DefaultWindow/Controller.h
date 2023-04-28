#pragma once
#include "Define.h"

class CObj;
class CController
{
public:
	CController();

	virtual ~CController();

protected:
	CObj*		m_cHost;
};

