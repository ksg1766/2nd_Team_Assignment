#include "stdafx.h"
#include "PoolManager.h"
//#include "Managers.h"
//#include "SceneManager.h"
#include "Goomba.h"
//#include "Turtle.h"
#include "Scene.h"
#include <algorithm>

CPoolManager::CPoolManager()
{
}

void CPoolManager::Initialize()
{
	m_cMonsterPool = new MonsterPool;
	m_cMonsterPool->Initialize();
}

CPoolManager::~CPoolManager()
{
	Release();
}

void CPoolManager::Return_Monster(CObj * _cMonster)
{
	_cMonster->Set_State(STATE::DEAD);
	m_cMonsterPool->Get_MonsterPool()->push_back(_cMonster);
}

void CPoolManager::Release()
{
	m_cMonsterPool->Release();
	Safe_Delete(m_cMonsterPool);
}

CPoolManager::MonsterPool::~MonsterPool()
{
	Release();
}

void CPoolManager::MonsterPool::Initialize()
{
	for (int i = 0; i < iMaxMonsterPool; ++i)
	{
		CObj* _cMonster = new CGoomba;
		dynamic_cast<CGoomba*>(_cMonster)->Initialize();
		m_MonsterList.push_back(_cMonster);
	}
}

void CPoolManager::MonsterPool::Create_Monster(CObj* _pPlayer)
{
	auto& findByState = [&](CObj* _iter)
	{
		if (STATE::DEAD == _iter->Get_State())
			return _iter;
	};

	auto& iterMonster = find_if(m_MonsterList.begin(), m_MonsterList.end(), findByState);

	//(*iterMonster)->Set_Type(TYPE::MONSTER);

	(*iterMonster)->Set_InfoX(_pPlayer->Get_Info().fX + 150.f);
	(*iterMonster)->Set_InfoY(_pPlayer->Get_Info().fY - 10.f);
	(*iterMonster)->Set_State(STATE::DEFAULT);

	CManagers::instance().Scene()->Get_Current_Scene()->Get_ObjList(TYPE::MONSTER).push_back(*iterMonster);
	m_MonsterList.erase(iterMonster);
}

void CPoolManager::MonsterPool::Release()
{
	/*if(!(m_MonsterList.empty()))
	for(auto& iter = m_MonsterList.begin(); iter != m_MonsterList.end(); )
	{
	Safe_Delete<CObj*>(*iter);
	iter = m_MonsterList.erase(iter);
	}*/

	if (!(m_MonsterList.empty()))
		for (auto& iter : m_MonsterList)
		{
			Safe_Delete(iter);
		}

	m_MonsterList.clear();
}