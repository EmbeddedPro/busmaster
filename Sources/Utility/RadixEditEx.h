#pragma once
#include "RadixEdit.h"

class CRadixEditEx : public CRadixEdit
{
	DECLARE_DYNAMIC(CRadixEditEx);
public:
	CRadixEditEx(void);
	virtual ~CRadixEditEx(void);
	BOOL PreTranslateMessage(MSG* pMsg);

protected:

	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	DECLARE_MESSAGE_MAP()
};

