#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "item.h"

int main(int argc, char const *argv[])
{
    sBST albero = BST_new();
    
    for(int i=0;i<11;i++){
        albero=BST_insert(albero,item_input());
    }
    BST_print(albero);
    printf("max value is:");
    item_print(BST_MaxValue(albero));
    printf("min value is:");
    item_print(BST_MinValue(albero));
    return 0;
}
