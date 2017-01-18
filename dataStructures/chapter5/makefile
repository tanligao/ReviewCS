CC=g++
CFLAGS=-Wall -g
OBJ=main.o myHash.o
PROJ=myHash
$(PROJ):$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(PROJ) $(OBJ)