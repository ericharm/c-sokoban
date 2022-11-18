all: run

run: compile #link
	./build/main

# link: compile
# 	cmake --build ./build

compile:
	mkdir -p build && cc main.c -o build/main -lcurses

clean:
	rm -rf ./build

