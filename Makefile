EXE=Snake.exe

all: build run

build: 
	g++ -I include -L lib src/*.cpp -o out/$(EXE) -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
run:
	out/$(EXE)
