#include "stdafx.h"
#include "SListAdapters.h"

//TVListAdapter///////////////////////////////////////////////////////////////////////////
void CTreeViewAdapter::getView(HSTREEITEM hItem, SItemPanel* pItem, SXmlNode xmlTemplate) {
	if (pItem->GetChildrenCount() == 0)
	{
		pItem->InitFromXml(&xmlTemplate);
	}
	ItemInfo& ii = m_tree.GetItemRef(hItem);
	SWindow* pWnd = pItem->FindChildByID(R.id.btn_test);
	pWnd->GetEventSet()->subscribeEvent(EVT_CMD, Subscriber(&CTreeViewAdapter::OnItemClick, this));

	pWnd->SetWindowText(S_CW2T(ii.data.pszPath));
	SToggle* pSwitch = pItem->FindChildByID2<SToggle>(R.id.tgl_switch);

	SWindow* pTxtRed = pItem->FindChildByID(R.id.txt_red);
	pTxtRed->SetWindowText(SStringT().Format(L"µ±Ç°Öµ%d", ii.data.leng));

	pSwitch->SetVisible(HasChildren(hItem));
	pSwitch->SetToggle(IsItemExpanded(hItem));
	pSwitch->GetEventSet()->subscribeEvent(EVT_CMD, Subscriber(&CTreeViewAdapter::OnSwitchClick, this));
}


BOOL  CTreeViewAdapter::OnItemClick(IEvtArgs* pEvt)
{
	SItemPanel* pItem = sobj_cast<SItemPanel>(((SWindow*)pEvt->Sender())->GetRoot());
	HSTREEITEM hItem = (HSTREEITEM)pItem->GetItemIndex();
	ItemInfo& ii = m_tree.GetItemRef(hItem);
	if (ii.data.leng > 100)
	{
		ii.data.leng -= 100;
	}
	else
	{
		ii.data.leng += 100;
	}
	this->notifyBranchChanged(hItem);
	return true;
}

BOOL  CTreeViewAdapter::OnSwitchClick(IEvtArgs* pEvt)
{
	SToggle* pToggle = sobj_cast<SToggle>(pEvt->Sender());
	SASSERT(pToggle);
	SItemPanel* pItem = sobj_cast<SItemPanel>(pToggle->GetRoot());
	SASSERT(pItem);
	HSTREEITEM hItem = (HSTREEITEM)pItem->GetItemIndex();
	ExpandItem(hItem, TVC_TOGGLE);
	return true;
}



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
