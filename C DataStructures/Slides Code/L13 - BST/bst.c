#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "item.h"

static void deleteNode(sBST, item);

struct node
{
    item value;
    struct node *left;  //minore
    struct node *right; //maggiore
};

static sBST createLeaf(item elem)
{
    sBST newNode;
    newNode = malloc(sizeof(struct node));
    if (newNode != NULL)
    {
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->value = elem;
        return newNode;
    }
    return NULL;
}

sBST BST_new(void)
{
    return NULL;
}

int BST_empty(sBST T)
{
    return T == NULL;
}

int BST_contain(sBST T, item val)
{
    if (T == NULL)
        return 0;
    if (item_compare(val, T->value) == 0)
        return 1;
    if (item_compare(val, T->value) == 1)
        return (BST_contain(T->right, val));
    else if (item_compare(val, T->value) == 2)
        return (BST_contain(T->left, val));
}

sBST BST_insert(sBST T, item elem)
{
    if (T == NULL)
        T = createLeaf(elem);
    else if (item_compare(elem, T->value) == 1)
        T->right = BST_insert(T->right, elem);
    else if (item_compare(elem, T->value) == 2)
        T->left = BST_insert(T->left, elem);
    else if (item_compare(elem, T->value) == 0)
        printf("elemento gia presente\n");
    return T;
}

sBST BST_delete(sBST T, item elem)
{
    if (T == NULL || elem == NULL)
        return (sBST)-1;
    if (item_equals(elem, T->left->value) || item_equals(elem, T->right->value))
        deleteNode(T, elem);
    if (elem > T->value)
        BST_delete(T->right, elem);
    else
        BST_delete(T->left, elem);
    return T;
}

sBST BST_MaxNode(sBST T)
{
    if (T->right != NULL)
        T = BST_MaxNode(T->right);
    return T;
}

item BST_MaxValue(sBST T)
{
    if (T->right != NULL)
        T = BST_MaxNode(T->right);
    return T->value;
}

sBST BST_MinNode(sBST T)
{
    if (T->left != NULL)
        T = BST_MinNode(T->left);
    return T;
}

item BST_MinValue(sBST T)
{
    if (T->left != NULL)
        T = BST_MinNode(T->left);
    return T->value;
}

static void deleteNode(sBST T, item elem)
{
    sBST garbageNode;
    if (item_equals(elem, T->left->value)) //Cancello il nodo minore
    {
        garbageNode = T->left;
        T->left = garbageNode->right;
    }
    else
    {
        garbageNode = T->right;
        T->right = garbageNode->right;
    }
    sBST min = BST_MinNode(garbageNode->right);
    min->left = garbageNode->left;
    free(garbageNode);
}

void BST_print(sBST T)
{
    if (T != NULL)
    {
        item_print(T->value);
        BST_print(T->left);
        BST_print(T->right);
    }
}