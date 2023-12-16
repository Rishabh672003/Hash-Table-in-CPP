project = hash-table
mode = Debug

all: compile

prepare:
	mkdir build

builddeps:
	cmake ./CMakeLists.txt -B build -DCMAKE_BUILD_TYPE=$(mode)

compile:
	cmake --build build --config $(mode)

run:
	./build/$(project)

clean:
	rm -rf build/ 

cleanbin:
	rm -rf build/$(project)
