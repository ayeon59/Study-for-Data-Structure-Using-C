#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

typedef int LData; /*int=LData*/

typedef struct _node{ /*struct _node=Node*/
	LData data;
	struct _node * next;
} Node; /*Node is box having an int and a pointer */

typedef struct _linkedList{
	Node * head;
	Node * cur;
	Node * before;
	int numOfData ;
	int (*comp)(LData d1, LData d2);
} LinkedList;

/*int (*comp) is pointer for function. 
That is, it is a way to swap in different functions later 
based on what you need it to do."*/

typedef LinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

void SetSortRule(List *plist ,int(*comp)(LData d1,LData d2));

#endif