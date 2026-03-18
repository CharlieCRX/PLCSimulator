.PHONY: all test clean

all:
	cmake -S . -B build
	cmake --build build

test: all
	./build/tests

clean:
	rm -rf build
