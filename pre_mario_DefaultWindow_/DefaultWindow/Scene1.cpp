#include "stdafx.h"
#include "Scene1.h"
#include "EndScene.h"
#include "Player.h"
#include "Block.h"
#include "Platform.h"
#include "Goomba.h"
#include "Trigger.h"
#include "Managers.h"
#include "PoolManager.h"
#include "ResourceManager.h"

CScene1::CScene1()
{
}


CScene1::~CScene1()
{
}

void CScene1::Initialize(void)
{
	m_fGravity = 4.9f;

	CObj* pPlayer = new CPlayer;
	pPlayer->Initialize();
	pPlayer->Set_InfoX(400);
	pPlayer->Set_InfoY(550);
	m_cObjList[(int)TYPE::PLAYER].push_back(pPlayer);

	CManagers::instance().Resource()->Insert_Bmp(L"../Image/Object/Block.bmp", L"Block");
	CManagers::instance().Resource()->Insert_Bmp(L"../Image/BackGround/BackGround.bmp", L"BackGround");
	//CManagers::instance().Resource()->Insert_Bmp(L"../Image/Object/MediumGround.bmp", L"MGround");
	CManagers::instance().Resource()->Insert_Bmp(L"../Image/Object/Goomba.bmp", L"Goomba");

	CObj* pGround = new CBlock;
	pGround->Initialize();
	pGround->Set_Type(TYPE::IMMORTAL);
	pGround->Set_InfoX(1000);
	pGround->Set_InfoY(575);
	pGround->Set_InfoCX(2000);
	pGround->Set_InfoCY(50);
	m_cObjList[(int)TYPE::IMMORTAL].push_back(pGround);

	CObj* pLeftWall = new CPlatform;
	pLeftWall->Set_Type(TYPE::IMMORTAL);
	pLeftWall->Set_InfoX(25);
	pLeftWall->Set_InfoY(250);
	pLeftWall->Set_InfoCX(50);
	pLeftWall->Set_InfoCY(600);
	pLeftWall->Initialize();
	//m_cObjList[(int)TYPE::IMMORTAL].push_back(pLeftWall);

	CObj* pRightWall = new CBlock;
	pRightWall->Initialize();
	pRightWall->Set_Type(TYPE::IMMORTAL);
	pRightWall->Set_InfoX(1975);
	pRightWall->Set_InfoY(250);
	pRightWall->Set_InfoCX(50);
	pRightWall->Set_InfoCY(600);
	m_cObjList[(int)TYPE::IMMORTAL].push_back(pRightWall);

	CObj* pBlock1 = new CPlatform;
	pBlock1->Set_Type(TYPE::FRAGILE);
	//pBlock1->Set_Mass(10);
	pBlock1->Set_InfoCX(200);
	pBlock1->Set_InfoCY(50);
	pBlock1->Set_InfoX(400);
	pBlock1->Set_InfoY(450);
	pBlock1->Initialize();
	//m_cObjList[(int)TYPE::FRAGILE].push_back(pBlock1);

	CManagers::instance().Pool()->Create_Monster(m_cObjList[(int)TYPE::PLAYER].front());

	CObj* pTrigger = new CTrigger;
	pTrigger->Initialize();
	pTrigger->Set_InfoY(400);
	m_cObjList[(int)TYPE::TRIGGER].push_back(pTrigger);

	CObj* pPlatform1 = new CPlatform;
	pPlatform1->Set_Type(TYPE::FRAGILE);
	pPlatform1->Set_InfoX(500);
	pPlatform1->Set_InfoY(450);
	pPlatform1->Set_InfoCX(100);
	pPlatform1->Set_InfoCY(50);
	pPlatform1->Initialize();

	CObj* pPlatform2 = new CPlatform;
	pPlatform2->Set_Type(TYPE::FRAGILE);
	pPlatform2->Set_InfoX(700);
	pPlatform2->Set_InfoY(500);
	pPlatform2->Set_InfoCX(250);
	pPlatform2->Set_InfoCY(50);
	pPlatform2->Initialize();

	CObj* pPlatform3 = new CPlatform;
	pPlatform3->Set_Type(TYPE::FRAGILE);
	pPlatform3->Set_InfoX(800);
	pPlatform3->Set_InfoY(325);
	pPlatform3->Set_InfoCX(100);
	pPlatform3->Set_InfoCY(100);
	pPlatform3->Initialize();

	CObj* pTrigger2 = new CTrigger;
	pTrigger2->Initialize();
	pTrigger2->Set_InfoX(1000);
	pTrigger2->Set_InfoY(275);
	pTrigger2->Set_InfoCY(400);
	m_cObjList[(int)TYPE::TRIGGER].push_back(pTrigger2);

	CObj* pPlatform5 = new CPlatform;
	pPlatform5->Set_Type(TYPE::FRAGILE);
	pPlatform5->Set_InfoX(1100);
	pPlatform5->Set_InfoY(450);
	pPlatform5->Set_InfoCX(150);
	pPlatform5->Set_InfoCY(50);
	pPlatform5->Initialize();

	CObj* pPlatform6 = new CPlatform;
	pPlatform6->Set_Type(TYPE::FRAGILE);
	pPlatform6->Set_InfoX(1300);
	pPlatform6->Set_InfoY(400);
	pPlatform6->Set_InfoCX(200);
	pPlatform6->Set_InfoCY(50);
	pPlatform6->Initialize();

	CObj* pPlatform7 = new CPlatform;
	pPlatform7->Set_Type(TYPE::FRAGILE);
	pPlatform7->Set_InfoX(1450);
	pPlatform7->Set_InfoY(350);
	pPlatform7->Set_InfoCX(300);
	pPlatform7->Set_InfoCY(50);
	pPlatform7->Initialize();

	CObj* pPlatform8 = new CPlatform;
	pPlatform8->Set_Type(TYPE::FRAGILE);
	pPlatform8->Set_InfoX(1600);
	pPlatform8->Set_InfoY(250);
	pPlatform8->Set_InfoCX(100);
	pPlatform8->Set_InfoCY(100);
	pPlatform8->Initialize();

	CObj* pPlatform9 = new CPlatform;
	pPlatform9->Set_Type(TYPE::FRAGILE);
	pPlatform9->Set_InfoX(1700);
	pPlatform9->Set_InfoY(500);
	pPlatform9->Set_InfoCX(200);
	pPlatform9->Set_InfoCY(100);
	pPlatform9->Initialize();

	CObj* pTrigger3 = new CTrigger;
	pTrigger3->Initialize();
	pTrigger3->Set_InfoX(1775);
	pTrigger3->Set_InfoY(300);
	pTrigger3->Set_InfoCX(250);
	pTrigger3->Set_InfoCY(50);
	m_cObjList[(int)TYPE::TRIGGER].push_back(pTrigger3);

	CObj* pTriggerEnd = new CBlock;
	pTriggerEnd->Initialize();
	pTriggerEnd->Set_InfoX(1900);
	pTriggerEnd->Set_InfoY(500);
	pTriggerEnd->Set_InfoCX(100);
	pTriggerEnd->Set_InfoCY(100);
	m_cObjList[(int)TYPE::TRIGGER].push_back(pTriggerEnd);

	m_WorldTime = 0;
}

