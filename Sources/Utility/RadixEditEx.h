#pragma once
#include "RadixEdit.h"

class CRadixEditEx : public CRadixEdit
{
	DECLARE_DYNAMIC(CRadixEditEx);
public:
	CRadixEditEx(void);
	virtual ~CRadixEditEx(void);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);


protected:

	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg UINT OnGetDlgCode();

	DECLARE_MESSAGE_MAP()
};

