#pragma once
#include "Obj.h"

class CPlatform :
	public CObj
{
public:
	CPlatform();
	virtual ~CPlatform();

	// CObj��(��) ���� ��ӵ�
	virtual void Initialize(void) override;
	virtual void Fixed_Update(void) override;
	virtual int  Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	void		 Create_Blocks();

private:
};

