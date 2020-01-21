#include <stdlib.h>
#include <stdio.h>
#include "item.h"

int main(int argc, char const *argv[])
{
    item anItem=item_new(5);
    item anOtherItem = item_input();
    int res= item_equals(anItem,anOtherItem);
    printf("sono uguali: %d\n",res);
    item_print(anItem);
    return 0;
}
