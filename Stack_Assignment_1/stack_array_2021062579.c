#include "stack_array.h"

// --------------------------------------------------------------------
// ���� ����
// --------------------------------------------------------------------

// ���� �ʱ�ȭ
void stack_init_as(Array_Stack* stack)
{
    stack->top = -1;
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
bool is_empty_as(Array_Stack* stack)
{
    if(stack->top == -1)
	    return true;

    return false;    
}

/*
* ������ ����á���� Ȯ��, true/false ��ȯ
* ������ �ִ� ������ ������ MAX_STACK_SIZE
*/
bool is_full_as(Array_Stack* stack)
{
    if(stack->top == MAX_STACK_SIZE-1)
        return true;
    return false;

}

// ���ÿ� ���� ����
void push_as(Array_Stack* stack, int data)
{
    if(!is_full_as(stack)) {
	stack->top ++;
        stack->array[stack->top] = data;
	
    }

}

// ������ �ֻ��� ����(top)�� �����ϰ� ��ȯ
int pop_as(Array_Stack* stack)
{
    if(!is_empty_as(stack)) {
        int temp = stack->array[stack->top];
        stack->top --;
        return temp;   
    } else {
        
        return 0;
    }

}


// --------------------------------------------------------------------
// ��ȭ ���� ����
// --------------------------------------------------------------------

// ���� ���� ���� ���� ��ȯ
int get_stack_size_as(Array_Stack* stack)
{
    return stack->top +1;
}

// ������ �ֻ��� ����(top) �� ��ȯ
int get_top_as(Array_Stack* stack)
{
    if(!is_empty_as(stack))
        return stack->array[stack->top];
    
    return 0;
}

/*
* ������ �ֻ��� ���Һ��� ������� ��� (pop X)
* top ... bottom 
* ex) 5 10 12 4 3
*/
void print_stack_as(Array_Stack* stack)
{
    if(!(is_empty_as(stack)))
        for(int i = stack->top; i >= 0; i-- ) {
            printf("%d ", (stack->array[i]));
        }
 
}
