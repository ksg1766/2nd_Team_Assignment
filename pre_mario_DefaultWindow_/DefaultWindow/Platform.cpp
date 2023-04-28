#include "stdafx.h"
#include "Platform.h"
#include "Block.h"
#include "Scene.h"
#include "Managers.h"
#include "SceneManager.h"

CPlatform::CPlatform()
{
}


CPlatform::~CPlatform()
{
}

void CPlatform::Initialize(void)
{
	//m_eType = TYPE::IMMORTAL;
	m_eState = STATE::DEFAULT;
	m_fSpeedX = 0.f;
	m_fSpeedY = 0.f;
	m_uMass = UINT32_MAX;

	m_pCurrentScene = CManagers::instance().Scene()->Get_Current_Scene();
	__super::Update_RectX();
	__super::Update_RectY();
	Create_Blocks();
}

void CPlatform::Fixed_Update(void)
{
}

int CPlatform::Update(void)
{
	return 0;
}

void CPlatform::Late_Update(void)
{
}

void CPlatform::Render(HDC hDC)
{
}

void CPlatform::Release(void)
{
}

void CPlatform::Create_Blocks()
{
	CBlock* pBlock = new CBlock;
	pBlock->Initialize();
	pBlock->Set_Type(TYPE::FRAGILE);
	pBlock->Set_InfoCX(50.f);
	pBlock->Set_InfoCY(50.f);


	int iNumOfBlocksX = (int)Get_Info().fCX / (int)pBlock->Get_Info().fCX;
	int iNumOfBlocksY = (int)Get_Info().fCY / (int)pBlock->Get_Info().fCY;

	if (iNumOfBlocksX && iNumOfBlocksY)
	{
		for (int j = 0; j < iNumOfBlocksY; ++j)
		{
			for (int i = 0; i < iNumOfBlocksX; ++i)
			{
				CBlock* pBlockInPlatform = pBlock->clone();
				pBlockInPlatform->Set_Type(Get_Type());
				pBlockInPlatform->Set_InfoX(m_tRect.left + 0.5f * pBlock->Get_Info().fCX + i * pBlock->Get_Info().fCX);
				pBlockInPlatform->Set_InfoY(m_tRect.top + 0.5f * pBlock->Get_Info().fCY + j * pBlock->Get_Info().fCY);
				m_pCurrentScene->Get_ObjList(TYPE::FRAGILE).push_back(pBlockInPlatform);
			}
		}
	}

	Safe_Delete(pBlock);
}