void CScene1::Fixed_Update(void)
{
	m_WorldTime += 10;
	for (int i = 0; i < (int)TYPE::END; ++i)
	{
		for (auto& iter : m_cObjList[i])
			iter->Fixed_Update();
	}
}

void CScene1::Update(void)
{
	if (!CManagers::instance().Pool()->Monster_in_Pool())
	{
		for (auto& iter : m_cObjList[(int)TYPE::MONSTER])
		{
			CManagers::instance().Pool()->Return_Monster(iter);
		}
		CScene* pEndScene = new CEndScene;
		pEndScene->Initialize();
		CManagers::instance().Scene()->Load_Scene(pEndScene);
	}

	for (int i = 0; i < (int)TYPE::END; ++i)
	{
		for (auto& iter : m_cObjList[i])
			iter->Update();
	}
}

void CScene1::Late_Update(void)
{
	for (int i = 0; i < (int)TYPE::END; ++i)
	{
		for (auto& iter : m_cObjList[i])
			iter->Late_Update();
	}

	for (int i = 0; i < (int)TYPE::END; ++i)
	{
		for (auto& iter = m_cObjList[i].begin(); iter != m_cObjList[i].end();)
		{
			if (STATE::DEAD == (*iter)->Get_State())
			{
				//Safe_Delete(*iter);	// CPoolManager->Return_Monster();
				CManagers::instance().Pool()->Return_Monster(*iter);
				iter = m_cObjList[i].erase(iter);
			}
			else
				++iter;
		}
	}
}

void CScene1::Render(HDC hDC)
{
	HDC		hMemDC = CManagers::instance().Resource()->Find_Image(L"BackGround");

	GdiTransparentBlt(hDC,
		0, // 복사받을 x위치의 좌표
		0, // 복사 받을 y위치의 좌표)
		800, // 복사 받을 가로 길이
		600, // 복사 받을 세로 길이
		hMemDC,	// 복사할 비트맵 이미지 dc
		0,		// 비트맵을 출력할 시작 x좌표
		0,		// 비트맵을 출력할 시작 y좌표
		800, // 복사할 비트맵의 가로 사이즈
		600,// 복사할 비트맵의 세로 사이즈
		RGB(255, 255, 255)); //제거하고자 하는 색상


	for (int i = 0; i < (int)TYPE::END; ++i)
	{
		for (auto& iter : m_cObjList[i])
		{
			iter->Render(hDC);
		}
	}
}

void CScene1::Release(void)
{
	//for (int i = 0; i < (int)TYPE::END; ++i)
	//{
	//	for (auto& iter : m_cObjList[i])
	//		Safe_Delete(iter);
	//	m_cObjList[i].clear();
	//}
}
