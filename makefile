bst: bst.o BST.o
	g++ bst.o BST.o -o bst

bst.o: bst.cpp
	g++ -c bst.cpp

BST.o: includes/BST.cpp
	g++ -c includes/BST.cpp

clean:
	rm *.o bst