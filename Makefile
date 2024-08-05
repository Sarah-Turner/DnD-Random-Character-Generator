CC = g++	# use g++ for compiling c++ code
DEPS = $(SRCS:.cpp=.d)

output: main.o Character.o RandomCharacterGenerator.o dice.o
	g++ -g -std=c++20 main.o Character.o RandomCharacterGenerator.o dice.o -o output

main.o: main.cpp
	g++ -g -std=c++20 -c main.cpp

Character.o: Character.cpp Character.h
	g++ -g -std=c++20 -c Character.cpp

RandomCharacterGenerator.o: RandomCharacterGenerator.cpp RandomCharacterGenerator.h
	g++ -g -std=c++20 -c RandomCharacterGenerator.cpp

dice.o: dice.cpp dice.h
	g++ -g -std=c++20 -c dice.cpp

clean:
	rm *.o output