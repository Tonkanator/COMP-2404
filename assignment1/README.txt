Tony Zheng
101305951

Files:

Makefile

defs.h - contains predefined colours and max array size
RGB.h
Button.h
Panel.h
CuWindow.h
Tester.h

RGB.cc
Button.cc
Panel.cc
CuWindow.cc
Tester.cc 
main.cc - In the studentTests() function, I have made four configurations where each has 2 panels and 2 panels. However, two of the configurations are used to test the overlaps() function of a button and the overlaps() function of a panel. This means that if their respective overlaps functions are working properly, than the second button or panel will not be added to the buttons or panels array, displaying only one button or panel.

Compilation and Execution
1. In the terminal, navigate to the assignment folder containing all of the files
2. Run the "make" command to compile and create an executable file called "a1"
3. Enter "./a1" to run the executable file