#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

struct generic_item
{
    char stringValue[20];
    int numericValue;
};

item item_create(char *string, int numeric)
{
    item anItem = malloc(sizeof(struct generic_item));
    strcpy(anItem->stringValue, string);
    anItem->numericValue = numeric;
    return anItem;
}

item item_clone(item anItem)
{
    return item_create(anItem->stringValue, anItem->numericValue);
}


/*Define in item structure a valute of comparison,
in our case "numericValue"*/
int item_compare(item x, item y)
{
    if (x->numericValue == y->numericValue)
        return 0;
    else if (x->numericValue > y->numericValue)
        return 1;
    else if (x->numericValue < y->numericValue)
        return 2;
    else
        return -1;
}

item item_acquire()
{
    int tempNumeric;
    char tempString[20];
    printf("Give me a String Value:\n");
    scanf("%s",tempString);
    printf("insert a Numeric Value\n");
    scanf("%d", &tempNumeric);
    item newItem=item_create(tempString, tempNumeric);
    return newItem;
}

void item_print(item x)
{
    printf("String Value is: %s\tNumeric Value is: %d\n", x->stringValue, x->numericValue);
}