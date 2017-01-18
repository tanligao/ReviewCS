CC=g++
CFLAGS=-Wall -g -std=c++11
PROJ=myTable
OBJ=main.o myList.o myDoubleList.o
$(PROJ):$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(PROJ) $(OBJ)