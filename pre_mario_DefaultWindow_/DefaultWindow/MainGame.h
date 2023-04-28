#pragma once

#include "Define.h"
#include "Player.h"

class Cscene;
class CMainGame
{
public:
	void		Initialize(void);
	void		Fixed_Update(void);
	void		Update(void);
	void		Late_Update(void);
	void		Render();
	void		Release(void);

private:
	HDC			m_DC;
	UINT		m_iUpdateCount;
	UINT		m_iFixedUpdateCount;


public:
	CMainGame();
	~CMainGame();
};

