#pragma once
#include "Component.h"
class CGraphicsComponent :
	public CComponent
{
public:
	CGraphicsComponent() = default;
	CGraphicsComponent(CObj* _pHost) : CComponent(_pHost) {}

	void Initialize();
	void Render(HDC hDC, HDC hMemDC);

	virtual ~CGraphicsComponent();
};

