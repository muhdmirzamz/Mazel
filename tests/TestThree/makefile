CXX=gcc
CFLAGS=-Wall -g -c
LFLAGS=-Wall -std=c++11 -lSDL2 -o
VPATH=TestThree

Game: main.o GameManager.o GameState.o MainMenu.o LevelOne.o
	$(CXX) $(LFLAGS) $@ $^

LevelOne.o: LevelOne.cpp
	$(CXX) $(CFLAGS) $^

MainMenu.o: MainMenu.cpp
	$(CXX) $(CFLAGS) $^

GameState.o: GameState.cpp
	$(CXX) $(CFLAGS) $^

GameManager.o: GameManager.cpp
	$(CXX) $(CFLAGS) $^

main.o: main.cpp
	$(CXX) $(CFLAGS) $^

clean:
	rm -rf *.o Game
