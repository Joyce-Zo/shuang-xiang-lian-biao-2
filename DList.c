#include "DList.h"

LTNode*  ListInit()
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

LTNode* BuyListNode(LTDateType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->next = newnode->prev = NULL;
	return newnode;
}

void ListPrint(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushBack(LTNode* phead, LTDateType x)
{
	assert(phead);
	// 1.
	/*LTNode* tail = phead->prev;
	LTNode* newnode = BuyListNode(x);

	tail->next = newnode;
	newnode->prev = tail;
	phead->prev = newnode;
	newnode->next = phead;*/

	// 2.
	ListInsert(phead, x);
}

void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);// 防止把哨兵位删了

	LTNode* tail = phead->prev;
	LTNode* tailprev = tail->prev;
	phead->prev = tailprev;
	tailprev->next = phead;

	free(tail);
}

void ListPushFront(LTNode* phead, LTDateType x)
{
	assert(phead);
	// 1.
	/*LTNode* next = phead->next;
	LTNode* newnode = BuyListNode(x);

	phead->next = newnode;
	newnode->prev = phead;
	 
	newnode->next = next;
	next->prev = newnode;*/
	
	// 2.
	ListInsert(phead->next, x);
}

void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);

	// 1.
	//LTNode* next = phead->next;
	//phead->next = next->next;
	//next->next->prev = phead;
	//free(next);
	//2. 差别不大
	LTNode* next = phead->next;
	LTNode* nextNext = next->next;
	free(next);
	phead->next = nextNext;
	nextNext->prev = phead;
}


LTNode* ListFind(LTNode* phead, LTDateType x)
{
	assert(phead);
	LTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
			return cur;
		else if (cur->next == phead)
			return NULL;
		cur = cur->next;
	}
}

void ListInsert(LTNode* pos, LTDateType x)// 在pos节点之前插入
{
	assert(pos);
	LTNode* newnode = BuyListNode(x);
	LTNode* prev = pos->prev;
	prev->next = newnode;
	newnode->prev = prev;

	newnode->next = pos;
	pos->prev = newnode;
}


void ListErase(LTNode* pos)// 删除pos节点
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	free(pos);
	prev->next = next;
	next->prev = prev;
}