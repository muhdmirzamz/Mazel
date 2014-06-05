CXX=g++
SDL_INCLUDE=-I/Users/muhdmirzamz/Documents/Code/Projects/CPPProjects/Mazel/tests/TestTen/SDL2.framework/Versions/A/Headers
SDL_FRAMEWORK=-F/Users/muhdmirzamz/Documents/Code/Projects/CPPProjects/Mazel/tests/TestTen -framework SDL2

CFLAGS=-c -Wall -std=c++11 $(SDL_INCLUDE)
LFLAGS=-Wall $(SDL_FRAMEWORK) -o
VPATH=TestTen

Game: main.o GameManager.o GameState.o RenderObject.o CollisionDetection.o MainMenu.o LevelOne.o LevelTwo.o
	$(CXX) $(LFLAGS) $@ $^
LevelTwo.o: LevelTwo.cpp
	$(CXX) $(CFLAGS) $^

LevelOne.o: LevelOne.cpp
	$(CXX) $(CFLAGS) $^

MainMenu.o: MainMenu.cpp
	$(CXX) $(CFLAGS) $^

CollisionDetection.o: CollisionDetection.cpp
	$(CXX) $(CFLAGS) $^

RenderObject.o: RenderObject.cpp
	$(CXX) $(CFLAGS) $^

GameState.o: GameState.cpp
	$(CXX) $(CFLAGS) $^

GameManager.o: GameManager.cpp
	$(CXX) $(CFLAGS) $^

main.o: main.cpp
	$(CXX) $(CFLAGS) $^

clean:
	rm -rf *.o Game
