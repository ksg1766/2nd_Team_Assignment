#pragma once#pragma once

#include "Managers.h"
#include "SceneManager.h"

class CObj;
class CPoolManager
{
public:
	CPoolManager();
	~CPoolManager();

	void Initialize();
	void Create_Monster(CObj* _cFrom) { m_cMonsterPool->Create_Monster(_cFrom); }
	void Return_Monster(CObj* _cBullet);
	int Monster_in_Pool() { return m_cMonsterPool->Monster_in_Pool(); }
	void Release();

private:
	class MonsterPool
	{
	public:
		~MonsterPool();

		list<CObj*>* Get_MonsterPool() { return &m_MonsterList; }
		 
		void Initialize();
		void Create_Monster(CObj* _pPlayer);
		void Release();
		int	Monster_in_Pool() { return m_MonsterList.size(); }

	private:
		static const int iMaxMonsterPool = 255;
		list<CObj*> m_MonsterList;
	};

private:
	MonsterPool* m_cMonsterPool;
};
