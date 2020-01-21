test.out: test.c stack.o list.o item.o
	gcc test.c stack.o list.o item.o -o test.out
stack.o: stack.c list.o item.o
	gcc -c stack.c
list.o: list.c item.o
	gcc -c list.c
item.o: item.c 
	gcc -c item.c
clean:
	rm -f *.o
	rm -f *.gch