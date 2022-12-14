
all: run

run: link
	./build/sokoban

link: compile
	cmake --build ./build

compile:
	cmake -S . -B ./build

test: compile-tests
	./build/test

compile-tests:
	mkdir -p build && cc test.c -g -o build/test -lcurses

clean:
	rm -rf ./build

