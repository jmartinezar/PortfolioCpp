# Variables

comp_flags = -std=c++17 -g -Wall -fsanitize=leak,undefined,address

# Recipies

exe: main
	./$<

%.o: %.cpp
	g++ $(comp_flags) -c $<

%.o: %.cpp %.h
	g++ $(comp_flags) -c $<

main: main.o node.o tree.o include.o
	g++ $(comp_flags) $^ -o $@

clean:
	rm *~ *.o main
