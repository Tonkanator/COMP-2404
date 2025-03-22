all: test
	
test: test.o Component.o ComponentList.o Panel.o FlowPanel.o AbsolutePanel.o Tester.o
	g++ -o test -std=c++11  test.o Component.o ComponentList.o Panel.o FlowPanel.o AbsolutePanel.o Tester.o -lX11 -L /opt/X11/lib

test.o:	test.cc 
	g++ -c test.cc -I /opt/X11/include
	
Component.o:	Component.h Component.cc ComponentList.o
	g++ -c Component.cc -I /opt/X11/include

ComponentList.o:	ComponentList.h ComponentList.cc Panel.o
	g++ -c ComponentList.cc  -I /opt/X11/include

Panel.o:	Panel.h Panel.cc
	g++ -c Panel.cc -I /opt/X11/include

FlowPanel.o:  FlowPanel.h FlowPanel.cc Panel.o
	g++ -c FlowPanel.cc -I /opt/X11/include

AbsolutePanel.o:  AbsolutePanel.h AbsolutePanel.cc Panel.o
	g++ -c AbsolutePanel.cc -I /opt/X11/include

Tester.o:	Tester.h Tester.cc
	g++ -c Tester.cc
	
clean:
	rm -f test *.o
