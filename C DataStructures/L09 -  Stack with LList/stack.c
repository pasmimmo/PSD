#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"

struct c_stack
{
    sList list;
};

/*Create new Stack, Stack is an LIFO - Last In First Out ADT*/
sStack Stack_new(void)
{
    struct c_stack *newStack = malloc(sizeof(struct c_stack));
    newStack->list = List_new();
    return newStack;
}

/*return 1 if stack is empty, 0 otherwise*/
int Stack_empty(sStack s)
{
    return List_empty(s->list);
}

/*insert an element into stack*/
sStack Stack_push(item anItem, sStack s)
{
    s->list = List_add(anItem, s->list);
    return s;
}

/*give a top element of stack Without removing it*/
item Stack_top(sStack s)
{
    return List_getFirst(s->list);
}

/*give a top element, removing it from stack*/
item Stack_pop(sStack s)
{
    item temp = List_getFirst(s->list);
    s->list = List_removeFirst(s->list);
    return temp;
}

/*Delete equals elements from stack*/
sStack Stack_elimDoppi(sStack s)
{
    sList worker = List_new();
    sStack newStack = Stack_new();
    for (int i = 0; i < List_size(s->list); i++)
    {
        item anItem = Stack_pop(s);

        if (List_contains(anItem, worker) == 0)
            worker = List_add(anItem, worker);
    }
    for (int i = 0; i < List_size(worker); i++)
    {
        newStack = Stack_push(List_getFirst(worker),newStack);
        worker = List_removeFirst(worker);
    }
    return newStack;
}

/*merge s1 and s2 stack, deleting 
elements contained in both */
sStack Stack_xorStack(sStack s1, sStack s2)
{
    sStack newStack = Stack_new();
    for (int i = 0; i < List_size(s1->list); i++)
    {
        item temp = Stack_pop(s1);
        newStack = Stack_push(temp, newStack);
    }
    for (int i = 0; i < List_size(s2->list); i++)
    {
        item temp = Stack_pop(s2);
        if (List_contains(temp, newStack->list) == 0)
            newStack = Stack_push(temp, newStack);
    }
    return newStack;
}
/*print given stack*/
void Stack_print(sStack s){
    List_print(List_reverse(s->list));
}