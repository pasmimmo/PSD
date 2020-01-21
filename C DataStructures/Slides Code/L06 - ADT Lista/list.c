#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"

struct node
{
    item value;
    struct node *next;
};

struct c_list
{
    struct node *first;
    int size;
};

list newList(void)
{
    struct c_list *list;
    list = malloc(sizeof(struct c_list));
    list->first = NULL;
    list->size = 0;
    return list;
}

int emptyList(list l)
{
    return l->size == 0;
}

list consList(item val, list l)
{
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    if (newNode != NULL)
    {
        newNode->value = val;
        newNode->next = l->first;
        l->first = newNode;
        l->size++;
    }
    return l;
}

list tailList(list l)
{
    struct node *garbageNode;
    garbageNode = l->first;
    l->first = l->first->next;
    l->size--;
    free(garbageNode);
    return l;
}

item getFirst(list l)
{
    item anItem = l->first->value;
    if (anItem == NULL)
        return NULLITEM;
    return anItem;
}

int sizeList(list l)
{
    if (l != NULL)
        return l->size;
    return -1;
}

int posItem(list l, item val)
{
    if (l == NULL || val == NULL)
        return -1;
    printf("sono in posItem\n%d\n", l->size);
    for (int i = 0; i < 3; i++)
    {
        printf("\n non trovato alla %d iterazione", i);
        item anItem = l->first->value;
        int eqq = eq(anItem, val);
        if (eqq == 1)
            return i;

        //l->first = l->first->next;
    }
    return -1;
}

item getItem(list l, int pos)
{
    if (l == NULL || pos < 0 || pos > l->size)
        return -1;
    list iterator = l;
    for (int i = 0; i <= pos; i++)
    {
        iterator->first = iterator->first->next;
    }
    if (iterator->first->value == NULL)
        return NULLITEM;
    return iterator->first->value;
}

list reverseList(list l)
{
    if (l == NULL)
        return -1;
    list reverse = newList();
    list iterator = l;
    for (int i = 0; i < iterator->size; i++)
    {
        consList(iterator->first->value, reverse);
        iterator->first = iterator->first->next;
    }
    return reverse;
}

void outputList(list l)
{
    list iterator = l;
    if (l == NULL || l->size < 1)
        printf("List not found!");
    for (int i = 0; i < iterator->size; i++)
    {
        printf("\n in position %d there is/are: \n", i);
        output_item(iterator->first->value);
        iterator->first = iterator->first->next;
    }
}

list inputList(int inputElemets)
{
    list newInputs = newList();
    for (int i = 0; i < inputElemets; i++)
    {
        consList(input_item(), newInputs);
    }
    return reverseList(newInputs);
}

//Ciao