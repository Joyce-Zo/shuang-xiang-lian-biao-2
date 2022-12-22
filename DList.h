#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDateType;

typedef struct LTNode
{
	LTDateType data;
	struct LTNode* next;
	struct LTNode* prev;
}LTNode;

LTNode*  ListInit();

LTNode* BuyListNode(LTDateType x);

void ListPrint(LTNode* phead);

void ListPushBack(LTNode* phead, LTDateType x);

void ListPopBack(LTNode* phead);

void ListPushFront(LTNode* phead, LTDateType x);

void ListPopFront(LTNode* phead);

LTNode* ListFind(LTNode* plist, LTDateType x);

void ListInsert(LTNode* pos, LTDateType x);

void ListErase(LTNode* pos);