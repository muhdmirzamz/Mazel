CXX=g++

SDL_INCLUDE=-I/Users/muhdmirzamz/Documents/Code/Projects/CPPProjects/Mazel/SDL2.framework/Versions/A/Headers
SDL_FRAMEWORK=-F/Users/muhdmirzamz/Documents/Code/Projects/CPPProjects/Mazel -framework SDL2

GLOBAL_INCLUDE=-I/Users/muhdmirzamz/Documents/Code/Projects/CPPProjects/Mazel/Mazel

#use c++11 
CFLAGS=-c -Wall -std=c++11 $(SDL_INCLUDE) $(GLOBAL_INCLUDE)
LFLAGS=-Wall $(SDL_FRAMEWORK) -o

#look for files in Mazel folder
VPATH=Mazel

MazelGame: main.o GameManager.o GameState.o MainMenu.o Level1.o
	@echo "Linking object files"
	@$(CXX) $(LFLAGS) $@ $^
	@echo "Done."

Level1.o: Level1.cpp
	@echo "Compiling Level1.cpp"
	@$(CXX) $(CFLAGS) $^

MainMenu.o: MainMenu.cpp
	@echo "Compiling MainMenu.cpp"
	@$(CXX) $(CFLAGS) $^

GameState.o: GameState.cpp
	@echo "Compiling GameState.cpp"
	@$(CXX) $(CFLAGS) $^

GameManager.o: GameManager.cpp
	@echo "Compiling GameManager.cpp"
	@$(CXX) $(CFLAGS) $^

main.o: main.cpp
	@echo "Compiling main.cpp"
	@$(CXX) $(CFLAGS) $^

clean:
	rm -rf *.o MazelGame
