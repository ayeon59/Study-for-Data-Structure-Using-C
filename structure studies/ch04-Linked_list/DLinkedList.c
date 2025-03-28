#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List * plist){
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp=NULL;
	plist->numOfData = 0;
} 
/*for initiallize Node*/

void FInsert(List *plist, LData data){
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numOfData)++;
}

/*for add a newNode*/

void SInsert(List *plist, LData data){

}

void LInsert(List *plist, LData data){
	if(plist->comp == NULL) /*if there isn't rule, just insert*/
	FInsert(plist,data);
	else 
	SInsert(plist,data);
}

int LFirst(List * plist, LData *pdata){
	if(plist->head->next== NULL) return FALSE;

	plist->before=plist->head;
	plist->cur=plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, LData *pdata){
	if(plist->cur->next== NULL) return FALSE;

	plist->before=plist->cur;
	plist->cur=plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List *plist){
	Node * rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist){
	return plist->numOfData;
}

int main(){
	List list;
	int data;
	ListInit(&list);

	LInsert(&list,11);
	LInsert(&list,11);
	LInsert(&list,22);
	LInsert(&list,22);
	LInsert(&list,33);

	printf("현재 데이터의 수 : %d \n",LCount(&list));

	if(LFirst(&list,&data)){
		printf("%d ",data);

		while(LNext(&list,&data)) printf("%d ",data);
	}
	printf("\n\n");

	if(LFirst(&list,&data)){
		if(data==22) LRemove(&list);

		while(LNext(&list,&data)) {
			if(data==22) LRemove(&list);
		}
	}
	printf("현재 데이터의 수 : %d \n",LCount(&list));
	printf("\n\n");

	if(LFirst(&list,&data)){
		printf("%d ",data);

		while(LNext(&list,&data)) printf("%d ",data);
	}
	printf("\n\n");
}