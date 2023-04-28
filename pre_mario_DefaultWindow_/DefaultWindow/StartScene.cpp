#include "stdafx.h"
#include "StartScene.h"
#include "Managers.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "Scene1.h"

CStartScene::CStartScene()
{
}


CStartScene::~CStartScene()
{
}

void CStartScene::Initialize(void)
{
	CManagers::instance().Resource()->Insert_Bmp(L"../Image/BackGround/StartScene.bmp", L"StartScene");

}

void CStartScene::Fixed_Update(void)
{
}

void CStartScene::Update(void)
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		CScene* cScene1 = new CScene1;
		CManagers::instance().Scene()->Load_Scene(cScene1);
		//CManagers::instance().Scene()->Get_Current_Scene();
	}
}

void CStartScene::Late_Update(void)
{
}

void CStartScene::Render(HDC hDC)
{
	HDC		hMemDC = CManagers::instance().Resource()->Find_Image(L"StartScene");

	GdiTransparentBlt(hDC, 0, 0, 800, 600, hMemDC, 0, 0, 800, 600, RGB(255, 255, 255));
}

void CStartScene::Release(void)
{
}
