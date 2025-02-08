
test: test.cc TextArea.o HeapArrays.o StackArrays.o RGB.o
	g++ -o test test.cc TextArea.o HeapArrays.o StackArrays.o RGB.o -lX11

test2: test2.cc TextArea.o RGB.o
	g++ -o test2 test2.cc TextArea.o RGB.o -lX11
	
StackArrays.o:	StackArrays.h StackArrays.cc 
	g++ -c StackArrays.cc 
	
HeapArrays.o:	HeapArrays.h HeapArrays.cc 
	g++ -c HeapArrays.cc 

TextArea.o:	TextArea.h TextArea.cc
	g++ -c TextArea.cc 

RGB.o:	RGB.h RGB.cc
	g++ -c RGB.cc

	
clean:
	rm -f test test2 *.o
