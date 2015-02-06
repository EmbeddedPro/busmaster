#include "RadixEditEx.h"


CRadixEditEx::CRadixEditEx(void)
{
}


CRadixEditEx::~CRadixEditEx(void)
{
}

BOOL CRadixEditEx::PreTranslateMessage(MSG* pMsg)
{
	return CRadixEdit::PreTranslateMessage(pMsg);
}
