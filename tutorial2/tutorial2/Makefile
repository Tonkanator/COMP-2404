all: Character.o battle.o main.cc
	g++ -o p1 Character.o battle.o main.cc

Character.o: Character.h Character.cc
	g++ -c Character.cc

battle.o: battle.h battle.cc
	g++ -c battle.cc

clean:
	rm -f p1 *.o
