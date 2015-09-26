main: test_binarytree.o binarytree.o
	gcc test_binarytree.o binarytree.o -o test_binarytree
test_binarytree.o: test_binarytree.c
	gcc -c test_binarytree.c

binarytree.o: binarytree.c
	gcc -c binarytree.c

clean:
	-rm test_binarytree *.o
