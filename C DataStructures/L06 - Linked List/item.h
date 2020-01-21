typedef struct generic_item *item;
#define NULLITEM NULL

//Create an item, BE CARE TO ADAPT SIGNATURE
item item_create(char *string,int numeric);

//Clone a given item to another one
item item_clone(item anItem);

/*Compare two item and return:
    0 if them are equal, 
    1 il first is greater than second, 
    2 if  second is greater,
    -1 if error occur*/
int item_compare(item x, item y);

//acquire item from scanf
item item_acquire();

//print a given item
void item_print(item x);