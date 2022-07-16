#include "dll_address.h"
#include <string.h>
#include <stdlib.h>

// --------------------------------------------------------------------
// 변경 금지
// --------------------------------------------------------------------

// 초기화	--- 변경금지
void list_init(DoublyLinkedList* list)
{
	list->head = NULL;
	list->tail = NULL;
}

// 주소록 출력	--- 변경금지
void print_list(DoublyLinkedList* list)
{
	if (is_empty_list(list))
		printf("XXXXXXXXX 빈 주소록 XXXXXXXXXX\n");
	else
	{
		printf("--------------------------\n");
		printf("---- 주소록 출력 시작 ----\n");
		printf("--------------------------\n");
		printf("  학번 \t\t 이름\n");
		printf("--------------------------\n");
		Node* tmp = list->head;
		while (tmp != NULL)
		{
			printf("%d\t%s\n", tmp->id, tmp->name);
			tmp = tmp->next;
		}

		printf("\n\n");
	}
}
// --------------------------------------------------------------------

/*
* is_empty
* return true/false
*/
int cnt = 0;

bool is_empty_list(DoublyLinkedList* list)
{
	if(cnt == 0) {
		return true;
	}
	return false;
}

/*
* is_full
* return true/false
*/
bool is_full_list(DoublyLinkedList* list)
{
	if(cnt == MAX_ADDRESS_SIZE) {
		return true;
	}
	return false;

}

/*
* insert_head
* 리스트 앞에 삽입
* return 성공 0 / 실패 -1
*/
int insert_head(DoublyLinkedList* list, char* name, int id)
{
	if(is_full_list(list)) {
		return -1;
	}
	Node *New = (Node *)malloc(sizeof(Node));
	New->id = id;
	strcpy(New->name, name);
	if(is_empty_list(list)) {
		list->head = New;
		list->tail = New;
	} else {
		New->next = list->head;
		list->head->prev = New;
		list->head = New;
	}

	cnt += 1;
	return 0;

}

/*
* insert_head
* 리스트 뒤에 삽입
* return 성공 0 / 실패 -1
*/
int insert_tail(DoublyLinkedList* list, char* name, int id)
{
	if(is_full_list(list)) {
		return -1;
	}
	Node *New = (Node *)malloc(sizeof(Node));
    New->id = id;
	strcpy(New->name, name);
    if(is_empty_list(list)) {
        list->head = New;
        list->tail = New;        
    } else {
		New->prev = list->tail;
		list->tail->next = New;
		list->tail = New;
    }

	cnt += 1;
	return 0;

}

/*
* insert_head
* 리스트 앞에 삽입
* return 성공 0 / 실패 -1
*/
int delete_head(DoublyLinkedList* list) 
{
	if(is_empty_list(list)) {
        return -1;
    }
    Node *temp = (Node *)malloc(sizeof(Node));
    temp = list->head;
    list->head = list->head->next;
    free(temp);
    cnt -= 1;
    return 0;
}

/*
* insert_head
* 리스트 앞에 삽입
* return 성공 0 / 실패 -1
*/
int delete_tail(DoublyLinkedList* list)
{
	if(is_empty_list(list)) {
        return -1;
    }
    Node *temp = (Node *)malloc(sizeof(Node));
    temp = list->tail;
	list->tail = list->tail->prev;
    free(temp);
    cnt -= 1;
    return 0;

}

// ------------- 심화 ---------------
/*
* 학번으로 검색
* printf 출력 "이름"
* return 성공 0 / 실패 -1
*/
int search_name(DoublyLinkedList* list, int id)
{
	DoublyLinkedList* s = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
	memcpy(s, list, sizeof(DoublyLinkedList));
	if(is_empty_list(list)) {
		return -1;
	}
	for(int i = 0; i < cnt; i++) {
		if(s->head->id == id) {
			printf("%s\n", s->head->name);
		}
		s->head = s->head->next;
	}
	return 0;
}

/*
* 이름으로 검색 
* printf 출력 "학번" (해당이름 모든 학번 출력)
* return 성공 0 / 실패 -1
*/
int search_id(DoublyLinkedList* list, char* name)
{
	DoublyLinkedList* s = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
	memcpy(s, list, sizeof(DoublyLinkedList));
	if(is_empty_list(list)) {
		return -1;
	}
	for(int i = 0; i < cnt; i++) {
		if(strcmp(s->head->name, name)==0) {
			printf("%d\n", s->head->id);
		}
		s->head = s->head->next;

	}
	return 0;
}