snake: main.o menuGame.o gamePlay.o 
	g++ main.o menuGame.o gamePlay.o -o snake

main.o: main.cpp
	g++ -c main.cpp

menuGame.o: menuGame.cpp menuGame.h
	g++ -c menuGame.cpp

gamePlay.o: gamePlay.cpp gamePlay.h
	g++ -c gamePlay.cpp

clean:
	rm -f *.o snake