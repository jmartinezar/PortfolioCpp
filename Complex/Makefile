cpp_flags = -g -Wall -fsanitize=address,leak,undefined -O3

all: main
	./main

main: main.o complex.o
	g++ $(cpp_flags) $^ -o $@

%.o: %.cpp complex.hpp
	g++ $(cpp_flags) -c $<

clean:
	rm *~ main *.o
