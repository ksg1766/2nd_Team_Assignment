#include "stdafx.h"
#include "SceneManager.h"
#include "Scene1.h"

CSceneManager::CSceneManager() : m_pCurrentScene(nullptr)
{
}

void CSceneManager::Initialize()
{
	
}

void CSceneManager::Load_Prev_Scene()
{
	m_pCurrentScene = m_sceneStack.top();
}

void CSceneManager::Load_Scene(CScene* _pNewScene)
{
	m_pCurrentScene = _pNewScene;
	m_pCurrentScene->Initialize();	// 초기 상태의 씬이 호출되는 점 주의
	if(!m_sceneStack.empty())
		m_sceneStack.top()->Release();
	m_sceneStack.push(m_pCurrentScene);
}

void CSceneManager::Terminate_Scene()
{
	m_pCurrentScene->Release();
	m_sceneStack.pop();
	if (!m_sceneStack.empty())
		Load_Prev_Scene();
	else
		;	// Terminate Game

}

void CSceneManager::Release()
{
	while (!m_sceneStack.empty())
	{
		Safe_Delete(m_sceneStack.top());
		m_sceneStack.pop();
	}
}

CSceneManager::~CSceneManager()
{
	Release();
}
