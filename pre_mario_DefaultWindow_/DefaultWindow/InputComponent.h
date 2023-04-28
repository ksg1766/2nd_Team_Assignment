#pragma once
#include "Component.h"
#include "Enum.h"

class CPlayer;
class CInputComponent :
	public CComponent
{
public:
	CInputComponent() = default;
	CInputComponent(CObj* _pHost) : CComponent(_pHost) {}

	void	Initialize();
	void	Update();

	bool	Key_Pressing(int _iKey);
	bool	Key_Down(int _iKey);
	bool	Key_Up(int _iKey);

	virtual	~CInputComponent();

private:
	bool		m_bKeyState[VK_MAX];
};

