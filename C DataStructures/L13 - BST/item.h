typedef struct c_item *item;
#define NULLITEM NULL;
item item_new();
int item_compare(item a, item b);
item item_clone(item a);
void item_print(item a);
item item_input();
int item_equals(item a, item b);