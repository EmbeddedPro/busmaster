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
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CRadixEditEx::PreTranslateMessage(MSG* pMsg)
{
	//return CRadixEdit::PreTranslateMessage(pMsg);
	return true;
}

void CRadixEditEx::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CRadixEdit::OnChar(nChar, nRepCnt, nFlags);
}