#observe - Linux is case sensitive. These names should match your filenames exactly

all: test
	
test: test.o RGB.o 
	g++ -o test test.o RGB.o 
		
test.o: test.cc RGB.h
	g++ -c test.cc

RGB.o:	RGB.h RGB.cc 
	g++ -c RGB.cc 

clean:
	rm -f test *.o
