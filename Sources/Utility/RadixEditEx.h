#pragma once
#include "RadixEdit.h"

class CRadixEditEx : public CRadixEdit
{
public:
	CRadixEditEx(void);
	virtual ~CRadixEditEx(void);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

