#include "stdafx.h"
#include "SListAdapters.h"





//McListAdapter///////////////////////////////////////////////////////////////////////////

void CMcAdapterList::getView(int position, SItemPanel* pItem, SXmlNode xmlTemplate)
{
	if (pItem->GetChildrenCount() == 0)
	{
		pItem->InitFromXml(&xmlTemplate);
	}
	SOFTINFO* psi = m_softInfo.GetData() + position;
	pItem->GetEventSet()->subscribeEvent(EVT_ITEMPANEL_DBCLICK, Subscriber(&CMcAdapterList::OnItemDBClick, this));
	SWindow* pWin = pItem->FindChildByName(R.name.col_text1);
	if (pWin)
	{
		pWin->SetWindowTextW(SStringT().Format(L"%d", psi->leng));
	}
	pWin = pItem->FindChildByName(R.name.col_text2);
	if (pWin)
	{
		pWin->SetWindowTextW(psi->pszPath);
	}
}

BOOL CMcAdapterList::OnItemDBClick(IEvtArgs* pEvt)
{
	SItemPanel* item = sobj_cast<SItemPanel>(pEvt->Sender());
	if (item)
	{
		int iItem = item->GetItemIndex();
		m_softInfo.RemoveAt(iItem);
	}
	notifyDataSetChanged();
	return false;
}

/////////////////////////////////////////////////////////////////////////////
