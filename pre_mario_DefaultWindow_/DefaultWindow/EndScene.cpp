#include "stdafx.h"
#include "EndScene.h"
#include "Managers.h"
#include "StartScene.h"
#include "SceneManager.h"
#include "ResourceManager.h"

CEndScene::CEndScene()
{
}


CEndScene::~CEndScene()
{
}

void CEndScene::Initialize(void)
{
	CManagers::instance().Resource()->Insert_Bmp(L"../Image/BackGround/GameOver.bmp", L"GameOver");
}

void CEndScene::Fixed_Update(void)
{
}

void CEndScene::Update(void)
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		CScene* pStartScene = new CStartScene;
		CManagers::instance().Scene()->Load_Scene(pStartScene);
		//CManagers::instance().Scene()->Get_Current_Scene();
	}
}

void CEndScene::Late_Update(void)
{
}

void CEndScene::Render(HDC hDC)
{
	HDC		hMemDC = CManagers::instance().Resource()->Find_Image(L"GameOver");

	GdiTransparentBlt(hDC, 0, 0, 800, 600, hMemDC, 0, 0, 800, 600, RGB(255, 255, 255));
}
