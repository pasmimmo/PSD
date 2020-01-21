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

static int findItemPosition(item anItem, sList list);

sList List_new(void)
{
    struct c_list *list;
    list = malloc(sizeof(struct c_list));
    list->first = NULL;
    list->size = 0;
    return list;
}

sList List_add(item anItem, sList list)
{
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    if (newNode == NULL)
        return -1;
    newNode->next = list->first;
    newNode->value = anItem;
    list->first = newNode;
    list->size++;
    return list;
}

sList List_removeItem(item anItem,sList list)
{
    sList tempList = List_new();
    struct node *iterator=list->first;
    for (int i = 0; i < list->size; i++)
    {
        if (item_compare(iterator->value, anItem) != 0)
            tempList = List_add(iterator->value, tempList);
        iterator=iterator->next;
    }
    tempList = List_reverse(tempList);
    return tempList;
}

int List_empty(sList list)
{
    return list->size == 0;
}

int List_size(sList list)
{
    if (list->first == NULL || list == NULL)
        return -1;
    return list->size;
}

item List_getFirst(sList list)
{
    if (list == NULL || list->first == NULL)
        return NULLITEM;
    item anItem = list->first->value;
    return anItem;
}

sList List_removeFirst(sList list)
{
    if (list->first == NULL || list == NULL)
        return -1;
    struct node *garbageNode;
    garbageNode = list->first;
    list->first = list->first->next;
    list->size--;
    free(garbageNode);
    return list;
}

sList List_reverse(sList list)
{
    if (list == NULL || list->first == NULL)
        return -1;
    sList reverse = List_new();
    struct node *iterator = list->first;
    for (int i = 0; i < List_size(list); i++)
    {
        item temp = iterator->value;
        iterator = iterator->next;
        reverse = List_add(temp, reverse);
    }
    return reverse;
}

int List_contains(item anItem, sList list)
{
    if (findItemPosition(anItem, list) >= 0)
        return 1;
    return 0;
}

void List_print(sList list)
{
    list = List_reverse(list);
    struct node *iterator = list->first;
    for (int i = 0; i < list->size; i++)
    {
        item_print(iterator->value);
        iterator=iterator->next;
    }
}

static int findItemPosition(item anItem, sList list)
{
    struct node *iterator=list->first;
    if (list == NULL || anItem == NULL)
        return -1;
    for (int i = 0; i < list->size; i++)
    {
        if (item_compare(iterator->value, anItem) == 0)
            return i;
        iterator=iterator->next;
    }
    return -1;
}

/* Legacy code
sList List_clone(sList list)
{
    sList newList = List_new();
    struct node *pointer = list->first;
    for (int i = 0; i < list->size; i++)
    {
        newList = List_add(pointer->value, newList);
        pointer = pointer->next;
    }
    return newList;
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
*/