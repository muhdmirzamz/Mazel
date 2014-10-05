CXX=g++ 

#SDL stuff
SDL_INCLUDE=-I./SDL2.framework/Versions/A/Headers
SDL_FRAMEWORK=-F./ -framework SDL2

#global include for ease of compiling and linking
GLOBAL_INCLUDE=-I./Mazel

#use c++11 
CFLAGS=-c -Wall -std=c++11 $(SDL_INCLUDE) $(GLOBAL_INCLUDE)
LFLAGS=-Wall $(SDL_FRAMEWORK) -o

OBJECT_FILES = main.o GameManager.o GameState.o Background.o Ball.o Obstacle.o Gui.o Enemy.o IntroScene.o GameOverScene.o MainMenu.o InstructionsPage.o BasicLevel.o NextLevelPage.o GameEndScene.o

#look for files in Mazel folder
VPATH=Mazel

MazelGame.exe: $(OBJECT_FILES)
	@echo "Linking files"
	@$(CXX) $(LFLAGS) $@ $^
	@echo "Done"
	@./MazelGame 

GameEndScene.o: GameEndScene.cpp
	@$(CXX) $(CFLAGS) $^

NextLevelPage.o: NextLevelPage.cpp
	@$(CXX) $(CFLAGS) $^

BasicLevel.o: BasicLevel.cpp
	@$(CXX) $(CFLAGS) $^

InstructionsPage.o: InstructionsPage.cpp
	@$(CXX) $(CFLAGS) $^

MainMenu.o: MainMenu.cpp
	@echo "Compiling game state classes"
	@$(CXX) $(CFLAGS) $^

GameOverScene.o: GameOverScene.cpp
	@$(CXX) $(CFLAGS) $^

IntroScene.o: IntroScene.cpp
	@echo "Compiling game scene classes"
	@$(CXX) $(CFLAGS) $^

Enemy.o: Enemy.cpp
	@$(CXX) $(CFLAGS) $^

Gui.o: Gui.cpp
	@$(CXX) $(CFLAGS) $^

Obstacle.o: Obstacle.cpp
	@$(CXX) $(CFLAGS) $^

Ball.o: Ball.cpp
	@$(CXX) $(CFLAGS) $^

Background.o: Background.cpp
	@echo "Compiling game elements classes"
	@$(CXX) $(CFLAGS) $^

GameState.o: GameState.cpp
	@$(CXX) $(CFLAGS) $^

GameManager.o: GameManager.cpp
	@echo "Compiling game base classes"
	@$(CXX) $(CFLAGS) $^

main.o: main.cpp
	@echo "Compiling main file..."
	@$(CXX) $(CFLAGS) $^

clean:
	rm -rf *.o MazelGame.exe
