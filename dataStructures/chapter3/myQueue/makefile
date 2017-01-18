CC=g++
CFLAGS=-Wall -g
OBJ=main.o myQueue.o
PROJ=myQueue
$(PROJ):$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(PROJ) $(OBJ)