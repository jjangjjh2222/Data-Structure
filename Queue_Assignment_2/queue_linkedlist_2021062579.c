#include "queue_linkedlist.h"
#include <stdlib.h>


// --------------------------------------------------------------------
// 변경 금지
// --------------------------------------------------------------------

// 초기화
void queue_init_lq(LinkedList_Queue* queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

// --------------------------------------------------------------------


/*
* 구현시 유의사항
* 1. 함수명과 매개변수는 수정하시지 마세요.
* 2. 반환값 정확하게 구현해주세요. (bool, int)
* 3. 발생할 수 있는 모든 예외사항을 처리해주세요.  (underflow/overflow)
*/

// --------------------------------------------------------------------
// Queue 구현
// --------------------------------------------------------------------

// true/false 반환
int cnt = 0;

bool is_empty_lq(LinkedList_Queue* queue)
{
    if(cnt == 0) {
        return true;
    }
    return false;
    
    
}

// true/false 반환
bool is_full_lq(LinkedList_Queue* queue)
{

    if(cnt == MAX_QUEUE_SIZE_LL) {
        return true;
    }
    return false;
    
}   

// Enqueue 성공 : 0 반환 / 실패 : -1 반환
int enqueue_lq(LinkedList_Queue* queue, int data)
{
    
    if(is_full_lq(queue)) {
        return -1;
    }

    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if(is_empty_lq(queue)) {
         queue->front = queue->rear = temp;
    } else {
        queue->rear->next = temp;
        queue->rear = queue->rear->next;
        
    }
    cnt += 1;
    return 0;

    
}

// Dequeue 성공 : Dequeue 값 반환 / 실패 : -1 반환
int dequeue_lq(LinkedList_Queue* queue)
{
    if(is_empty_lq(queue)) {
        return -1;
    } else {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp = queue->front;
        int x = temp->data;
        queue->front = temp->next;
        free(temp);
        cnt -= 1;
        return x;
    }
    
}
