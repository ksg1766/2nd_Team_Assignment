#include "stdafx.h"
#include "Managers.h"
#include "SceneManager.h"
#include "PoolManager.h"
#include "InputComponent.h"
#include "ScrollManager.h"
#include "ResourceManager.h"

void CManagers::Initialize()
{
	m_pScroll = new CScrollManager;
	m_pScene = new CSceneManager;
	m_pResource = new CResourceManager;
	m_pPool = new CPoolManager;
	m_pPool->Initialize();
}

void CManagers::Release()
{
	Safe_Delete(m_pScroll);
	Safe_Delete(m_pScene);
	Safe_Delete(m_pPool);
	Safe_Delete(m_pResource);
}

CManagers::CManagers()
{
}


CManagers::~CManagers()
{
	Release();
}
