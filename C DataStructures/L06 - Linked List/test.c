#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "item.h"

static void test_item();
static void test_list();

int main(int argc, char const *argv[])
{
    //test_item();
    test_list();
}

void test_item()
{
    printf("Test item.h library\n");
    item testItem = item_acquire();
    item testItem2 = item_create("Mimmo", 17);
    printf("item1 print\n");
    item_print(testItem);
    item_print(testItem2);
    item generated = item_clone(testItem);
    printf("results of compare between input items %d\n", item_compare(testItem, testItem2));
    printf("results of compare between cloned %d\n", item_compare(generated, testItem));
}

static void test_list()
{
    sList aList = List_new();
    item fixedItem = item_create("stringMagic", 17);
    aList = List_add(fixedItem, aList);
    for (int i = 0; i < 2; i++)
    {
        item anItem = item_acquire();
        aList = List_add(anItem, aList);
    }
    printf("List contains:\n");
    List_print(aList);
    printf("reverse list print contains: \n");
    List_print(List_reverse(aList));
    printf("list contains fixed item: %d\n\t\t\t\t1 mean TRUE, 0 mean FALSE\n", List_contains(fixedItem, aList));
    aList = List_removeItem(fixedItem, aList);
    printf("\n\nNow print list without fixed item\n");
    List_print(aList);
}