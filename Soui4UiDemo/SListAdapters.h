#pragma once
#include "helper/SAdapterBase.h"
typedef struct
{
	SStringW pszPath;
	int leng;
} TreeItemData;
class CTreeViewAdapter : public STreeAdapterBase<TreeItemData>
{
public:
	virtual void WINAPI getView(HSTREEITEM hItem, SItemPanel* pItem, SXmlNode xmlTemplate);
	BOOL OnItemClick(IEvtArgs* pEvt);
	BOOL OnSwitchClick(IEvtArgs* pEvt);
};


class CMcAdapterList : public SMcAdapterBase
{
public:
	typedef struct
	{
		int leng;
		SStringW pszPath;
	} SOFTINFO;
	SArray<SOFTINFO> m_softInfo;
public:
	STDMETHOD_(SStringW, GetColumnName)(int iCol) SCONST
	{
		return SStringW().Format(L"col%d", iCol + 1);
	}
	STDMETHOD_(int, getCount)() OVERRIDE
	{
		return m_softInfo.GetCount();
	}
	virtual void WINAPI getView(int position, SItemPanel* pItem, SXmlNode xmlTemplate);


	void addItem(SOFTINFO info) { m_softInfo.Add(info); };
	int getLeng(int position) { return m_softInfo.GetAt(position).leng; }
	SStringW getPath(int position) { return m_softInfo.GetAt(position).pszPath; }
	BOOL OnItemDBClick(IEvtArgs* pEvt);
};


