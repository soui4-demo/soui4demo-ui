// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainDlg.h"	
#include <helper/SMenuEx.h>


CMainDlg::CMainDlg() : SHostWnd(_T("LAYOUT:XML_MAINWND"))
{
}

CMainDlg::~CMainDlg()
{
}

BOOL CMainDlg::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	SShellTray* notify = FindChildByName2<SShellTray>(L"menu");
	if (notify) {
		notify->SetToolTipText(GETSTRING(L"@string/title"));
	}
	SListCtrl* pLsct = FindChildByName2<SListCtrl>(R.name.lsct1);
	if (pLsct) {
		for (int i = 0; i < 20; i++)
		{
			int index = pLsct->InsertItem(0, L"主内容");
			pLsct->SetItemData(index, i + 1);
			pLsct->SetSubItemText(index, 1, L"内容1");
			pLsct->SetSubItemText(index, 2, L"内容2");
			pLsct->SetSubItemText(index, 3, L"内容3");
		}
	}
	SMCListView* pMcV = FindChildByName2<SMCListView>(R.name.mclv1);
	if (pMcV) {
		CMcAdapterList* pAdapter = static_cast<CMcAdapterList*>(pMcV->GetAdapter());
		bool isRelease = false;
		if (!pAdapter)
		{
			isRelease = true;
			pAdapter = new CMcAdapterList();
		}
		for (int i = 0; i < 20; i++)
		{
			CMcAdapterList::SOFTINFO info = { i + 1,L"内容" };
			pAdapter->addItem(info);
		}

		pMcV->SetAdapter(pAdapter);
		if (isRelease)
			pAdapter->Release();
	}
	STreeCtrl* pTrcl = FindChildByName2<STreeCtrl>(R.name.treectrl1);
	if (pTrcl) {
		for (int i = 0; i < 20; i++)
		{
			HSTREEITEM index = pTrcl->GetRootItem();
			pTrcl->InsertItem(SStringT().Format(L"内容%d", i+1), index);
			pTrcl->SetItemData(index, i + 1);
		}
	}
	STreeView* pTV = FindChildByName2<STreeView>(R.name.treeview1);
	if (pTV) {
		CTreeViewAdapter* pAdapter = static_cast<CTreeViewAdapter*>(pTV->GetAdapter());
		bool isRelease = false;
		if (!pAdapter)
		{
			isRelease = true;
			pAdapter = new CTreeViewAdapter();
		}
		TreeItemData data;
		data.pszPath = L"name root";
		data.leng = 100;
		HSTREEITEM hRoot = pAdapter->InsertItem(data);
		for (int i = 0; i < 20; i++)
		{
			data.pszPath = L"name root child";
			data.leng = i + 1;
			pAdapter->InsertItem(data, hRoot);
		}

		pTV->SetAdapter(pAdapter);
		if (isRelease)
			pAdapter->Release();
	}
	return 0;
}
//TODO:消息映射
void CMainDlg::OnClose()
{
	SShellTray* notify = FindChildByName2<SShellTray>(L"menu");
	if (notify) {
		notify->Destroy();
	}

	SNotifyCenter::getSingleton().removeAllEvents();
	SNativeWnd::DestroyWindow();
}

void CMainDlg::OnMaximize()
{
	SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE);
}
void CMainDlg::OnRestore()
{
	SendMessage(WM_SYSCOMMAND, SC_RESTORE);
}
void CMainDlg::OnMinimize()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

void CMainDlg::OnSize(UINT nType, CSize size)
{
	SetMsgHandled(FALSE);
	SWindow* pBtnMax = FindChildByName(L"btn_max");
	SWindow* pBtnRestore = FindChildByName(L"btn_restore");
	if (!pBtnMax || !pBtnRestore) return;

	if (nType == SIZE_MAXIMIZED)
	{
		pBtnRestore->SetVisible(TRUE);
		pBtnMax->SetVisible(FALSE);
	}
	else if (nType == SIZE_RESTORED)
	{
		pBtnRestore->SetVisible(FALSE);
		pBtnMax->SetVisible(TRUE);
	}
}


//演示如何响应菜单事件
void CMainDlg::OnCommand(UINT uNotifyCode, int nID, HWND wndCtl)
{
	if (uNotifyCode == 0)
	{
		switch (nID)
		{
		case 2:
			OnClose();
			break;
		case 6:
			PostMessage(WM_CLOSE);
			break;
		default:
			break;
		}
	}
}


void CMainDlg::OnShellTrayNotify(IEvtArgs* e)
{
	EventTrayNotify* e2 = sobj_cast<EventTrayNotify>(e);
	SShellTray* pTray = sobj_cast<SShellTray>(e->Sender());
	switch (e2->lp)
	{
	case WM_LBUTTONDOWN:
		if (IsWindowVisible())
		{
			ShowWindow(SW_HIDE);
		}
		else
		{
			ShowWindow(SW_SHOW);
			if (IsIconic())
			{
				OnRestore();
			}
		}
		break;
	case WM_RBUTTONDOWN:
	{
		SMenuEx menu;
		if (menu.LoadMenu(_T("SMENU:menu_tray")))
		{
			POINT pt;
			GetCursorPos(&pt);
			SetForegroundWindow(m_hWnd);
			menu.TrackPopupMenu(0, pt.x, pt.y, m_hWnd);
		}
	}
	break;
	}
}

