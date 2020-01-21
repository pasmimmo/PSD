#include "item.h"
typedef struct c_list *sList;

sList List_new(void);

sList List_add(item anItem, sList list);
sList List_removeItem(item anItem,sList list);

int List_empty(sList list);
int List_size(sList list);

item List_getFirst(sList list);
sList List_removeFirst(sList list);
sList List_reverse(sList list);
int List_contains(item anItem, sList list);

void List_print(sList list);