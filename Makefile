# @NOTE: NEED TO USE TABS, NOT SPACES

build:
	g++ -w -std=c++17 \
	./src/*.cpp \
	-o game \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2_mixer \
	-lSDL2_ttf;

clean:
	rm ./game;

run:
	./game;
