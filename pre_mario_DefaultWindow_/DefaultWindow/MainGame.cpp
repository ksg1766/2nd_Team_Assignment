#include "stdafx.h"
#include "MainGame.h"
#include "Managers.h"
#include "SceneManager.h"
#include "StartScene.h"
#include "Scene1.h"
#include "ResourceManager.h"
#include "PoolManager.h"
#include "Player.h"
CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize(void)
{
	m_DC = GetDC(g_hWnd);
	CManagers::instance().Initialize();

	CScene* cStartScene = new CStartScene;
	//CScene* cScene1 = new CScene1;
	
	CManagers::instance().Scene()->Load_Scene(cStartScene);
	//CManagers::instance().Scene()->Load_Scene(cScene1);
	//m_pCurrentScene = cScene1;
	
	CManagers::instance().Resource()->Insert_Bmp(L"../Image/BackGround/BackBuffer.bmp", L"BackBuffer");

	m_iUpdateCount = 0;
	m_iFixedUpdateCount = 0;
}

void CMainGame::Fixed_Update(void)
{
	CManagers::instance().Scene()->Get_Current_Scene()->Fixed_Update();

	++m_iFixedUpdateCount;
}

void CMainGame::Update(void)
{
	CManagers::instance().Scene()->Get_Current_Scene()->Update();

	++m_iUpdateCount;
}

void CMainGame::Late_Update(void)
{
	CManagers::instance().Scene()->Get_Current_Scene()->Late_Update();
}

void CMainGame::Render()
{
	//Rectangle(m_DC, 0, 0, WINCX, WINCY);

	HDC		hMemDC = CManagers::instance().Resource()->Find_Image(L"BackBuffer");
	BitBlt(m_DC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

	TCHAR	szFixedUpdateCount[32] = L"";
	RECT	rc1{ 640, 40, 790, 70 };
	swprintf_s(szFixedUpdateCount, L"FixedU : %d", m_iFixedUpdateCount);

	TCHAR	szUpdateCount[32] = L"";
	RECT	rc2{ 640, 10, 790, 40 };
	swprintf_s(szUpdateCount, L"Update : %d", m_iUpdateCount);

	TCHAR	szMonsterInScene[32] = L"";
	RECT	rc3{ 640, 70, 790, 100 };
	swprintf_s(szMonsterInScene, L"MonsterInScene : %d", CManagers::instance().Scene()->Get_Current_Scene()->Get_ObjList(TYPE::MONSTER).size());

	TCHAR	szMonsterInPool[32] = L"";
	RECT	rc4{ 640, 100, 790, 130 };
	swprintf_s(szMonsterInPool, L"MonsterInPool : %d", CManagers::instance().Pool()->Monster_in_Pool());

	TCHAR	szWorldTime[32] = L"";
	RECT	rc5{ 160, 40, 290, 70 };
	swprintf_s(szWorldTime, L"WorldTime : %d", CManagers::instance().Scene()->Get_Current_Scene()->Get_WorldTime() / 1000);
	//
	/*TCHAR	szPlayerSpeedY[32] = L"";
	RECT	rc3{ 680, 70, 790, 100 };
	CObj* _tempPlayer = CManagers::instance().Scene()->Get_Current_Scene()->Get_ObjList(TYPE::PLAYER).front();
	swprintf_s(szPlayerSpeedY, L"SpeedY : %f", _tempPlayer->Get_SpeedY());*/

	DrawText(m_DC, szFixedUpdateCount, lstrlen(szFixedUpdateCount), &rc1, DT_LEFT);
	DrawText(m_DC, szUpdateCount, lstrlen(szUpdateCount), &rc2, DT_LEFT);
	DrawText(m_DC, szMonsterInScene, lstrlen(szMonsterInScene), &rc3, DT_LEFT);
	DrawText(m_DC, szMonsterInPool, lstrlen(szMonsterInPool), &rc4, DT_LEFT);
	DrawText(m_DC, szWorldTime, lstrlen(szWorldTime), &rc5, DT_LEFT);

	CManagers::instance().Scene()->Get_Current_Scene()->Render(hMemDC);
}

void CMainGame::Release(void)
{
	//Safe_Delete<CObj*>(m_pPlayer);
	CManagers::instance().Release();
	ReleaseDC(g_hWnd, m_DC);
	//Safe_Delete();
	
}

