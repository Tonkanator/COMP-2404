objects = test9.o Media.o

all: test9

test9: $(objects)
	g++ -o test9 $(objects)

test9.o: test9.cc Array.h Media.h 
	g++ -c test9.cc 

Media.o: Media.cc Media.h 
	g++ -c Media.cc

clean:
	rm -f test9 *.o	

