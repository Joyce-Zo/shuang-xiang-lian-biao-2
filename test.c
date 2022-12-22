#include "DList.h"

void testList1()
{
	LTNode* plist = ListInit();

	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);
	
	/*ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);*/

	//ListPushFront(plist, 1);
	//ListPushFront(plist, 2);

	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);
}

void testList2()
{
	LTNode* plist = ListInit();

	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);

	ListPushFront(plist, 1);

	ListPrint(plist);

	//LTNode* cur = ListFind(plist, 3);
	//////printf("%d ", cur->data);
	//// 
	////ListInsert(cur, 5);

	//ListErase(cur); 
	//ListPrint(plist);
}
int main()
{
	//testList1();
	testList2();
	return;
}