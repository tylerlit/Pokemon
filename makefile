CXX = g++
CXXFLAGS = -Wall

proj2: proj2.o Pokemon.o MyPokemon.o
	$(CXX) $(CXXFLAGS) proj2.o Pokemon.o MyPokemon.o -o proj2

proj2.o: proj2.cpp proj2.h
	$(CXX) $(CXXFLAGS) -c proj2.cpp

Pokemon.o: Pokemon.cpp Pokemon.h
	$(CXX) $(CXXFLAGS) -c Pokemon.cpp

MyPokemon.o: MyPokemon.cpp MyPokemon.h
	$(CXX) $(CXXFLAGS) -c MyPokemon.cpp


clean:
	rm *.o
	rm *~

run:
	./proj2