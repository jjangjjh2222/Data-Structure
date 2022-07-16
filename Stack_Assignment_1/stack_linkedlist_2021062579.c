#include "stack_linkedlist.h"
#include <stdlib.h>
#include <string.h>

// --------------------------------------------------------------------
// ���� ����
// --------------------------------------------------------------------

// ���� �ʱ�ȭ
void stack_init_ls(LinkedList_Stack* stack)
{
    stack->top = NULL;
}

// --------------------------------------------------------------------

/*
* ������ ���ǻ���
* 1. �Լ����� �Ű������� �����Ͻ��� ������.
* 2. ��ȯ�� ��Ȯ�ϰ� �������ּ���. (bool, int)
*/

// --------------------------------------------------------------------
// ���� ���� ���� - ��� ���� B
// --------------------------------------------------------------------

// ������ ����ִ��� Ȯ��, true/false ��ȯ
bool is_empty_ls(LinkedList_Stack* stack)
{
    if(stack->top == NULL) {
        return true;
    }
    return false;
}

/*
* ������ ����á���� Ȯ��, true/false ��ȯ
* ������ �ִ� ������ ������ MAX_STACK_SIZE
*/
bool is_full_ls(LinkedList_Stack* stack)
{
    LinkedList_Stack* count = malloc(sizeof(LinkedList_Stack));
    memcpy(count, stack, sizeof(LinkedList_Stack));
    
    for(int i=0; i<MAX_STACK_SIZE; i++) {
        if(count->top == NULL) {
            return false;
        } else {
            count->top = count->top->next;
        }
    }
    return true;

    
}

// ���ÿ� ���� ����
void push_ls(LinkedList_Stack* stack, int data)
{
    Node* temp = (Node *)malloc(sizeof(Node));
    temp -> data = data;
    temp -> next = stack -> top;
    stack -> top = temp;
}

// // ������ �ֻ��� ����(top)�� �����ϰ� ��ȯ
int pop_ls(LinkedList_Stack* stack)
{
    if(!is_empty_ls(stack)) {
        Node* temp = stack -> top;
        int data = temp -> data;
        stack -> top = temp -> next;
        free(temp);
	    return data;
    } 

    return 0;
}


// --------------------------------------------------------------------
// ��ȭ ���� ����
// --------------------------------------------------------------------

// ���� ���� ���� ���� ��ȯ
int get_stack_size_ls(LinkedList_Stack* stack)
{
    LinkedList_Stack* s = (LinkedList_Stack*)malloc(sizeof(LinkedList_Stack));
    memcpy(s, stack, sizeof(LinkedList_Stack));
    int num = 0;
    
    for(int i=0; i<MAX_STACK_SIZE; i++) {
        if(s->top == NULL) break;
        else {
            s->top = s->top->next;
            num++;
	}
    }
    return num;
}

// ������ �ֻ��� ����(top) �� ��ȯ
int get_top_ls(LinkedList_Stack* stack)
{
    return stack->top->data;
    
}

/*
* ������ �ֻ��� ���Һ��� ������� ��� (pop X)
* top ... bottom
* ex) 5 10 12 4 3
*/
void print_stack_ls(LinkedList_Stack* stack)
{
    struct LinkedList_Stack* count = (LinkedList_Stack*)malloc(sizeof(LinkedList_Stack));
    memcpy(count, stack, sizeof(LinkedList_Stack));
    
    for(int i=0; i<MAX_STACK_SIZE; i++) {
        if(count->top == NULL) break;
        else {
            printf("%d ", count->top->data);
            count->top = count->top->next;
	    }
    }

}
