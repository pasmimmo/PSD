#include "item.h"
typedef struct node *sBST;
// prototipi
sBST BST_new();

int BST_empty(sBST T);
int BST_contain(sBST T, item elem);

sBST BST_insert(sBST T, item elem);
sBST BST_delete(sBST T, item elem);

item BST_MinValue(sBST T);
item BST_MaxValue(sBST T);
sBST BST_MinNode(sBST T);
sBST BST_MaxNode(sBST T);

void BST_print(sBST T);
