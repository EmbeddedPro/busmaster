#include "RadixEditEx.h"

IMPLEMENT_DYNAMIC(CRadixEditEx, CEdit)

CRadixEditEx::CRadixEditEx(void)
{
}


CRadixEditEx::~CRadixEditEx(void)
{
}


BEGIN_MESSAGE_MAP(CRadixEditEx, CRadixEdit)
	//{{AFX_MSG_MAP(CRadixEditEx)
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_WM_GETDLGCODE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CRadixEditEx::PreTranslateMessage(MSG* pMsg)
{
	//return CRadixEdit::PreTranslateMessage(pMsg);
	return true;
}

void CRadixEditEx::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	bool isCtrlDown = (GetKeyState(VK_CONTROL) & 0x8000) == 0x8000;
	CRadixEdit::OnChar(nChar, nRepCnt, nFlags);
}

bool IsEdit(CWnd* pWnd)
{
	ASSERT(pWnd != NULL);
	HWND hWnd = pWnd->GetSafeHwnd();
	if (hWnd == NULL)
		return FALSE;

	TCHAR szClassName[6];
	return ::GetClassName(hWnd, szClassName, 6) &&
		_tcsicmp(szClassName, _T("Edit")) == 0;
}

void CRadixEditEx::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	{
		CRadixEdit::OnKeyDown(nChar, nRepCnt, nFlags);
	}
}

// CEditItem message handlers
UINT CRadixEditEx::OnGetDlgCode()
{
	UINT Code = CEdit::OnGetDlgCode();
	Code |= DLGC_WANTALLKEYS | DLGC_WANTCHARS | DLGC_WANTMESSAGE | DLGC_WANTARROWS | DLGC_HASSETSEL;
	return Code;
} // OnGetDlgCode

// intercept commands to add them to the history
LRESULT CRadixEditEx::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	bool isPressed = (GetKeyState(VK_CONTROL) & 0x8000) == 0x8000;
	bool bProcessed = false;
	switch (message)
	{
	case WM_KEYDOWN:
		if ((wParam == _T('A')) && isPressed)
		{
			SetSel(0, -1);
			bProcessed = true;
		}
		else if ((wParam == _T('Q')) && isPressed)
		{
			Copy();
			bProcessed = true;
		}
		else if ((wParam == _T('W')) && isPressed)
		{
			Paste();
			bProcessed = true;
		}
		else if((wParam == _T('K')) && isPressed)
		{
			Cut();
			bProcessed = true;
		}
		break;
	case WM_CUT:
		break;
	}
	return bProcessed ? TRUE : CEdit::WindowProc(message, wParam, lParam);
}

