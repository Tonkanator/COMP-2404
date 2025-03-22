objects = test.o Search.o Media.o

all: test

test: $(objects)
	g++ -o test $(objects)

test.o: test.cc Search.h Media.h
	g++ -c test.cc 

Search.o: Search.h Search.cc
	g++ -c Search.cc
	
Media.o: Media.cc Media.h
	g++ -c Media.cc

clean:
	rm -f test *.o	

