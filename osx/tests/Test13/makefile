CXX=g++

SDL_INCLUDE=-I/Users/muhdmirzamz/Documents/Code/Projects/CPPProjects/Mazel/tests/Test13/SDL2.framework/Versions/A/Headers
SDL_FRAMEWORK=-F/Users/muhdmirzamz/Documents/Code/Projects/CPPProjects/Mazel/tests/Test13 -framework SDL2

CFLAGS=-c -Wall -std=c++11 $(SDL_INCLUDE)
LFLAGS=-Wall $(SDL_FRAMEWORK) -o

VPATH=Test13

Game: main.o GameManager.o GameState.o MainMenu.o
	$(CXX) $(LFLAGS) $@ $^
	git branch
	git remote -v
	git add --all Test13
	git add Test13.xcodeproj
	git add makefile
	git commit -m 'Sticking with boilerplate code for now'
	git push mazel master

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
