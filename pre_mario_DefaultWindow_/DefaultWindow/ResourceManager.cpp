#include "stdafx.h"
#include "ResourceManager.h"
#include <algorithm>
#include "Struct.h"

CResourceManager::CResourceManager()
{
}


CResourceManager::~CResourceManager()
{
	Release();
}

void CResourceManager::Insert_Bmp(const TCHAR * pFilePath, const TCHAR * pImgKey)
{
	auto		iter = find_if(m_mapBit.begin(), m_mapBit.end(), tagFinder(pImgKey));

	if (iter == m_mapBit.end())
	{
		CMyBMP*		pBmp = new CMyBMP;
		pBmp->Load_Bmp(pFilePath);

		m_mapBit.emplace(pImgKey, pBmp);
	}
}

HDC CResourceManager::Find_Image(const TCHAR * pImgKey)
{
	auto		iter = find_if(m_mapBit.begin(), m_mapBit.end(), tagFinder(pImgKey));

	if (iter == m_mapBit.end())
		return nullptr;

	return iter->second->Get_MemDC();
}

template<typename T>
auto& lamDeleteMap = [&](T& Temp)
{ 
	if (Temp.second)
	{
		delete Temp.second;
		Temp.second = nullptr;
	}
};

void CResourceManager::Release(void)
{
	for_each(m_mapBit.begin(), m_mapBit.end(), CDeleteMap());
	m_mapBit.clear();
}
