
# If you are compiling natively on a mac, you will need to use the following flags.
# When you are compiling your executable: 
#
#     g++ $(macflag) -o <exectuable> <source files> $(maclib)
#
# For example:
#
# 	  g++ $(macflag) -o a1 main.o Panel.o Button.o CuWindow.o Tester.o $(maclib)
#
# When you are compiling your object files:
#
#	  g++ $(macflag) -c <source file> $(macinclude)
#
# macinclude is used to include the X11 library, if you have installed it using XQuartz.
# maclib is used to link the X11 library, if you have installed it using XQuartz.
# macflag is used to enable C++11 features, which are required for this assignment.

macflag    = -std=c++11 				
macinclude = -I /opt/X11/include 
maclib     = -L /opt/X11/lib 

# Put your Makefile instructions below.
all: a1

a1: RGB.o Button.o Panel.o CuWindow.o Tester.o main.o
	g++ -o a1 RGB.o Button.o Panel.o CuWindow.o Tester.o main.o -lX11

RGB.o: defs.h RGB.h RGB.cc
	g++ -c RGB.cc

Button.o: defs.h Button.h Button.cc
	g++ -c Button.cc

Panel.o: defs.h Panel.h Panel.cc
	g++ -c Panel.cc

CuWindow.o: defs.h CuWindow.h CuWindow.cc
	g++ -c CuWindow.cc

Tester.o: defs.h Tester.h Tester.cc
	g++ -c Tester.cc

main.o: defs.h main.cc
	g++ -c main.cc

clean:
	rm -f a1 *.o