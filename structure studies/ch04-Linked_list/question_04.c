#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


typedef int LData;

typedef struct _node{
    LData data;
    struct _node * next ;
}Node;

typedef struct _list{
    Node * head;
    Node * before;
    Node * cur;
    int numOfData;

} List;

void ListInit(List *plist){
    plist->head = (Node*)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->cur = NULL;
    plist->numOfData = 0;
}

void FInsert(List *plist,LData data){
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head->next;
    plist->head->next = newNode;

    (plist->numOfData)++;
}

void LInsert(List *plist,LData data){
    FInsert(plist,data);
}

int LMove(List *plist, LData *pdata)
{
    // 최초 호출 (LFirst 역할)
    if (plist->cur == NULL)
    {
        if (plist->head->next == NULL) // 빈 리스트
            return FALSE;

        plist->before = plist->head;
        plist->cur = plist->head->next;
    }
    else
    {
        if (plist->cur->next == NULL) // 다음 노드 없음
            return FALSE;

        plist->before = plist->cur;
        plist->cur = plist->cur->next;
    }

    *pdata = plist->cur->data;
    return TRUE;
}


/*
int LFirst(List * plist, LData * pdata)
{
	if(plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
    if(plist->head)
	if(plist->cur->next == NULL)
		return FALSE;


	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}*/

int main(){
    List list;
    int data;
    ListInit(&list);

    LInsert(&list,11);
    LInsert(&list,22);
    LInsert(&list,33);
    LInsert(&list,44);
    LInsert(&list,55);

    while(LMove(&list, &data)){
        printf("%d \n", data);
    }

}