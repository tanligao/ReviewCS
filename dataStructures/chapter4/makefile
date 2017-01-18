CC=g++
CFLAGS=-Wall -g
PROJ=BSTree
OBJ=main.o BinarySearchTree.o
$(PROJ):$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(PROJ) $(OBJ)