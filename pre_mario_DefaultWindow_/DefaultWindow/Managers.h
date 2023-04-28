#pragma once

class CScrollManager;
class CInputManager;
class CSceneManager;
class CPoolManager;
class CResourceManager;
class CManagers
{
public:
	static CManagers& instance()	// Singleton
	{
		static CManagers*	m_instance = new CManagers();
		return *m_instance;
	}

	void Initialize();
	void Release();

	CScrollManager*		Scroll()	{ return m_pScroll; }
	CSceneManager*		Scene()		{ return m_pScene; }
	CPoolManager*		Pool()		{ return m_pPool; }
	CResourceManager*	Resource()	{ return m_pResource; }

private:
	CManagers();
	~CManagers();

	static CManagers*	m_instance;

	CScrollManager*		m_pScroll;
	CSceneManager*		m_pScene;
	CPoolManager*		m_pPool;
	CResourceManager*	m_pResource;
};

