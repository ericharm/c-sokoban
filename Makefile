all: run

run: compile
	./build/main

test: compile-tests
	./build/test

# link: compile
# 	cmake --build ./build

compile:
	mkdir -p build && cc main.c -o build/main -lcurses

compile-tests:
	mkdir -p build && cc test.c -g -o build/test -lcurses

clean:
	rm -rf ./build

