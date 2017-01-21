CC=g++
CFLAGS=-Wall -g
OBJ=main.o NQueue.o
PROJ=NQueue
$(PROJ):$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(PROJ) $(OBJ)