#include <stdio.h>
#include <stdlib.h>
#include "item.h"

struct c_item
{
    int value;
};
item item_new(int x)
{
    item newItem = malloc(sizeof(struct c_item));
    newItem->value = x;
    return newItem;
}
int item_compare(item a, item b)
{
    if (a->value == b->value)
    {
        return 0;
    }
    else if (a->value > b->value || b == NULL)
    {
        return 1;
    }
    else if (a->value < b->value || a == NULL)
        return 2;
    else
        return -1;
}

item item_clone(item a)
{
    return item_new(a->value);
}

void item_print(item a)
{
    printf("item value = %d\n", a->value);
}
item item_input()
{
    printf("insert an item value\n");
    int value;
    scanf("%d", &value);
    return item_new(value);
}
int item_equals(item a, item b)
{
    if (item_compare(a, b) == 0)
        return 1;
    return 0;
}