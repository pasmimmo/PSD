main.out: main.o item.o list.o
	gcc main.o item.o list.o -o main.out
main.o: item.h list.h main.c
	gcc -c main.c
item.o: item.c
	gcc -c item.c
list.o: list.c
	gcc -c list.c
clean:
	rm -f *.o
