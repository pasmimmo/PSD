#include "item.h"
typedef struct c_list *list;
// prototipi
list newList(void);
int emptyList(list l);
list tailList(list l);
list consList(item val, list l);
item getFirst(list l);
int sizeList(list l);
void outputList(list l);
list reverseList(list l);
int posItem(list l, item val);
//Ciao