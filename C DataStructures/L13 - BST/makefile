
bst_test.out: bst.o item.o
	gcc bst_test.c bst.o item.o -o bst_test.out
#item_test.out: item.o
#	gcc item_test.c item.o -o item_test.out
bst.o: bst.c item.o
	gcc -c bst.c
item.o: item.c
	gcc -c item.c
clean:
	rm -f *.o
	rm -f *.gch
