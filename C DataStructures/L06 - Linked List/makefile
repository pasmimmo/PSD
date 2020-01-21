test.out: test.o item.o list.o
	gcc test.o item.o list.o -o test.out
test.o: item.o list.o test.c
	gcc -c test.c
list.o: list.c item.o
	gcc -c list.c
item.o: item.c 
	gcc -c item.c
clean:
	rm -f *.o
	rm -f *.gch
	rm -f *.out
