#pragma once
#include "Scene.h"
class CEndScene
	: public CScene
{
public:
	CEndScene();
	~CEndScene();

	// CScene��(��) ���� ��ӵ�
	virtual void Initialize(void) override;
	virtual void Fixed_Update(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC m_DC) override;
};

