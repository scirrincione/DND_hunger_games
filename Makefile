CXX=g++
CXXFLAGS = -std=c++11 -g

test: main.cc startLoc.h ITrap.h IObject.h IMap.h ICreature.h
	$(CXX) $(CXXFLAGS) -o test main.cc basicTrap.cc healthBar.cc startLoc.h ITrap.h IObject.h IMap.h ICreature.h

run: main.o basicTrap.o healthBar.o SamePlayer.o DifferentPlayer.o startLoc.o
	$(CXX) $(CXXFLAGS) main.o SamePlayer.o DifferentPlayer.o basicTrap.o healthBar.o startLoc.o -o run

main.o: main.cc
	$(CXX) $(CXXFLAGS) -c main.cc -o main.o

basicTrap.o: basicTrap.cc ITrap.h IObject.h
	$(CXX) $(CXXFLAGS) -c basicTrap.cc -o basicTrap.o

healthBar.o: healthBar.cc
	$(CXX) $(CXXFLAGS) -c healthBar.cc -o healthBar.o

SamePlayer.o: SamePlayer.cc SamePlayer.h ICreature.h IObject.h 
	$(CXX) $(CXXFLAGS) -c SamePlayer.cc -o SamePlayer.o

DifferentPlayer.o: DifferentPlayer.cc DifferentPlayer.h ICreature.h IObject.h
	$(CXX) $(CXXFLAGS) -c DifferentPlayer.cc -o DifferentPlayer.o

startLoc.o: startLoc.cc startLoc.h IMap.h ICreature.h ITrap.h IObject.h
	$(CXX) $(CXXFLAGS) -c startLoc.cc -o startLoc.o

clean:
	rm -f *.o run