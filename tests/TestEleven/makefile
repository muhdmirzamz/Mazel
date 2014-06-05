CXX=g++
SDL_INCLUDE=-I/Users/muhdmirzamz/Documents/Code/Projects/CPPProjects/Mazel/tests/TestEleven/SDL2.framework/Versions/A/Headers
SDL_FRAMEWORK=-F/Users/muhdmirzamz/Documents/Code/Projects/CPPProjects/Mazel/tests/TestEleven -framework SDL2 

CFLAG=-c -Wall -std=c++11  $(SDL_INCLUDE)
LFLAG=-Wall $(SDL_FRAMEWORK) -o
VPATH=TestEleven

Game: main.o GameManager.o GameState.o RenderObject.o CollisionDetection.o MainMenu.o Level1.o Level2.o
	$(CXX) $(LFLAG) $@ $^

Level2.o: Level2.cpp
	$(CXX) $(CFLAG) $^

Level1.o: Level1.cpp
	$(CXX) $(CFLAG) $^

MainMenu.o: MainMenu.cpp
	$(CXX) $(CFLAG) $^

CollisionDetection.o: CollisionDetection.cpp
	$(CXX) $(CFLAG) $^

RenderObject.o: RenderObject.cpp
	$(CXX) $(CFLAG) $^

GameState.o: GameState.cpp
	$(CXX) $(CFLAG) $^

GameManager.o: GameManager.cpp
	$(CXX) $(CFLAG) $^

main.o: main.cpp
	$(CXX) $(CFLAG) $^

clean:
	rm -rf *.o Game
