#include "deque.h"
#include <stdlib.h>


// --------------------------------------------------------------------
// 변경 금지
// --------------------------------------------------------------------

// 초기화
void deque_init(LinkedList_Deque* deque)
{
    deque->front = NULL;
    deque->rear = NULL;
}

// --------------------------------------------------------------------


/*
* 구현시 유의사항
* 1. 함수명과 매개변수는 수정하시지 마세요.
* 2. 반환값 정확하게 구현해주세요. (bool, int)
* 3. 발생할 수 있는 모든 예외사항을 처리해주세요. (underflow/overflow)
*/

// --------------------------------------------------------------------
// Deque 구현
// --------------------------------------------------------------------

// true/false 반환
int count = 0;

bool is_empty_deque(LinkedList_Deque* deque)
{
    if(count == 0) {
        return true;
    } else {
        return false;
    }
}

// true/false 반환
bool is_full_deque(LinkedList_Deque* deque)
{
    if (count == MAX_DEQUE_SIZE) {
        return true;
    } else {
        return false;
    }
    
}


// Input 성공 : 0 반환 / 실패 : -1 반환
int addfront_deque(LinkedList_Deque* deque, int data)
{
    if(is_full_deque(deque)) {
        return -1;
    }

    Node_Deque *New = (Node_Deque *)malloc(sizeof(Node_Deque));
    New->data = data;
    if(is_empty_deque(deque)) {
        deque->front = New;
        deque->rear = New;        
    } else {
        New->next = deque->front;
        deque->front = New;
    }
    
    count += 1;
    return 0;
    
}

int addrear_deque(LinkedList_Deque* deque, int data)
{
    if(is_full_deque(deque)) {
        return -1;
    } 
    Node_Deque *New = (Node_Deque *)malloc(sizeof(Node_Deque));
    New->data = data;
    if(is_empty_deque(deque)) {
        deque->front = New;
        deque->rear = New;        
    } else {
        deque->rear->next = New;
        deque->rear = deque->rear->next;
    }
    
    count += 1;
    return 0;
    
}

// Output 성공 : Output 값 반환 / 실패 : -1 반환
int delfront_deque(LinkedList_Deque* deque)
{
    if(is_empty_deque(deque)) {
        return -1;
    }
    Node_Deque *temp = (Node_Deque *)malloc(sizeof(Node_Deque));
    temp = deque->front;
    int x = temp->data;
    deque->front = deque->front->next;
    free(temp);
    count -= 1;
    return x;

}

int delrear_deque(LinkedList_Deque* deque)
{
    if(is_empty_deque(deque)) {
        return -1;
    }
    Node_Deque *temp = (Node_Deque *)malloc(sizeof(Node_Deque));
    Node_Deque *a = (Node_Deque *)malloc(sizeof(Node_Deque));
    temp = deque->rear;
    a = deque->front;
    int x = temp->data;
    for(int i = 0; i<count-2; i++) {
        a = a->next;
    }
    deque->rear = a;
    free(temp);
    count -= 1;
    return x;

}