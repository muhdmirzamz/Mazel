CXX=g++

SDL_INCLUDE=-I/Users/muhdmirzamz/Documents/Code/Projects/CPPProjects/Mazel/Mazel/SDL2.framework/Versions/A/Headers
SDL_FRAMEWORK=-F/Users/muhdmirzamz/Documents/Code/Projects/CPPProjects/Mazel/Mazel -framework SDL2

#use c++11 
CFLAGS=-c -Wall -std=c++11 $(SDL_INCLUDE)
LFLAGS=-Wall $(SDL_FRAMEWORK) -o

#look for files in Mazel folder
VPATH=Mazel

MazelGame: main.o GameManager.o GameState.o MainMenu.o
	@echo "Linking object files"
	@$(CXX) $(LFLAGS) $@ $^
	@echo "Done."

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
