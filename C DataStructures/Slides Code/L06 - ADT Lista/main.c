#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char const *argv[])
{
    list paper = newList();
    item anItem = input_item();
    consList(anItem, paper);
    printf("sono uguali %d", eq(getFirst(paper), anItem));

    consList(input_item(), paper);
    consList(input_item(), paper);
    printf("nella lista ci sono %d elementi\n", sizeList(paper));
    outputList(reverseList(paper));
    printf("%d", emptyList(paper));
    printf("ci sono %d elementi\n", sizeList(paper));
    printf("marco sta in posizione %d", posItem(paper, anItem));
    return 0;
}
