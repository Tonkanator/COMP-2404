all: test

test:	test.o Student.o Algorithms.o TestClass.o
	g++ -o test test.o Student.o TestClass.o Algorithms.o

test.o:	test.cc Student.h 
	g++ -c test.cc

TestClass.o:	TestClass.cc TestClass.h
	g++ -c TestClass.cc

Algorithms.o:	Algorithms.cc Algorithms.h
	g++ -c Algorithms.cc

Student.o:	Student.cc Student.h
	g++ -c Student.cc

clean:
	rm -f *.o test
