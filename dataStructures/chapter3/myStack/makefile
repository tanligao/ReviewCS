CC=g++
CFLAGS=-Wall -g
OBJ=main.o myStack.o
PROJ=myStack
$(PROJ):$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(PROJ) $(OBJ)