#pragma once
#include <map>
#include "MyBMP.h"
 
class CResourceManager
{
public:
	CResourceManager();
	~CResourceManager();

	void		Insert_Bmp(const TCHAR* pFilePath, const TCHAR* pImgKey);
	HDC			Find_Image(const TCHAR* pImgKey);
	void		Release(void);

public:
	void		Destroy_Instance(void)
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}

	}
private:
	static CResourceManager*		m_pInstance;
	map<const TCHAR*, CMyBMP*>		m_mapBit;
};