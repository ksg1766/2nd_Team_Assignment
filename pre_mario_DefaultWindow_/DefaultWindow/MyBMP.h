#pragma once
#include "Define.h"

class CMyBMP
{
public:
	CMyBMP();
	~CMyBMP();

public:
	HDC		Get_MemDC() { return m_hMemDC; }
	void	Load_Bmp(const TCHAR* pFilePath);
	void	Release(void);

private:
	HDC			m_hMemDC;
	HBITMAP		m_hBitmap;
	HBITMAP		m_hOldmap;
};
