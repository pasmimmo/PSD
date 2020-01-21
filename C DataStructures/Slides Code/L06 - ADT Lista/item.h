typedef struct studente *item;
#define NULLITEM NULL
int eq(item x, item y);
item input_item();
void output_item(item x);
item cloneItem(item x);
item createItem(char *nome, int matricola);

//Ciao