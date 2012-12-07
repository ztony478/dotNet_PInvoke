#include "StdAfx.h"
#include "NameEntityFinder.h"

CNameEntityFinder::CNameEntityFinder(NameEntityType type)
{
	_type = type;
	wprintf(L"*Native*: NameEntity finder object is created.\n\n");
}

CNameEntityFinder::~CNameEntityFinder(void)
{
	wprintf(L"\n*Native*: NameEntity finder object is deleted.\n\n");
}

bool CNameEntityFinder::Initialize(const wchar_t* resourcePath)
{
	// 初始化对象
	wprintf(L"\n*Native*: NameEntity finder object is initialized.\n\n");
	return true;
}

void CNameEntityFinder::UnInitialize()
{
	// 释放对象模型资源
	wprintf(L"\n*Native*: NameEntity finder object is uninitialized.\n\n");
}

bool CNameEntityFinder::FindNames(const wchar_t* text, PNAMEENTITY* ppNameEntity, UINT* nameCount)
{
	wprintf(L"\n*Native*: NameEntity finder object is processing text.\n\n");
	// 调用核心算法处理输入的文字，并返回结果
	// 这里我们仅仅演示结果的输出
	*nameCount = PopulateResult(text, ppNameEntity);
	return true;
}

int CNameEntityFinder::PopulateResult(const wchar_t* text, PNAMEENTITY* ppNameEntity)
{
	int nameCount = 5;
	*ppNameEntity = (PNAMEENTITY)CoTaskMemAlloc(nameCount * sizeof(NAMEENTITY));
	memset(*ppNameEntity, 0, nameCount * sizeof(NAMEENTITY));
	PNAMEENTITY pCurNameEntity = *ppNameEntity;

	AddNameEntity(L"北京", 17, PlaceName, 0.8, pCurNameEntity);
	pCurNameEntity++;
	AddNameEntity(L"微软亚洲研究院", 21, OrganizationName, 0.9, pCurNameEntity);
	pCurNameEntity++;
	AddNameEntity(L"洪小文", 31, PersonName, 0.8, pCurNameEntity);
	pCurNameEntity++;
	AddNameEntity(L"王坚", 37, PersonName, 0.78, pCurNameEntity);
	pCurNameEntity++;
	AddNameEntity(L"郭百宁", 42, PersonName, 0.78, pCurNameEntity);

	return nameCount;
}


void CNameEntityFinder::AddNameEntity(const wchar_t* name, int beginPosition, NameEntityType type, double score, PNAMEENTITY pEntity)
{
	if(NULL != pEntity)
	{
		pEntity->_highlight_length = (int)wcslen(name);
		pEntity->_name = (WCHAR*)CoTaskMemAlloc((pEntity->_highlight_length + 1) * sizeof(WCHAR));
		wcscpy_s(pEntity->_name, (pEntity->_highlight_length + 1), name);
		pEntity->_highlight_begin = beginPosition;
		pEntity->_type = type;
		pEntity->_score = score;
	}
}


