
OBJS = Collection.o Array.o LList.o main.o


CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

Collection: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o Collection

Array.o: Array.cpp Array.h
	$(CC) $(CFLAGS) Array.cpp

LList.o: LList.cpp LList.h
	$(CC) $(CFLAGS) LList.cpp

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp

clean:
	\rm *.o Collection