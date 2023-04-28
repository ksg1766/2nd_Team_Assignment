#pragma once
#include <stack>
class CScene;
class CSceneManager
{
public:
	CSceneManager();

	void Initialize();
	void Load_Prev_Scene();
	void Load_Scene(CScene* _pCurrentScene);
	void Terminate_Scene();
	void Release();

	CScene* Get_Current_Scene() { return m_pCurrentScene; };
	void* Set_Current_Scene(CScene* _pCurrentScene) { m_pCurrentScene = _pCurrentScene; };

	~CSceneManager();

private:
	CScene*	m_pCurrentScene;
	stack<CScene*> m_sceneStack;
};

