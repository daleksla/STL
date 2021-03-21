# standard compile options for the c++ executable
STD = --std=c++17
LIB = -isystem /usr/include/c++/9/

# deposit directories
SOURCES = ./sources
EXES = ./exes

# default super-target
all: 
	g++ $(LIB) $(STD) $(SOURCES)/stackTest.cpp -o $(EXES)/stackTest
	g++ $(LIB) $(STD) $(SOURCES)/queueTest.cpp -o $(EXES)/queueTest
	g++ $(LIB) $(STD) $(SOURCES)/linkedlistTest.cpp -o $(EXES)/linkedlistTest
	g++ $(LIB) $(STD) $(SOURCES)/stringTest.cpp -o $(EXES)/stringTest
	g++ $(LIB) $(STD) $(SOURCES)/basepointerTest.cpp -o $(EXES)/basepointerTest
