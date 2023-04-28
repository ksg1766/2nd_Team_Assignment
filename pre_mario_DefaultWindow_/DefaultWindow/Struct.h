#pragma once

typedef struct tagInfo
{
	float	fX;
	float	fY;
	float	fCX;
	float	fCY;
}INFO;

struct tagFinder
{
public:
	tagFinder(const TCHAR* pString) : m_pString(pString) {}

public:
	template<typename T>
	bool	operator()(T& MyPair)
	{
		return !lstrcmp(m_pString, MyPair.first);
	}

private:
	const TCHAR* m_pString;
};

//const TCHAR* m_pString = ;
//template<typename T>
//auto& lamFinder = [&](T& MyPair) { return !lstrcmp(m_pString, MyPair.first); };

struct CDeleteMap
{
	template<typename T>
	void operator()(T& Temp)
	{
		if (Temp.second)
		{
			delete Temp.second;
			Temp.second = nullptr;
		}
	}
};