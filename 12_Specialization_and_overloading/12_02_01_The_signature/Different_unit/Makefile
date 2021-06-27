APID=Different_unit

.phony:clean

OBJ = The_signature1.o The_signature2.o
CC=g++

all:$(OBJ)
	$(CC) $(OBJ) -o $(APID)
	@rm -rf *.o

%.o:%.cpp
	$(CC) -g -c $< 

clean:
	@rm -rf $(APID)
