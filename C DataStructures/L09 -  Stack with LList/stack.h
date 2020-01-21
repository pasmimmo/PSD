#include "item.h"

typedef struct c_stack *sStack;

sStack Stack_new(void);

int Stack_empty(sStack s);

sStack Stack_push(item anItem,sStack s);

item Stack_pop(sStack s);

item Stack_top(sStack s);

void Stack_print(sStack s);


sStack Stack_elimDoppi(sStack s);

sStack Stack_xorStack(sStack s1, sStack s2);