#pragma once

struct DNODE {
	int key;
	DNODE* pNext;
	DNODE* pPrev;
};
	DNODE* pHead;
	DNODE* pTail;
};
bool removeElement(DList* &L, int key);